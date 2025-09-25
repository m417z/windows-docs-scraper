# IContactManager::Load

## Description

Loads an [IContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontact) object with the data from the contact
referenced by the computer-local contact ID.

## Parameters

### `pszContactID` [in]

Type: **LPCWSTR**

Specifies the contact ID to load.

### `ppContact` [out]

Type: **[IContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontact)****

Specifies the destination [IContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontact) object.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Contact was found and loaded. |
| **ERROR_NO_MATCH** | Could not find this contact ID. |

## See also

[GetContactID](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nf-icontact-icontact-getcontactid)

[IContactManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontactmanager)