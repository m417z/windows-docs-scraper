# IContactCollection::GetCurrent

## Description

Retrieves the current contact in the enumeration.

## Parameters

### `ppContact` [out]

Type: **[IContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontact)****

If successful, contains the current contact.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After reset, a call to **IContactCollection::GetCurrent** without first calling [IContactCollection::Next](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nf-icontact-icontactcollection-next) will fail.

## See also

[IContactCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontactcollection)

[IContactCollection::Reset](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nf-icontact-icontactcollection-reset)