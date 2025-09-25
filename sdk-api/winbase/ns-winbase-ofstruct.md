# OFSTRUCT structure

## Description

Contains information about a file that the
[OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile) function opened or attempted to open.

## Members

### `cBytes`

The size of the structure, in bytes.

### `fFixedDisk`

If this member is nonzero, the file is on a hard (fixed) disk. Otherwise, it is not.

### `nErrCode`

The MS-DOS error code if the
[OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile) function failed.

### `Reserved1`

Reserved; do not use.

### `Reserved2`

Reserved; do not use.

### `szPathName`

The path and file name of the file.

## See also

[OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile)