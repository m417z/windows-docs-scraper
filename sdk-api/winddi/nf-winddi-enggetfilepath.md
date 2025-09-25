# EngGetFilePath function

## Description

The **EngGetFilePath** function determines the file path associated with the specified font file.

## Parameters

### `h` [in]

Handle to the font file.

### `pDest` [out]

Pointer to a buffer that will contain the fully qualified path of the directory containing the font file. The buffer can contain at most MAX_PATH + 1 characters, including the terminating null character. The constant MAX_PATH is defined in *windef.h*.

## Return value

**EngGetFilePath** returns **TRUE** if it succeeds in obtaining the file path of the font file. Otherwise, **EngGetFilePath** returns **FALSE**.

## See also

[EngMapFontFileFD](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfontfilefd)