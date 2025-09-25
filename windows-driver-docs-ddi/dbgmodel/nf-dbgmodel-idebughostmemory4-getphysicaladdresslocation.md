## Description

The GetPhysicalAddressLocation method creates a location structure that represents an offset as a physical memory address. Failure is a legitimate outcome (E_NOTIMPL) if the debugger does not support physical addressing. However, if the debugger supports physical addressing but a particular target does not, GetPhysicalAddressLocation will succeed but read attempts from that location will fail.

On successful execution of this method, the resulting location can be utilized with any method that requires a location. This includes the creation of typed objects at a physical address. Callers are free to modify the offset of the returned location after the method successfully returns.

## Parameters

### `physAddr`

The physical memory address which needs to be represented as location structure.

### `pPhysicalAddressLocation`

A pointer to the storage location where the location structure representing the physical memory address will be stored.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

If this method succeeds, the location can be utilized with any method that takes a location (including the creation of typed objects at a physical address).

## See also

[IDebugHostMemory4 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmemory4)