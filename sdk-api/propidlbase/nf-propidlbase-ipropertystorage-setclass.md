# IPropertyStorage::SetClass

## Description

The **SetClass** method assigns a new CLSID to the current property storage object, and persistently stores the CLSID with the object.

## Parameters

### `clsid` [in]

New CLSID to be associated with the property set.

## Return value

This method supports the standard return value E_UNEXPECTED, in addition to the following:

## Remarks

Assigns a CLSID to the current property storage object. The CLSID has no relationship to the stored property IDs. Assigning a CLSID allows a piece of code to be associated with a given instance of a property set; such code, for example, might manage the user interface (UI). Different CLSIDs can be associated with different property set instances that have the same FMTID.

If the property set is created with the *pclsid* parameter of the [IPropertySetStorage::Create](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-create) method specified as **NULL**, the CLSID is set to all zeroes.

The current CLSID on a property storage object can be retrieved with a call to
[IPropertyStorage::Stat](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-stat). The initial value for the CLSID can be specified at the time that the storage is created with a call to [IPropertySetStorage::Create](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-create).

Setting the CLSID on a nonsimple property set (one that can legally contain storage- or stream-valued properties, as described in [IPropertySetStorage::Create](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-create)) also sets the CLSID on the underlying sub-storage.

## See also

[IPropertySetStorage::Create](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-create)

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IPropertyStorage::Stat](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-stat)