# wiasSendEndOfPage function

## Description

The **wiasSendEndOfPage** function calls the client callback routine during a data transfer, sending the current total page count.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `lPageCount`

Specifies the total page count.

### `pmdtc` [in, out]

Pointer to a [MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context) structure.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## See also

[MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context)