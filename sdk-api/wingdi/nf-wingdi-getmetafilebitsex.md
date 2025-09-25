# GetMetaFileBitsEx function

## Description

The **GetMetaFileBitsEx** function retrieves the contents of a Windows-format metafile and copies them into the specified buffer.

**Note** This function is provided only for compatibility with Windows-format metafiles. Enhanced-format metafiles provide superior functionality and are recommended for new applications. The corresponding function for an enhanced-format metafile is [GetEnhMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilebits).

## Parameters

### `hMF` [in]

A handle to a Windows-format metafile.

### `cbBuffer` [in]

The size, in bytes, of the buffer to receive the data.

### `lpData` [out]

A pointer to a buffer that receives the metafile data. The buffer must be sufficiently large to contain the data. If *lpvData* is **NULL**, the function returns the number of bytes required to hold the data.

## Return value

If the function succeeds and the buffer pointer is **NULL**, the return value is the number of bytes required for the buffer; if the function succeeds and the buffer pointer is a valid pointer, the return value is the number of bytes copied.

If the function fails, the return value is zero.

## Remarks

After the Windows-metafile bits are retrieved, they can be used to create a memory-based metafile by calling the [SetMetaFileBitsEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmetafilebitsex) function.

The **GetMetaFileBitsEx** function does not invalidate the metafile handle. An application must delete this handle by calling the [DeleteMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletemetafile) function.

To convert a Windows-format metafile into an enhanced-format metafile, use the [SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits) function.

## See also

[DeleteMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletemetafile)

[GetEnhMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilebits)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SetMetaFileBitsEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmetafilebitsex)

[SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits)