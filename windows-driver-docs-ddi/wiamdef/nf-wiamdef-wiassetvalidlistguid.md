## Description

The **wiasSetValidListGuid** function sets valid values for a WIA_PROP_LIST property of type VT_CLSID.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `propid`

Specifies the identifier of the property to be updated.

### `ulCount`

Specifies the number of items in the *pgValues* array.

### `guidNom`

Specifies the property's nominal value.

### `pguidValues` [in]

Pointer to the first element of an array of valid property values.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## See also

[wiasSetValidFlag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidflag)

[wiasSetValidListFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidlistfloat)

[wiasSetValidListLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidlistlong)

[wiasSetValidListStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidliststr)

[wiasSetValidRangeFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidrangefloat)

[wiasSetValidRangeLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidrangelong)