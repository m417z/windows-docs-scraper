# _D3DKMT_RELEASEKEYEDMUTEX structure

## Description

The D3DKMT_RELEASEKEYEDMUTEX structure describes a keyed mutex that the [D3DKMTReleaseKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreleasekeyedmutex) function releases.

## Members

### `hKeyedMutex` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the keyed mutex object to release.

### `Key` [in]

A 64-bit value that specifies the key value to release the mutex to.

### `FenceValue` [in]

A 64-bit value that specifies the current fence value of the GPU synchronization object.

## See also

[D3DKMTReleaseKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreleasekeyedmutex)