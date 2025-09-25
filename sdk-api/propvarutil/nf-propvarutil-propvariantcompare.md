# PropVariantCompare function

## Description

Compares two [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures, based on default comparison units and settings.

## Parameters

### `propvar1` [in]

Type: **REFPROPVARIANT**

Reference to the first [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `propvar2` [in]

Type: **REFPROPVARIANT**

Reference to the second [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **INT**

* Returns 1 if *propvar1* is greater than *propvar2*
* Returns 0 if *propvar1* equals *propvar2*
* Returns -1 if *propvar1* is less than *propvar2*

## Remarks

Calling [PropVariantCompare](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantcompare) is equivalent to calling [PropVariantCompareEx](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantcompareex) with the PVCHF_DEFAULT flag.

This function compares only selected types, not all types.

By default, VT_NULL / VT_EMPTY / 0-element vectors are considered to be less than any other vartype.

If the vartypes are different, this function attempts to convert *propvar2* to the vartype of *propvar1* before comparing them.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

## See also

[PropVariantCompareEx](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantcompareex)