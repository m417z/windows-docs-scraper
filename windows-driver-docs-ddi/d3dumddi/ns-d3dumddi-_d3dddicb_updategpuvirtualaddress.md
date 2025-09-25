# _D3DDDICB_UPDATEGPUVIRTUALADDRESS structure

## Description

**D3DDDICB_UPDATEGPUVIRTUALADDRESS** is used with [pfnUpdateGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updategpuvirtualaddresscb) to allow the user mode driver to specify a number of mapping operations to be applied to the process virtual address space in a single batch of page table updates.

## Members

### `hContext`

Specifies the context against which the map operation will be synchronized against. This also determines which kernel context the map operation will be executed against. In a linked display adapter configuration **hContext** defines a physical GPU, whose page tables are modified.

### `hFenceObject`

Specifies the monitored fence object to use for synchronization. This should typically be set to the monitored fence used by the user mode driver to track progress of **hContext**.

### `NumOperations`

Specifies the number of operations in the **Operations** array.

### `Operations`

[D3DDDI_UPDATEGPUVIRTUALADDRESS_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_updategpuvirtualaddress_operation) array of operations to perform on the GPU virtual address space.

### `Reserved0`

This member is reserved and should be set to zero.

### `Reserved1`

This member is reserved and should be set to zero.

### `FenceValue`

Specifies the **FenceValue** for **hFenceObject** that the *Map* operation should wait on (unless **DoNotWait** is 1). When the *Map* operation completes, the fence object will signal **hFenceObject** with **FenceValue**+1.

### `Flags`

### `Flags.DoNotWait`

When set to 1, there will be no wait for the sync objects before executing the operations.

### `Flags.Reserved`

This member is reserved and should be set to zero.

### `Flags.Value`

The consolidated value of the **Flags** union.

## See also

[D3DDDI_UPDATEGPUVIRTUALADDRESS_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_updategpuvirtualaddress_operation)

[pfnUpdateGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updategpuvirtualaddresscb)