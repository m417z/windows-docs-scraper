## Description

This enum defines the memory layout of one dimension of an extended array. It is designed to fully describe the array layout of a CLI (ECMA-335) array.

## Constants

### `ExtendedArrayLengthIsOffset32`

Indicates that the "Length" field of the array dimension is an offset from the base address of the array where to find a dynamic size.
### `ExtendedArrayLengthIsOffset64`

Similar to `ExtendedArrayLengthIsOffset32` but for 64 bit offsets.
### `ExtendedArrayLengthIsOffset`

This flag can be used in place of `ExtendedArrayLengthIsOffset32` or `ExtendedArrayLengthIsOffset64` to denote the offset of the dynamic size.

### `ExtendedArrayLowerBoundIsOffset32`
Indicates that the "LowerBound" field of the array dimension is an offset from the base address of the array where to find a dynamic bound.
### `ExtendedArrayLowerBoundIsOffset64`

Similar to `ExtendedArrayLowerBoundIsOffset32` but for 64 bit offsets.
### `ExtendedArrayLowerBoundIsOffset`

This flag can be used in place of `ExtendedArrayLowerBoundIsOffset32` or `ExtendedArrayLowerBoundIsOffset64` to denote the offset of the dynamic bound.
### `ExtendedArrayStrideIsOffset32`

Indicates that the "Stride" field of the array dimension is an offset from the base address of the array where to find a dynamic stride.
### `ExtendedArrayStrideIsOffset64`

Similar to `ExtendedArrayStrideIsOffset32` but for 64 bit offsets.
### `ExtendedArrayStrideIsOffset`

This flag can be used in place of `ExtendedArrayStrideIsOffset32` or `ExtendedArrayStrideIsOffset64` to denote the offset of the dynamic stride.
### `ExtendedArrayStrideIsComputedByNextRank`

Indicates that the "Stride" field is computed from the element size and the computed sizes of each dimension as indicated by other fields. The stride of this dimension is based on the stride of the next (e.g.: dim[0] is the largest).
### `ExtendedArrayStrideIsComputedByPreviousRank`

Similar to `ExtendedArrayStrideIsComputedByNextRank`, but the stride of this dimension is based on the stride of the previous (e.g.: dim[0] is the smallest).
### `ExtendedArrayStrideIsComputed`

This flag can be used in place of `ExtendedArrayStrideIsComputedByNextRank` or `ExtendedArrayStrideIsComputedByPreviousRank` to denote that the stride is computed based on other dimensions.

## Remarks

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)