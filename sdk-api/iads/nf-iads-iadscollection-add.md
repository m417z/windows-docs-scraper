# IADsCollection::Add

## Description

The **IADsCollection::Add** method adds a named item to the collection.

## Parameters

### `bstrName` [in]

The **BSTR** value that specifies the item name. [IADsCollection::GetObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscollection-getobject) and [IADsCollection::Remove](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscollection-remove) reference the item by this name.

### `vItem` [in]

Item value. When the item is an object, this parameter holds the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer on the object.

## Return value

This method supports the standard return values, as well as the following.

For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

Collections for a directory service can also consist of a set of immutable objects.

This method is not supported in any of the [ADSI system providers](https://learn.microsoft.com/windows/desktop/ADSI/adsi-system-providers).

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI System
Providers](https://learn.microsoft.com/windows/desktop/ADSI/adsi-system-providers)

[IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection)

[IADsCollection::GetObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscollection-getobject)

[IADsCollection::Remove](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscollection-remove)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)