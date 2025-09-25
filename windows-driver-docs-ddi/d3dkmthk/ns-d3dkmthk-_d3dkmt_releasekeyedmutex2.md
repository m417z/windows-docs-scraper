# _D3DKMT_RELEASEKEYEDMUTEX2 structure

## Description

Describes a keyed mutex object that the [D3DKMTReleaseKeyedMutex2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreleasekeyedmutex2) function releases that includes private data.

## Members

### `hKeyedMutex` [in]

A value of type **D3DKMT_HANDLE** that represents a kernel-mode handle to the keyed mutex object to release.

### `Key` [in]

A 64-bit value that specifies the key value to release the mutex to.

### `FenceValue` [in]

A 64-bit value that specifies the current fence value of the GPU synchronization object.

### `pPrivateRuntimeData` [in]

A pointer to a caller-supplied buffer where the runtime private data associated with the resource is stored.

### `PrivateRuntimeDataSize` [in]

The size, in bytes, of the buffer pointed to by the **pPrivateRuntimeData** member.

## See also

[D3DKMTReleaseKeyedMutex2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreleasekeyedmutex2)