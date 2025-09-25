# _D3DKMT_OPENRESOURCE structure

## Description

The D3DKMT_OPENRESOURCE structure describes parameters for opening a resource.

## Members

### `hDevice` [in]

A handle to the device that the resource and allocations are associated with.

### `hGlobalShare` [in]

A handle to the shared resource to open.

### `NumAllocations` [in]

The number of elements in the array that **pOpenAllocationInfo** specifies, which represents the number of allocations that are associated with the resource.

### `pOpenAllocationInfo` [in/out]

An array of [D3DDDI_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo) structures that describe each allocation to update.

### `pOpenAllocationInfo2`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

### `pPrivateRuntimeData` [in]

A pointer to a caller-supplied buffer where the OpenGL runtime copies private data that is associated with the resource.

### `PrivateRuntimeDataSize` [in]

The size, in bytes, of the buffer that **pPrivateRuntimeData** points to.

### `pResourcePrivateDriverData` [in/out]

A pointer to a buffer that receives the private data that is associated with the resource. This data is per resource and not per allocation.

### `ResourcePrivateDriverDataSize` [in]

The size, in bytes, of the buffer that **pResourcePrivateDriverData** points to.

### `pTotalPrivateDriverDataBuffer` [in/out]

A pointer to a buffer that receives the private data for all of the allocations that are associated with the resource. The caller should never access this private data directly.

### `TotalPrivateDriverDataBufferSize` [in/out]

On input, the size, in bytes, of the buffer that **pTotalPrivateDriverDataBuffer** points to. On output, this member specifies the size, in bytes, of data that is written to the buffer that **pTotalPrivateDriverDataBuffer** points to.

### `hResource` [out]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the newly opened shared resource that is associated with the allocations.

## See also

[D3DDDI_OPENALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo)

[D3DKMTOpenResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenresource)