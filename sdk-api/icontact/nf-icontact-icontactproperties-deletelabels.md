# IContactProperties::DeleteLabels

## Description

Deletes the labels at a specified array entry.

## Parameters

### `pszArrayElementName` [in]

Type: **LPCWSTR**

Specifies the property to delete labels on.

### `dwFlags` [in]

Type: **DWORD**

Must be CGD_DEFAULT.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Labels deleted successfully. |
| **ERROR_PATH_NOT_FOUND** | Property name doesn't exist for delete. |