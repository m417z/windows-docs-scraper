# ICatInformation::EnumReqCategoriesOfClass

## Description

Retrieves an enumerator for the CATIDs required by the specified class.

## Parameters

### `rclsid` [in]

The class identifier.

### `ppenumCatid` [out]

A pointer to an [IEnumCATID](https://learn.microsoft.com/windows/desktop/api/comcat/nn-comcat-ienumguid) interface pointer. This can be used to enumerate the CATIDs that are required by *rclsid*.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and S_OK.

## See also

[ICatInformation](https://learn.microsoft.com/windows/desktop/api/comcat/nn-comcat-icatinformation)