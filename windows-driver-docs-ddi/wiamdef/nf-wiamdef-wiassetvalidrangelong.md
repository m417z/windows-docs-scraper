# wiasSetValidRangeLong function

## Description

The **wiasSetValidRangeLong** function specifies the range of valid values for a WIA_PROP_RANGE property of type VT_I4.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `propid`

Specifies the identifier of the property to be updated.

### `lMin`

Specifies the minimum value of the valid range.

### `lNom`

Specifies the property's nominal value.

### `lMax`

Specifies the maximum value of the valid range.

### `lStep`

Specifies the increment between each valid value in the range.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## See also

[wiasSetValidFlag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidflag)

[wiasSetValidListFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidlistfloat)

[wiasSetValidListGuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidlistguid)

[wiasSetValidListLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidlistlong)

[wiasSetValidListStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidliststr)

[wiasSetValidRangeFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetvalidrangefloat)