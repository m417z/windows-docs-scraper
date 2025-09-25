# IContactProperties::CreateArrayNode

## Description

Creates a new array node in a multi-value property.

## Parameters

### `pszArrayName` [in]

Type: **LPCWSTR**

Specifies the top-level property for which to create a new node.

### `dwFlags` [in]

Type: **DWORD**

Must be CGD_DEFAULT.

### `fAppend` [in]

Type: **BOOL**

TRUE for insert after, **FALSE** for insert before.

### `pszNewArrayElementName` [in, out]

Type: **LPWSTR**

Specifies a user-allocated buffer to store the new array element name.

### `cchNewArrayElementName` [in]

Type: **DWORD**

Specifies an allocated buffer size in characters.

### `pdwcchNewArrayElementNameRequired` [in, out]

Type: **DWORD***

On failure, contains the required size for *pszNewArrayElementName*.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | New node is created and name is in *pszNewArrayElementName*. |
| **ERROR_PATH_NOT_FOUND** | Macro HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND) returned when array name is invalid. |
| **ERROR_INSUFFICIENT_BUFFER** | Macro HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) returned when *pszNewArrayElementName* is not large enough to store the value. The required buffer size is stored in *pdwcchNewArrayElementNameRequired*. |

## Remarks

**Note** The first element of an existing set is at index 1.

To create a *pszArrayName* at toplevel/secondlevel[1],
call this function with *pszArrayName* == toplevel, fAppend=**FALSE**.

To create an array node that is an extension at [namespace]toplevel/secondlevel[1],
call this function with *pszArrayName* == [namespace:secondlevel]toplevel.

To append to the set, pass *fAppend*=TRUE instead;
*pszNewArrayElementName* then contains the resulting array node name, including the index.