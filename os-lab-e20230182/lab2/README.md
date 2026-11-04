# OS Lab 2 - Linux Navigation & File Management

Student ID: e20230182

## My values

- Files: `cash flow.txt`, `audit notes.txt`
- Departments: owner Audit, reader Marketing, third HR

## What I did

- Built the TechCorp folders with `mkdir -p`.
- Moved both reports from `incoming/` to `reports/`, one with a relative path and one with absolute paths.
- Copied both reports to `TechCorp/Audit/`, and the first report to `archive/first-original.txt`.
- Read the first report from `TechCorp/Marketing/` with a relative path and an absolute path.
- Compared the copies with `cmp` to prove they are identical.

## Path error and fix

- Error: `cat: 'reports/cash flow.txt': No such file or directory`
- Cause: a relative path starts from the current folder, and `Marketing` has no `reports` folder.
- Fix: `../../reports/cash flow.txt`

## Path choice

Relative paths are shorter when I know which folder I am in. Absolute paths work from any folder.

## Plus and Challenge

- Plus: I needed five `..` in total, two in the source path and three in the destination path.
- Challenge: quotes around `*.txt` stop the shell from expanding `*`, so `cp` looks for a file with that exact name.
- Challenge: `*` does not match names that start with a dot, so `.hidden.txt` is not copied.
