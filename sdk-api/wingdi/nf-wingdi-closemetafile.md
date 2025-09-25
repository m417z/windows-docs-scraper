# CloseMetaFile function

## Description

The **CloseMetaFile** function closes a metafile device context and returns a handle that identifies a Windows-format metafile.

**Note** This function is provided only for compatibility with Windows-format metafiles. Enhanced-format metafiles provide superior functionality and are recommended for new applications. The corresponding function for an enhanced-format metafile is [CloseEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-closeenhmetafile).

## Parameters

### `hdc` [in]

Handle to a metafile device context used to create a Windows-format metafile.

## Return value

If the function succeeds, the return value is a handle to a Windows-format metafile.

If the function fails, the return value is **NULL**.

## Remarks

To convert a Windows-format metafile into a new enhanced-format metafile, use the [SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits) function.

When an application no longer needs the Windows-format metafile handle, it should delete the handle by calling the [DeleteMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletemetafile) function.

## See also

[CloseEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-closeenhmetafile)

[CopyMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-copymetafilea)

[CreateMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createmetafilea)

[DeleteMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletemetafile)

[EnumMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enummetafile)

[GetMetaFileBitsEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getmetafilebitsex)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PlayMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playmetafile)

[SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits)