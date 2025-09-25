# wiasUpdateScanRect function

## Description

The **wiasUpdateScanRect** function updates the scanning area sizes of the scanning device.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `pContext` [in]

Pointer to a [WIA_PROPERTY_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context) structure containing the property context, created by a prior call to [wiasCreatePropContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatepropcontext).

### `lWidth`

Specifies the horizontal width of the scanning area of the scanning device, in units of thousandths of an inch. Normally, this is the horizontal bed size.

### `lHeight`

Specifies the vertical height of the scanning area of the scanning device, in units of thousandths of an inch. Normally, this is the vertical bed size.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## Remarks

This helper method is called to update the properties making up the scan rectangle. The appropriate changes are made to the properties that are dependent on those that make up the scan rectangle. For example, a change in horizontal resolution affects the horizontal extent. This function assumes that the valid values for the vertical and horizontal extents, and vertical and horizontal positions have not yet been updated.

## See also

[WIA_PROPERTY_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context)

[wiasCreatePropContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatepropcontext)