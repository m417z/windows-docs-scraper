# PlayMetaFile function

## Description

The **PlayMetaFile** function displays the picture stored in the given Windows-format metafile on the specified device.

**Note** This function is provided only for compatibility with Windows-format metafiles. Enhanced-format metafiles provide superior functionality and are recommended for new applications. The corresponding function for an enhanced-format metafile is [PlayEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafile).

## Parameters

### `hdc` [in]

Handle to a device context.

### `hmf` [in]

Handle to a Windows-format metafile.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

To convert a Windows-format metafile into an enhanced format metafile, use the [SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits) function.

A Windows-format metafile can be played multiple times.

A Windows-format metafile can be embedded in a second Windows-format metafile by calling the **PlayMetaFile** function and playing the source metafile into the device context for the target metafile.

Any object created but not deleted in the Windows-format metafile is deleted by this function.

To stop this function, an application can call the [CancelDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-canceldc) function from another thread to terminate the operation. In this case, the function returns **FALSE**.

## See also

[CancelDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-canceldc)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits)