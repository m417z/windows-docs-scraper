# ISettingsNamespace::GetAttribute

## Description

Gets the value of an attribute of the namespace.

## Parameters

### `Name` [in]

The name of the attribute.

### `Value` [out]

The value of the attribute.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **WCM_E_ATTRIBUTENOTFOUND** | Indicates that the requested attribute is not specified for the item. |
| **E_OUTOFMEMORY** | Indicates that there are insufficient resources to return information to the user. |

## See also

[ISettingsNamespace](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsnamespace)