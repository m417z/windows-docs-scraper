# IContactManager::MergeContactIDs

## Description

Makes an old Contact ID resolve to the same value as a new Contact ID.
Subsequent calls to [IContactManager::Load](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nf-icontact-icontactmanager-load) with the old contact ID
now loads the new contact ID contact.

## Parameters

### `pszNewContactID` [in]

Type: **LPWSTR**

Specifies the ID of the new contact, representing both the old and new contacts.

### `pszOldContactID` [in]

Type: **LPCWSTR**

Specifies the ID representing the old contact.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Address change was successful. |