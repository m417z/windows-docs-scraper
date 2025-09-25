# IContactManager::GetMeContact

## Description

Retrieves the local user account concept of 'me'.

## Parameters

### `ppMeContact` [out]

Type: **[IContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontact)****

Specifies where to store a pointer to the 'me' contact.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Retrieval was successful. |