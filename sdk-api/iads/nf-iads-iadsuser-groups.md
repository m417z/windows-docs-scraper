# IADsUser::Groups

## Description

The **IADsUser::Groups** method obtains a collection of the ADSI group objects to which this user belongs. The method returns an [IADsMembers](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsmembers) interface pointer through which you can enumerate all the groups in the collection.

## Parameters

### `ppGroups` [out]

Pointer to a pointer to the [IADsMembers](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsmembers) interface on a members object that can be enumerated using [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) to determine the groups to which this end-user belongs.

## Return value

This method supports the standard return values, including S_OK. For other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsMembers](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsmembers)

[IADsUser](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsuser)

[IADsUser
Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsuser-property-methods)

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)