# FIND_BY_SID_DATA structure

## Description

Contains data for the
[FSCTL_FIND_FILES_BY_SID](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_find_files_by_sid) control
code.

## Members

### `Restart`

Indicates whether to restart the search. This member should be 1 on first call, so the search will start
from the root. For subsequent calls, this member should be zero so the search will resume at the point where it
stopped.

### `Sid`

A [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that specifies the desired creator
owner.

## See also

[FSCTL_FIND_FILES_BY_SID](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_find_files_by_sid)