# ISharedPropertyGroup::get_Property

## Description

Retrieves a reference to an existing shared property with the specified name.

## Parameters

### `Name` [in]

The name that was used to create the shared property that is retrieved.

### `ppProperty` [out]

A reference to the shared property specified in the *Name* parameter, or **NULL** if the property does not exist.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The shared property exists, and a reference to it is returned in the *ppProperty* parameter. |
| **E_INVALIDARG** | The shared property with the name specified in the *Name* parameter does not exist. |

## See also

[ISharedProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isharedproperty)

[ISharedPropertyGroup](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isharedpropertygroup)