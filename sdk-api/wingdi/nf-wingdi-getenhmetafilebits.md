# GetEnhMetaFileBits function

## Description

The **GetEnhMetaFileBits** function retrieves the contents of the specified enhanced-format metafile and copies them into a buffer.

## Parameters

### `hEMF` [in]

A handle to the enhanced metafile.

### `nSize` [in]

The size, in bytes, of the buffer to receive the data.

### `lpData` [out]

A pointer to a buffer that receives the metafile data. The buffer must be sufficiently large to contain the data. If *lpbBuffer* is **NULL**, the function returns the size necessary to hold the data.

## Return value

If the function succeeds and the buffer pointer is **NULL**, the return value is the size of the enhanced metafile, in bytes.

If the function succeeds and the buffer pointer is a valid pointer, the return value is the number of bytes copied to the buffer.

If the function fails, the return value is zero.

## Remarks

After the enhanced-metafile bits are retrieved, they can be used to create a memory-based metafile by calling the [SetEnhMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setenhmetafilebits) function.

The **GetEnhMetaFileBits** function does not invalidate the enhanced-metafile handle. The application must call the [DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile) function to delete the handle when it is no longer needed.

The metafile contents retrieved by this function are in the enhanced format. To retrieve the metafile contents in the Windows format, use the [GetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getwinmetafilebits) function.

## See also

[DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile)

[GetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getwinmetafilebits)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SetEnhMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setenhmetafilebits)