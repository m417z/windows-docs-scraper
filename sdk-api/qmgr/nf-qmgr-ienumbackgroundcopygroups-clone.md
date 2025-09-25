# IEnumBackgroundCopyGroups::Clone

## Description

[**IEnumBackgroundCopyGroups** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **Clone** method to create another [IEnumBackgroundCopyGroups](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ienumbackgroundcopygroups) enumerator that contains the same enumeration state as the current one.

Using this method, a client can record a particular point in the enumeration sequence, and then return to that point at a later time. The new enumerator supports the same interface as the original one.

## Parameters

### `ppenum` [out]

Receives the interface pointer to the enumeration object. If the method is unsuccessful, the value of this output variable is undefined. You must release *ppenum* when done.

## Return value

This method returns **S_OK** on success.

## See also

[IEnumBackgroundCopyGroups](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ienumbackgroundcopygroups)