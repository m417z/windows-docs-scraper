# IContactManager::Initialize

## Description

Initializes the contact manager with the unique application name and application version
being used to manipulate contacts.

## Parameters

### `pszAppName` [in]

Type: **LPWSTR**

Specifies the application name.

### `pszAppVersion` [in]

Type: **LPCWSTR**

Specifies the application version.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [IContactManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontactmanager) is initialized. |

## Remarks

**Note** This method MUST be called before other [IContactManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontactmanager) methods.