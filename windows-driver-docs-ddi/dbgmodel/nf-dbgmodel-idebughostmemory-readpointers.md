# IDebugHostMemory::ReadPointers

## Description

Reads a number of pointer sized objects from the address space of the target as defined by the inpassed context and location.

Each read pointer is, if necessary, zero extended to 64-bits and returned.

## Parameters

### `context`

The host context in which to read pointers. This represents, for example, the address space in which the location exists.

### `location`

The location at which to read pointers. This location may represent a virtual address within the address space defined by context or it may represent something like a register within a context record for a thread.

### `count`

The number of pointers to read.

### `pointers`

The pointers read from the debug target will be placed into the array passed here. Any pointers less than 64-bits in size will be zero extended to 64-bits.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDebugHostMemory interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmemory)