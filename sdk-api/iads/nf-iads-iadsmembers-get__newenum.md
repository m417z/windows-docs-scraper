# IADsMembers::get__NewEnum

## Description

The **IADsMembers::get__NewEnum** method gets a dependent enumerator object that implements [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) for this ADSI collection object. Be aware that there are two underscore characters in the function name (**get__NewEnum**).

## Parameters

### `ppEnumerator` [out]

Pointer to a pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the enumerator object for this collection.

## Return value

This method supports the standard return values, including S_OK. For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsMembers](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsmembers)

[IADsMembers Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsmembers-property-methods)

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)