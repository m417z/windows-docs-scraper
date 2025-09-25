# SafeArrayCreateVector function

## Description

Creates a one-dimensional array. A safe array created with **SafeArrayCreateVector** is a fixed size, so the constant FADF_FIXEDSIZE is always set.

## Parameters

### `vt` [in]

The base type of the array (the VARTYPE of each element of the array). The VARTYPE is restricted to a subset of the variant types. Neither the VT_ARRAY nor the VT_BYREF flag can be set. VT_EMPTY and VT_NULL are not valid base types for the array. All other types are legal.

### `lLbound` [in]

The lower bound for the array. This parameter can be negative.

### `cElements` [in]

The number of elements in the array.

## Return value

A safe array descriptor, or null if the array could not be created.

## See also

[SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate)

[SafeArrayDestroy](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-safearraydestroy)