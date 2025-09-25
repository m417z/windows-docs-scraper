# _D3DDDICB_LOCK2 structure

## Description

**D3DDDICB_LOCK2** describes parameters for locking an allocation.

## Members

### `hAllocation` [in]

A driver specified **D3DKMT_HANDLE** to the allocation to lock.

### `Flags`

A set of flags to pass to the [Lock2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtlock2) kernel function which will determine how the allocation is locked. See [D3DDDICB_LOCK2FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lock2flags) for details.

### `pData` [out]

A CPU virtual address pointing a valid memory location pointing to the CPU backing store or the GPU frame buffer.

## See also

[D3DDDICB_LOCK2FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lock2flags)

[Lock2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtlock2)