# IEnumUnknown::Clone

## Description

Creates a new enumerator that contains the same enumeration state as the current one.

This method makes it possible to record a point in the enumeration sequence in order to return to that point at a later time. The caller must release this new enumerator separately from the first enumerator.

## Parameters

### `ppenum` [out]

A pointer to the cloned enumerator object.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## See also

[IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown)