# Lab 3 — Wildcards, Hard Links and Symbolic Links: individual report

Copy this template to `lab3/README.md` in your own course repository. Follow [the instructions](lab3-instruction.md). Your prediction, debrief and checkpoint answers are already saved by `oslab`; do not copy them here. The marks come from those records and your evidence files; this report is your own record of the lab.

- Student name/ID:PHAI JINGPO e20230182
- Ubuntu username: gic-phai-jingpo
- My values (`oslab values lab3`): name = market, tag = final , v1 = 789, v2 = 816
- Files: `evidence/wildcards.txt`, `evidence/links.txt`, `evidence/replacement.txt`, `evidence/checkpoint.txt`

## What I Saw

| State | What `cat` printed for the hard link | What `cat` printed for the symbolic link | What `readlink` printed |
|---|---|---|---|
| Before the rename | `version 789` | `version 789` | `market.txt` |
| After the rename, before the repair | `version 789` | `No such file or directory` (dangling link) | `market.txt` |
| After a new file took the old name | `version 789` | `version 816` | `market.txt` |
| After my repair | `version 789` | `version 789` | `market-final.txt` |

**My repair (the two commands I wrote):**

```bash
rm -- market-soft.txt
ln -s -- market-final.txt market-soft.txt
```

## Explanation

The original report `market.txt` and its hard link `market-hard.txt` share the same inode, **[enter original inode from `evidence/replacement.txt`]**, so renaming the original to `market-final.txt` did not change what the hard link reads. The symbolic link `market-soft.txt` has its own inode, **[enter symbolic-link inode]**, and stored the path `market.txt`, not the inode of the original report. After a new `market.txt` was created with `version 816`, the symbolic link followed that filename and read the new file (inode **[enter new file inode]**), while the hard link still read `version 789`. I repaired the symbolic link using the relative target `market-final.txt` so it reached the original report again.

## What My Tests Do Not Prove

The `cat` output proves what content each link can read at the time of testing, but matching content alone does not prove that two filenames refer to the same file. The `ls -li` output and matching inode numbers are needed to show that `market-hard.txt` and `market-final.txt` refer to the same inode.

## Plus / Challenge (only if you did them)

Not included; these optional exercises have not been confirmed as completed.

## AI Note (optional)

An AI tool suggested recreating the symbolic link using a relative target after the rename. I tested that suggestion with `readlink market-soft.txt`, `cat market-soft.txt`, and `oslab check lab3`; the Core checker reported all five Core milestones as `PASS`.
