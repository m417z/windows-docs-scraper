# ISettingsItem::GetKeyValue

## Description

Extracts key values for any list that already exists in the image, for example, DNS, http settings, and user account information.

## Parameters

### `Value` [out]

The value of the key for the list element. The type of the value returned is the actual type of the key. For example, the type is a string in the case of a dynamically keyed list. The value is unescaped appropriately to reverse the changes made by SMI for the purpose of storing it. The VARIANT type is overwritten with the correct type if the predefined VARIANT type is incorrect.

## Return value

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_OPERATION)** | The item is not a list element. |
| **E_OUTOFMEMORY** | There are insufficient resources to return information to the user. |
| **E_INVALIDARG** | The value is null. |

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)