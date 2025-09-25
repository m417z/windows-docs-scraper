# FreePropVariantArray function

## Description

The **FreePropVariantArray** function calls
[PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear) on each of the
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures in the *rgvars* array to make the value zero for each of the members of the array.

## Parameters

### `cVariants` [in]

Count of elements in the
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) array (*rgvars*).

### `rgvars` [in]

Pointer to an initialized array of
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures for which any deallocatable elements are to be freed. On exit, all zeroes are written to the
**PROPVARIANT** structure (thus tagging them as VT_EMPTY).

## Return value

This function returns HRESULT.

## Remarks

**FreePropVariantArray** calls
[PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear) on an array of
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures to clear all the valid members. All valid
**PROPVARIANT** structures are freed. If any of the
**PROPVARIANT** structures contain illegal VT types, valid members are freed and the function returns STG_E_INVALIDPARAMETER.

Passing **NULL** for *rgvars* is legal, and produces a return code of S_OK.

## See also

[PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear)