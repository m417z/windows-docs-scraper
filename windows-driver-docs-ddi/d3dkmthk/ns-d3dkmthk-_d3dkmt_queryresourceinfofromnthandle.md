# _D3DKMT_QUERYRESOURCEINFOFROMNTHANDLE structure

## Description

Describes information that is required to map a global NT handle to resource information.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the device.

### `hNtHandle` [in]

A global NT handle to the resource that is to be queried.

### `pPrivateRuntimeData` [in]

A pointer to a caller-supplied buffer where the runtime private data associated with the resource will be copied to.

### `PrivateRuntimeDataSize` [in]

The size, in bytes, of the buffer pointed to by the **pPrivateRuntimeData** member.

[out] If **pPrivateRuntimeData** is **NULL**, this member is the size, in bytes, of the buffer required to receive the runtime private data. Otherwise, this member is the size, in bytes, of runtime private data copied into the buffer.

### `TotalPrivateDriverDataSize` [out]

The size, in bytes, of the buffer that is required to hold all the driver private data for all allocations associated with the resource.

### `ResourcePrivateDriverDataSize` [out]

The size, in bytes, of the driver's resource private data.

### `NumAllocations` [out]

The number of allocations associated with the resource.

## See also

[D3DKMTQueryResourceInfoFromNtHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryresourceinfofromnthandle)