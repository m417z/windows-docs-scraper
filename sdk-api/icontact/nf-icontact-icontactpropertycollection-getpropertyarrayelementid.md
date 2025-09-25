# IContactPropertyCollection::GetPropertyArrayElementID

## Description

Retrieves the unique ID for a given element in a property array.

## Parameters

### `pszArrayElementID` [in, out]

Type: **LPWSTR**

On success, contains the unique ID for the element.

### `cchArrayElementID` [in]

Type: **DWORD**

Specifies caller-allocated buffer size in characters.

### `pdwcchArrayElementIDRequired` [in, out]

Type: **DWORD***

On failure, contains the required size for *pszArrayElementID*.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Query is successful. |
| **S_FALSE** | Array node does not have a unique array element ID. |
| **ERROR_INSUFFICIENT_BUFFER** | *pszArrayElementID* was not large enough to store the value. The required buffer size is stored in **pdwcchArrayElementIDRequired*. |

## Remarks

**Note** Valid only when [IContactPropertyCollection::GetPropertyType](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nf-icontact-icontactpropertycollection-getpropertytype)
returns CGD_ARRAY_NODE for the current property.