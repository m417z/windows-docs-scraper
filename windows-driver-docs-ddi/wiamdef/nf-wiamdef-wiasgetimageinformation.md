# wiasGetImageInformation function

## Description

The **wiasGetImageInformation** function retrieves transfer context information from an item.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `lFlags`

Specifies operational flags. Currently, only the following flag is defined:

| Flag | Meaning |
| --- | --- |
| WIAS_INIT_CONTEXT | Initialize the MINIDRV_TRANSFER_CONTEXT structure. |

### `pmdtc` [in, out]

Pointer to a [MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context) structure. Upon return, this structure contains the requested image item information.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## Remarks

This function uses a [MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context) structure to calculate item image and item header sizes. In addition, it can optionally fill in an image header if the image format requires a data header. The header will be copied to the buffer if the **pTransferBuffer** member of the MINIDRV_TRANSFER_CONTEXT structure is not **NULL**. When using image formats (such as JPEG) that do not have a header, the header size in the **lHeaderSize** member of the MINIDRV_TRANSFER_CONTEXT structure is reported as zero.

For image formats where the actual final size of the image is not known until after data acquisition, as with multipage TIFF and compressed formats, the **lItemSize** member of the [MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context) structure is reported as zero. The **lImageSize** member is reported as the size, in bytes, of the uncompressed image in a single page.

If WIAS_INIT_CONTEXT is specified in the *lFlags* parameter, the MINIDRV_TRANSFER_CONTEXT structure pointed to by the *pmdtc* parameter is filled in with information derived from the item's image properties. This flag should be used when a minidriver has allocated a new context.

## See also

[MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context)