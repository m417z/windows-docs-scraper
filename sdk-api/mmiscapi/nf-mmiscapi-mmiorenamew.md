# mmioRenameW function

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

## Remarks

> [!NOTE]
> The mmiscapi.h header defines mmioRename as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).