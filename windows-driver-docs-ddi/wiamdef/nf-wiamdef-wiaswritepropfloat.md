# wiasWritePropFloat function

## Description

The **wiasWritePropFloat** function writes a single floating-point property value to a WIA item.

## Parameters

### `pWiasContext` [in]

A Pointer to a WIA item context.

### `propid`

Specifies the property identifier.

### `fVal`

Specifies the floating-point property value to write to the item.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## See also

[wiasReadPropFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropfloat)

[wiasWritePropBin](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepropbin)

[wiasWritePropGuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepropguid)

[wiasWritePropLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswriteproplong)

[wiasWritePropStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepropstr)