# _D3DKMT_UPDATEGPUVIRTUALADDRESS structure

## Description

**D3DKMT_UPDATEGPUVIRTUALADDRESS** is used with [UpdateGpuVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtupdategpuvirtualaddress) to allow the driver to specify a number of mapping operations to be applied to the process virtual address space in a single batch of page table updates.

## Members

### `hDevice`

A handle to the device.

### `hContext`

A handle to a context that the map operation will be synchronized against. This also determines which kernel context the map operation will be executed against. In a linked display adapter (LDA) configuration **hContext** defines a physical GPU whose page tables are modified.

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

Specifies the **FenceValue** for **hFenceObject** that the map operation should wait on (unless **DoNotWait** is 1). When the map operation completes, the fence object will signal **hFenceObject** with **FenceValue**+1.

### `Flags`

Flag options.

### `Flags.DoNotWait`

When set to 1, there will be no wait for the sync objects before executing the operations.

### `Flags.Reserved`

This member is reserved and should be set to zero.

### `Flags.Value`

The consolidated value of the **Flags** union.