# ISecurityCallersColl::get_Item

## Description

Retrieves a specified caller in the security callers collection.

## Parameters

### `lIndex` [in]

The name of the caller to retrieve. See Remarks for information about the available callers.

### `pObj` [out]

A reference to the retrieved caller.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The security callers collection represents a chain of callers that cross security boundaries. These callers are also known as upstream callers.

Each item in this collection is a [SecurityIdentity](https://learn.microsoft.com/windows/desktop/cossdk/securityidentity) object. To obtain an item in this collection, use the Item property of the [SecurityCallers](https://learn.microsoft.com/windows/desktop/cossdk/securitycallers) collection object, specifying an integer index value between 0 and the number of callers, minus 1, in the collection. To retrieve the direct caller, this index value should be 0, and to retrieve the original caller, the index can be either -1 or the number of callers minus 1.

## See also

[ISecurityCallersColl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecuritycallerscoll)