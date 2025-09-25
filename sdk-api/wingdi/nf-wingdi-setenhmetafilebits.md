# SetEnhMetaFileBits function

## Description

The **SetEnhMetaFileBits** function creates a memory-based enhanced-format metafile from the specified data.

## Parameters

### `nSize` [in]

Specifies the size, in bytes, of the data provided.

### `pb` [in]

Pointer to a buffer that contains enhanced-metafile data. (It is assumed that the data in the buffer was obtained by calling the [GetEnhMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilebits) function.)

## Return value

If the function succeeds, the return value is a handle to a memory-based enhanced metafile.

If the function fails, the return value is **NULL**.

## Remarks

When the application no longer needs the enhanced-metafile handle, it should delete the handle by calling the [DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile) function.

The **SetEnhMetaFileBits** function does not accept metafile data in the Windows format. To import Windows-format metafiles, use the [SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits) function.

## See also

[DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile)

[GetEnhMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilebits)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits)