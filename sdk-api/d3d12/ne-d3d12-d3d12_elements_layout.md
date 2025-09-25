# D3D12_ELEMENTS_LAYOUT enumeration

## Description

Describes how the locations of elements are identified.

## Constants

### `D3D12_ELEMENTS_LAYOUT_ARRAY:0`

For a data set of *n* elements, the pointer parameter points to the start of *n* elements in memory.

### `D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS:0x1`

For a data set of *n* elements, the pointer parameter points to an array of *n* pointers in memory, each pointing to an individual element of the set.