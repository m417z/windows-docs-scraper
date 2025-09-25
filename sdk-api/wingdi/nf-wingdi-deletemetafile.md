# DeleteMetaFile function

## Description

The **DeleteMetaFile** function deletes a Windows-format metafile or Windows-format metafile handle.

**Note** This function is provided only for compatibility with Windows-format metafiles. Enhanced-format metafiles provide superior functionality and are recommended for new applications. The corresponding function for an enhanced-format metafile is [DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile).

## Parameters

### `hmf` [in]

A handle to a Windows-format metafile.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

If the metafile identified by the *hmf* parameter is stored in memory (rather than on a disk), its content is lost when it is deleted by using the **DeleteMetaFile** function.

## See also

[CopyMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-copymetafilea)

[CreateMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createmetafilea)

[DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)