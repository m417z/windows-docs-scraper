# _D3DKMT_QUERYRESOURCEINFO structure

## Description

The D3DKMT_QUERYRESOURCEINFO structure describes parameters for retrieving information about a resource.

## Members

### `hDevice` [in]

A handle to the device that the resource and allocations are associated with.

### `hGlobalShare` [in]

A handle to the shared resource to open.

### `pPrivateRuntimeData` [in]

If non-**NULL**, a pointer to a buffer that receives the runtime-private data that is supplied at create time. The OpenGL ICD should first call the [D3DKMTQueryResourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryresourceinfo) function with **pPrivateRuntimeData** set to **NULL** to obtain the buffer size and then call again with the correct size buffer.

### `PrivateRuntimeDataSize` [in/out]

The size, in bytes, of the buffer that **pPrivateRuntimeData** points to. If **pPrivateRuntimeData** is **NULL**, **PrivateRuntimeDataSize** is set to the size, in bytes, that is required for the buffer to store the runtime-private data.

### `TotalPrivateDriverDataSize` [out]

The size, in bytes, of the buffer that is required to hold the private driver data for all of the allocations that are associated with the resource.

### `ResourcePrivateDriverDataSize` [out]

The size, in bytes, of the buffer that is required to hold the private driver data for the resource.

### `NumAllocations` [out]

The number of allocations that are associated with the resource.

## See also

[D3DKMTOpenResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenresource)

[D3DKMTQueryResourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryresourceinfo)