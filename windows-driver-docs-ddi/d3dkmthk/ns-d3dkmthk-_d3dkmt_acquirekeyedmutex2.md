# D3DKMT_ACQUIREKEYEDMUTEX2 structure

## Description

Describes a keyed mutex object that the [**D3DKMTAcquireKeyedMutex2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtacquirekeyedmutex2) function acquires that includes private data.

## Members

### `hKeyedMutex`

[in] A D3DKMT_HANDLE data type that represents a handle to the keyed mutex.

### `Key`

[in] The key value to acquire.

### `pTimeout`

[in] An NT-style timeout value.

### `FenceValue`

[out] The current fence value of the GPU sync object.

### `pPrivateRuntimeData`

[out] A pointer to a buffer to copy private data to.

### `PrivateRuntimeDataSize`

[in] The size, in bytes, of the **pPrivateRuntimeData** member.

## See also

[**D3DKMTAcquireKeyedMutex2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtacquirekeyedmutex2)