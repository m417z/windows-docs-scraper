# wiasReadPropFloat function

## Description

The **wiasReadPropFloat** function retrieves a floating-point property value from a WIA item.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `propid`

Specifies the property identifier.

### `pfVal` [out]

Pointer to a memory location that receives the floating-point value of the property.

### `pfValOld` [out, optional]

Pointer to a memory location that receives the former floating-point value of the property. If this information is not needed, set this parameter to **NULL**.

### `bMustExist`

Indicates whether the property must exist. If set to **TRUE**, the property must exist; if set to **FALSE**, it does not have to exist.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## See also

[wiasReadPropBin](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropbin)

[wiasReadPropGuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropguid)

[wiasReadPropLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadproplong)

[wiasReadPropStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropstr)

[wiasWritePropFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepropfloat)