# IMoniker::IsEqual

## Description

Determines whether this moniker is identical to the specified moniker.

## Parameters

### `pmkOtherMoniker` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker to be used for comparison with this one (the one from which this method is called).

## Return value

This method returns S_OK to indicate that the two monikers are identical, and S_FALSE otherwise.

## Remarks

Previous implementations of the running object table (ROT) called this method. The current implementation of the ROT uses the [IROTData](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irotdata) interface instead.

### Notes to Callers

Call this method to determine whether two monikers are identical. The reduced form of a moniker is considered different from the unreduced form. You should call the [IMoniker::Reduce](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-reduce) method before calling **IsEqual**, because a reduced moniker is in its most specific form. **IsEqual** may return S_FALSE on two monikers before they are reduced, and S_OK after they are reduced.

### Notes to Implementers

Your implementation should not reduce the current moniker before performing the comparison. It is the caller's responsibility to call [IMoniker::Reduce](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-reduce) to compare reduced monikers.

Two monikers that compare as equal must hash to the same value using [IMoniker::Hash](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-hash).

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | This method returns S_OK if both are anti-monikers; otherwise, it returns S_FALSE. |
| Class moniker | This method returns S_OK if *pmkOther* is a class moniker constructed with the same CLSID information as itself. Otherwise, the method returns S_FALSE. May return E_INVALIDARG if *pmkOther* is an invalid pointer. |
| File moniker | This method returns S_OK if **pmkOther* is a file moniker and the paths for both monikers are identical (using a case-insensitive comparison). Otherwise, the method returns S_FALSE. |
| Generic composite moniker | This method returns S_OK if the components of both monikers are equal when compared in the left-to-right order. |
| Item moniker | This method returns S_OK if both monikers are item monikers and their display names are identical (using a case-insensitive comparison); otherwise, the method returns S_FALSE. |
| OBJREF moniker | This method returns S_OK if *pmkOther is an OBJREF moniker and the paths for both monikers are identical (using a case-insensitive comparison). Otherwise, the method returns S_FALSE. |
| Pointer moniker | This method returns S_OK only if both are pointer monikers and the interface pointers that they wrap are identical. |
| URL moniker | Returns S_FALSE if the other moniker (*pmkOtherMoniker*) is not an URL moniker, which it checks using [IPersist::GetClassID](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid) to see whether the CLSID is CLSID_URLMoniker. If the other moniker is an URL moniker, it compares the display names of the monikers for equality, returning S_OK if they are identical or S_FALSE otherwise. |

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[IROTData](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irotdata)