# IContactProperties::GetLabels

## Description

Retrieves the labels for a specified array element name.

## Parameters

### `pszArrayElementName` [in]

Type: **LPCWSTR**

Specifies the array element name.

### `dwFlags` [in]

Type: **DWORD**

Must be CGD_DEFAULT.

### `pszLabels` [in, out]

Type: **LPWSTR**

Specifies user-allocated buffer to store the labels.

### `cchLabels` [in]

Type: **DWORD**

Specifies allocated buffer size in characters.

### `pdwcchLabelsRequired` [in, out]

Type: **DWORD***

On failure, contains the required size for *pszLabels*.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Retrieval successful. |
| **ERROR_PATH_NOT_FOUND** | No data found for this property name. |
| **ERROR_INVALID_DATATYPE** | Unable to get value for this property due to schema. |
| **ERROR_INSUFFICIENT_BUFFER** | *pszLabels* was not large enough to store the value. The required buffer size is stored in **pdwcchLabelsRequired*. |

## Remarks

The user-allocated buffer in *pszLabels* receives a concatenated list of null-terminated strings, followed by an empty string. In other words, the last 4 bytes will be zero. For example, L"str1\0str2\0\0". NOTE: Succeeds only for multi-value properties. Also, may return labels in a different order than they were set.