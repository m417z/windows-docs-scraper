# IPropertyStore::GetValue

## Description

This method retrieves the data for a specific property.

## Parameters

### `key`

TBD

### `pv`

After the `IPropertyStore::GetValue` method returns successfully, this parameter points to a [PROPVARIANT](https://learn.microsoft.com/previous-versions/aa912007(v=msdn.10))  structure that contains data about the property.

### `Key`

A reference to the PROPERTYKEY structure that is retrieved through [IPropertyStore::GetAt](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getat). The PROPERTYKEY structure also contains a globally unique identifier (GUID) for the property.

## Return value

Returns S_OK or INPLACE_S_TRUNCATED if successful, or an error value otherwise.

INPLACE_S_TRUNCATED is returned to indicate that the returned PROPVARIANT was converted into a more canonical form. For example, this would be done to trim leading or trailing spaces from a string value. You must use the SUCCEEDED macro to check the return value, which treats INPLACE_S_TRUNCATED as a success code. The SUCCEEDED macro is defined in the Winerror.h file.

## Remarks

If the PROPERTYKEY referenced in key is not present in the property store, this method returns S_OK and the [vt](https://learn.microsoft.com/previous-versions/aa912007(v=msdn.10))  member of the structure that is pointed to by pv is set to VT_EMPTY.

## See also

[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)

[IPropertyStore::GetAt](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getat)