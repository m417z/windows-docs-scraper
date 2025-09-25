# wiasSetValidFlag function

## Description

The **wiasSetValidFlag** function sets the valid values for a WIA_PROP_FLAG property.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `propid`

Specifies the identifier of the property to be updated.

### `ulNom`

Specifies the property's nominal value.

### `ulValidBits`

Specifies the valid bits that can be used for the WIA_PROP_FLAG property.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## See also

[wiasSetValidListFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidlistfloat)

[wiasSetValidListGuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidlistguid)

[wiasSetValidListLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidlistlong)

[wiasSetValidListStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidliststr)

[wiasSetValidRangeFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidrangefloat)

[wiasSetValidRangeLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidrangelong)