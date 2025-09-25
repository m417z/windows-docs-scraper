# ArrayDimension structure

## Description

Defines the memory layout of one dimension of an array.

## Members

### `LowerBound`

The lower bounds of the array. For C style zero based arrays, this will always be zero. There is no uniform restriction that all arrays represented by these interfaces are zero based.

### `Length`

Defines the length of the dimension. The dimension is considered to be of the form [LowerBound, LowerBound + Length)

### `Stride`

Defines how many bytes to move forward in memory to walk from index N of the dimension to index N + 1

## Remarks

For C-style arrays, a single array dimension is returned here with values which are always:
LowerBound = 0

Length = ARRAYSIZE(array)

Stride = sizeof(elementType)

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)