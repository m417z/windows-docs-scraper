# _D3DDDI_OPENALLOCATIONINFO structure

## Description

The D3DDDI_OPENALLOCATIONINFO structure describes an allocation to be opened.

## Members

### `hAllocation` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the allocation. The user-mode display driver should use this handle to reference the allocation in the command buffer.

### `pPrivateDriverData` [in]

A pointer to a block of private data, which was passed to the display miniport driver when the resource was created.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the block of private data that is pointed to by **pPrivateDriverData**.