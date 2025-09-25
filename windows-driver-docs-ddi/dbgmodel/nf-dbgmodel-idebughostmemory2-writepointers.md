# IDebugHostMemory2::WritePointers

## Description

Takes a number of pointers as held in unsigned 64-bit values, truncates them to the native pointer size of the target,and writes them into the address space of the target as defined by the inpassed context and location.

## Parameters

### `context`

The host context in which to write pointers. This represents, for example, the address space in which the location exists.

### `location`

The location at which to write pointers. This location may represent a virtual address within the address space defined by context or it may represent something like a register within a context record for a thread.

### `count`

The number of pointers to write.

### `pointers`

The pointers to write to the debug target. If the target is 32-bits, the pointer values here will be truncated prior to writing them to the underlying debug target.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDebugHostMemory2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmemory2)