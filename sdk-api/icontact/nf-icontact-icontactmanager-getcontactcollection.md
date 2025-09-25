# IContactManager::GetContactCollection

## Description

Returns an [IContactCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontactcollection) object that contains all known contacts.

## Parameters

### `ppContactCollection` [out]

Type: **[IContactCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontactcollection)****

On success, contains an enumeration of the contact collection.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. *ppContactCollection* contains the collection. |

## Remarks

The enumerator of the new collection is set before the first contact. You must first call [Next](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nf-icontact-icontactcollection-next) before querying the collection with [GetCurrent](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nf-icontact-icontactcollection-getcurrent).