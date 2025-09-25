# wiasWritePageBufToStream function

## Description

The **wiasWritePageBufToStream** function writes the contents of a temporary page buffer to the **IStream** interface provided by the application.

## Parameters

### `pmdtc` [in]

Pointer to a [MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context) structure.

### `pstream` [in]

Pointer to the **IStream** data stream provided by the application. The **IStream** interface is described in the Microsoft Windows SDK documentation.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_*XXX* errors (described in the Windows SDK documentation).

## Remarks

The function writes data from a temporary page buffer that is allocated by a minidriver to the image data stream provided by the calling application. Minidrivers typically call this function after acquiring a page of data for which the minidriver allocated a temporary buffer.

This function is similar to [wiasWriteBufToFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritebuftofile) and [wiasWritePageBufToFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepagebuftofile). The **wiasWriteBufToFile** function can be used to write a buffer of image data to any type of image file. The **wiasWritePageBufToFile** function can be used to write a page of image data to a multipage TIFF file with all appropriate tags and image file directory (IFD) entries. If the driver intends to write this multipage TIFF file data to a stream, it would call **wiasWritePageBufToStream**.

## See also

[MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context)

[wiasWriteBufToFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritebuftofile)

[wiasWritePageBufToFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepagebuftofile)