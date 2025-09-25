# mmioRename function

## Description

The **mmioRename** function renames the specified file.

## Parameters

### `pszFileName`

Pointer to a string containing the file name of the file to rename.

### `pszNewFileName`

Pointer to a string containing the new file name.

### `pmmioinfo`

Pointer to an [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure containing extra parameters used by **mmioRename**. If this parameter is not **NULL**, all unused members of the **MMIOINFO** structure it references must be set to zero, including the reserved members.

### `fdwRename`

Flags for the rename operation. This parameter should be set to zero.

## Return value

Returns zero if the file was renamed. Otherwise, returns an error code returned from **mmioRename** or from the I/O procedure.