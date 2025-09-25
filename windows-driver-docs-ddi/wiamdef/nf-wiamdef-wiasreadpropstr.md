# wiasReadPropStr function

## Description

The **wiasReadPropStr** function retrieves a string property value from a WIA item.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `propid`

Specifies the property identifier.

### `pbstr` [out]

Pointer to a memory location that receives the first byte of the property's string value.

### `pbstrOld` [out, optional]

Pointer to a memory location that receives the first byte of the property's previous value. If this information is not needed, set this parameter to **NULL**.

### `bMustExist`

Indicates whether the property must exist. If set to **TRUE**, the property must exist; if set to **FALSE**, the property does not have to exist.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## Remarks

When the minidriver has completed using the string it received from this function, it must deallocate the memory used for the string.

## See also

[wiasReadPropBin](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropbin)

[wiasReadPropFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropfloat)

[wiasReadPropGuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropguid)

[wiasReadPropLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadproplong)

[wiasWritePropStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepropstr)