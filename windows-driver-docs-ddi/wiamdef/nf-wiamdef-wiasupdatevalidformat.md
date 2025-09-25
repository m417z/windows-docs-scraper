# wiasUpdateValidFormat function

## Description

The **wiasUpdateValidFormat** function updates the valid format of the property context for the current minidriver.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `pContext` [in]

Pointer to a [WIA_PROPERTY_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context) structure containing a property context.

### `pIMiniDrv` [in]

Pointer to the [IWiaMiniDrv Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv) of the current minidriver.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## See also

[WIA_PROPERTY_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context)