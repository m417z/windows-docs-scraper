# wiasWriteBufToFile function

## Description

The **wiasWriteBufToFile** function writes from a specified buffer to an image file.

## Parameters

### `lFlags`

Specifies a set of operation flags. This parameter should be set to 0.

### `pmdtc` [in]

Pointer to a [MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context) structure.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## Remarks

A WIA minidriver uses this function to write a buffer to any type of image file. A driver that intends to write a page of purely image data to a multipage TIFF file, delegating the addition of the appropriate tags, image file directory (IFD) entries, and other nonimage data to the WIA service, should use [wiasWritePageBufToFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepagebuftofile).

## See also

[MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context)

[wiasWritePageBufToFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepagebuftofile)

[wiasWritePageBufToStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepagebuftostream)