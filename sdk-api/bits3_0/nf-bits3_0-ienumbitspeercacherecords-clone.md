# IEnumBitsPeerCacheRecords::Clone

## Description

Creates another
[IEnumBitsPeerCacheRecords](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ienumbitspeercacherecords) enumerator that contains the same enumeration state as the current one.

Using this method, a client can record a particular point in the enumeration sequence, and then return to that point at a later time. The new enumerator supports the same interface as the original one.

## Parameters

### `ppenum` [out]

Receives the interface pointer to the enumeration object. If the method is unsuccessful, the value of this output variable is undefined. You must release *ppEnum* when done.

## Return value

This method returns **S_OK** on success or one of the standard COM **HRESULT** values on error.

## See also

[IEnumBitsPeerCacheRecords](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ienumbitspeercacherecords)