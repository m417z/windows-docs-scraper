# IContactProperties::DeleteProperty

## Description

Deletes the value at a specified property. Property modification
and version data can still be enumerated with [IContactPropertyCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontactpropertycollection).

## Parameters

### `pszPropertyName` [in]

Type: **LPCWSTR**

Specifies the property to delete the value for.

### `dwFlags` [in]

Type: **DWORD**

Must be CGD_DEFAULT.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Property deleted successfully. |
| **ERROR_PATH_NOT_FOUND** | Property name doesn't exist for delete. |