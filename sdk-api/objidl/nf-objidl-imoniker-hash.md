# IMoniker::Hash

## Description

Creates a hash value using the internal state of the moniker.

## Parameters

### `pdwHash` [out]

A pointer to a variable that receives the hash value.

## Return value

This method returns S_OK to indicate that the hash value was retrieved successfully.

## Remarks

### Notes to Callers

You can use the value returned by this method to maintain a hash table of monikers. The hash value determines a hash bucket in the table. To search such a table for a specified moniker, calculate its hash value and then compare it to the monikers in that hash bucket using [IMoniker::IsEqual](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-isequal).

### Notes to Implementers

The hash value must be constant for the lifetime of the moniker. Two monikers that compare as equal using [IMoniker::IsEqual](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-isequal) must hash to the same value.

Marshaling and then unmarshaling a moniker should have no effect on its hash value. Consequently, your implementation of **IMoniker::Hash** should rely only on the internal state of the moniker, not on its memory address.

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | This method calculates a hash value for the moniker. |
| Class moniker | This method calculates a hash value for the moniker and returns S_OK. May return E_INVALIDARG if *pdwHash* is an invalid pointer. |
| File moniker | This method calculates a hash value for the moniker. |
| Generic composite moniker | This method calculates a hash value for the moniker. |
| Item moniker | This method calculates a hash value for the moniker. |
| OBJREF moniker | This method calculates a hash value for the moniker. |
| Pointer moniker | This method calculates a hash value for the moniker. |
| URL moniker | Creates a hash value based on the URL string of the moniker. This hash value is identical when URL strings are identical, although it may also be identical for different URL strings. This method is used to speed up comparisons by reducing the amount of time that it is necessary to call [IMoniker::IsEqual](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-isequal). |

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)