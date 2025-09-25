# IContactProperties::DeleteArrayNode

## Description

Deletes the data at a specified array entry.

## Parameters

### `pszArrayElementName` [in]

Type: **LPCWSTR**

Specifies array entry from which to remove all data.

### `dwFlags` [in]

Type: **DWORD**

Must be CGD_DEFAULT.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Node is deleted. |
| **ERROR_PATH_NOT_FOUND** | Property name doesn't exist for delete. |

## Remarks

**Note** Element indexes are unchanged for the entire set. Array node element ID,
modification and version data can still be enumerated with [IContactPropertyCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontactpropertycollection).