# ICatInformation::EnumCategories

## Description

Retrieves an enumerator for the component categories registered on the system.

## Parameters

### `lcid` [in]

The requested locale for any return szDescription of the enumerated categories. Typically, the caller specifies the value returned from the [GetUserDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlcid) function.

### `ppenumCategoryInfo` [out]

A pointer to a pointer to an [IEnumCATEGORYINFO](https://learn.microsoft.com/windows/desktop/api/comcat/nn-comcat-ienumcategoryinfo) interface. This can be used to enumerate the CATIDs and localized description strings of the component categories registered with the system.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and S_OK.

## See also

[ICatInformation](https://learn.microsoft.com/windows/desktop/api/comcat/nn-comcat-icatinformation)