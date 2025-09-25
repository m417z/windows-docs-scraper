# IContactProperties::GetString

## Description

Retrieves the string value at a specified property into a caller-allocated buffer.

## Parameters

### `pszPropertyName` [in]

Type: **LPCWSTR**

Specifies the property to retrieve.

### `dwFlags` [in]

Type: **DWORD**

Must be CGD_DEFAULT.

### `pszValue` [in, out]

Type: **LPWSTR**

Specifies user-allocated buffer to store the property.

### `cchValue` [in]

Type: **DWORD***

Specifies allocated buffer size in characters.

### `pdwcchPropertyValueRequired` [in, out]

Type: **DWORD***

On failure, contains the required size for *pszValue*.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | *pszValue* contains the null-terminated value. |
| **S_FALSE** | No data for this value. Either the property has been present in the past but its value has been removed or the property is a container of other properties (toplevel/secondlevel[3]). The buffer at *pszValue* has been zeroed. |
| **ERROR_PATH_NOT_FOUND** | No data found for this property name. |
| **ERROR_INSUFFICIENT_BUFFER** | *pszValue* was not large enough to store the value. The required buffer size is stored in **pdwcchPropertyValueRequired*. |

## Remarks

To retrieve a single level property, set *pszPropertyName* to the property name.

To retrieve a value from a multi-value (hierarchical) property, include the desired index as part of *pszPropertyName* in the form: toplevel/secondlevel[1]/thirdlevel. NOTE: the first element of a set is index 1, so index [0] is invalid. The following example retrieves the Title of the fourth Name property of a contact.

`L"NameCollection/Name[4]/Title"`