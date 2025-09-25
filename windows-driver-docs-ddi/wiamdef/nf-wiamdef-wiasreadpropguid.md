## Description

The **wiasReadPropGuid** function retrieves a GUID property value from a WIA item.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `propid`

Specifies the property identifier.

### `pguidVal` [out]

Pointer to a memory location that receives the GUID property value.

### `pguidValOld` [out, optional]

Pointer to a memory location that receives the previous value of the GUID property data. If this information is not needed, this parameter can be set to **NULL**.

### `bMustExist`

Indicates whether the property must exist. If set to **TRUE**, the property must exist; if set to **FALSE**, the property does not have to exist.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## See also

[wiasReadPropBin](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropbin)

[wiasReadPropFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropfloat)

[wiasReadPropLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadproplong)

[wiasReadPropStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropstr)

[wiasWritePropGuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepropguid)