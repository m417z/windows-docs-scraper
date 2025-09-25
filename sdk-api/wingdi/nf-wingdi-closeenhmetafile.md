# CloseEnhMetaFile function

## Description

The **CloseEnhMetaFile** function closes an enhanced-metafile device context and returns a handle that identifies an enhanced-format metafile.

## Parameters

### `hdc` [in]

Handle to an enhanced-metafile device context.

## Return value

If the function succeeds, the return value is a handle to an enhanced metafile.

If the function fails, the return value is **NULL**.

## Remarks

An application can use the enhanced-metafile handle returned by the **CloseEnhMetaFile** function to perform the following tasks:

* Display a picture stored in an enhanced metafile
* Create copies of the enhanced metafile
* Enumerate, edit, or copy individual records in the enhanced metafile
* Retrieve an optional description of the metafile contents from the enhanced-metafile header
* Retrieve a copy of the enhanced-metafile header
* Retrieve a binary copy of the enhanced metafile
* Enumerate the colors in the optional palette
* Convert an enhanced-format metafile into a Windows-format metafile

When the application no longer needs the enhanced metafile handle, it should release the handle by calling the [DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile) function.

## See also

[CopyEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-copyenhmetafilea)

[CreateEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createenhmetafilea)

[DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile)

[EnumEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumenhmetafile)

[GetEnhMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilebits)

[GetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getwinmetafilebits)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PlayEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafile)