# _D3DKMT_OPENKEYEDMUTEX2 structure

## Description

Describes a keyed mutex that the [D3DKMTOpenKeyedMutex2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenkeyedmutex2) function opens.

## Members

### `hSharedHandle` [in]

A D3DKMT_HANDLE data type that represents a global handle to a keyed mutex.

### `hKeyedMutex` [out]

A D3DKMT_HANDLE data type that represents a handle to the keyed mutex in this process.

### `pPrivateRuntimeData` [in]

A buffer that contains initial private data. This buffer is copied only if the keyed mutex does not already have private data.

### `PrivateRuntimeDataSize` [in]

The size, in bytes, of the **pPrivateRuntimeData** member.

## See also

[D3DKMTOpenKeyedMutex2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenkeyedmutex2)