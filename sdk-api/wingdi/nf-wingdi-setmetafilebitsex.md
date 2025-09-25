# SetMetaFileBitsEx function

## Description

The **SetMetaFileBitsEx** function creates a memory-based Windows-format metafile from the supplied data.

**Note** This function is provided only for compatibility with Windows-format metafiles. Enhanced-format metafiles provide superior functionality and are recommended for new applications. The corresponding function for an enhanced-format metafile is [SetEnhMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setenhmetafilebits).

## Parameters

### `cbBuffer` [in]

Specifies the size, in bytes, of the Windows-format metafile.

### `lpData` [in]

Pointer to a buffer that contains the Windows-format metafile. (It is assumed that the data was obtained by using the [GetMetaFileBitsEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getmetafilebitsex) function.)

## Return value

If the function succeeds, the return value is a handle to a memory-based Windows-format metafile.

If the function fails, the return value is **NULL**.

## Remarks

To convert a Windows-format metafile into an enhanced-format metafile, use the [SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits) function.

When the application no longer needs the metafile handle returned by **SetMetaFileBitsEx**, it should delete it by calling the [DeleteMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletemetafile) function.

## See also

[DeleteMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletemetafile)

[GetMetaFileBitsEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getmetafilebitsex)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SetEnhMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setenhmetafilebits)

[SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits)