# IContactProperties::SetString

## Description

Sets the string value of a specified property to that of a specified null-terminated string.

## Parameters

### `pszPropertyName` [in]

Type: **LPCWSTR**

Specifies the property to set.

### `dwFlags` [in]

Type: **DWORD**

CGD_DEFAULT can be used to create or overwrite value at *pszPropertyName*.

### `pszValue` [in]

Type: **LPWSTR**

Specifies null-terminated string to store.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Value is set at this property. |
| **ERROR_PATH_NOT_FOUND** | Property name invalid for set. |
| **ERROR_INVALID_DATATYPE** | Unable to set value for this property due to schema. |

## Remarks

To set a single-level property, set *pszPropertyName* to the property name.

To set a property from a multi-value property, set *pszPropertyName* to the form:
toplevel/secondlevel[4]/thirdlevel.