# IContactCollection::Reset

## Description

Resets the enumerator to before the logical first element.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A call to [IContactCollection::GetCurrent](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nf-icontact-icontactcollection-getcurrent) immediately after **IContactCollection::Reset** is undefined. To get the first contact, call [IContactCollection::Next](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nf-icontact-icontactcollection-next) first to ensure that there is one.