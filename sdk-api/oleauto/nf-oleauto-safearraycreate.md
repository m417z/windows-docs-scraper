# SafeArrayCreate function

## Description

Creates a new array descriptor, allocates and initializes the data for the array, and returns a pointer to the new array descriptor.

## Parameters

### `vt` [in]

The base type of the array (the VARTYPE of each element of the array). The VARTYPE is restricted to a subset of the variant types. Neither the VT_ARRAY nor the VT_BYREF flag can be set. VT_EMPTY and VT_NULL are not valid base types for the array. All other types are legal.

### `cDims` [in]

The number of dimensions in the array. The number cannot be changed after the array is created.

### `rgsabound` [in]

A vector of bounds (one for each dimension) to allocate for the array.

## Return value

A safe array descriptor, or null if the array could not be created.