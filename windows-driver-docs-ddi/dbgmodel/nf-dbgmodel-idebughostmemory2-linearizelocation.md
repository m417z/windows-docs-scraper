# IDebugHostMemory2::LinearizeLocation

## Description

Takes a location which may represent something other than a virtual memory address and attempts to linearize the location into a virtual memory address within the given context. This operation may fail if the location cannot be represented by a virtual address (e.g.: it's a register).

## Parameters

### `context`

The host context in which the location is valid. This represents, for example, the address space in which the location exists.

### `location`

The location to linearize into a virtual memory address.

### `pLinearizedLocation`

A new location representing a virtual memory address will be returned here. If the location cannot be linearized into a virtual memory address (e.g.: the location represents an enregistered value), this method will fail.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDebugHostMemory2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmemory2)