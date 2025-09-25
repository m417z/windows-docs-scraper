## Description
The **ExtendedArrayDimension** struct provides details about an array dimension, including how to interpret the remainder of the information in the array dimension, lower bounds, length, and stride.
## Members
### `DimensionFlags`
The **DimensionFlags** member is a ULONG64 type that specifies information about how to interpret the remainder of the information in the array dimension.
### `LowerBound`
The **LowerBound** member is a LONG64 type that defines the lower bounds of the array. For C style zero based arrays, this will always be zero. Note that there is no uniform restriction that all arrays represented by these interfaces are zero based.
### `Length`
The **Length** member is a ULONG64 type that specifies the length of the dimension. The dimension is considered to be of the form (LowerBound, LowerBound + Length).
### `Stride`
The **Stride** member is a ULONG64 type that defines how many bytes to move forward in memory to walk from index N of the dimension to index N + 1.
## Remarks
The **ExtendedArrayDimension** struct is typically used for handling multi-dimensional arrays. With this struct, each dimension of the array can have its own properties such as lower bound, length, and stride. This makes it especially useful when dealing with non-zero based or non-uniform arrays.

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)