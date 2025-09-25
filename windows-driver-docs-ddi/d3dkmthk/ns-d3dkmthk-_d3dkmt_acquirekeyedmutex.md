# D3DKMT_ACQUIREKEYEDMUTEX structure

## Description

The **D3DKMT_ACQUIREKEYEDMUTEX** structure describes a keyed mutex that the [**D3DKMTAcquireKeyedMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtacquirekeyedmutex) function acquires.

## Members

### `hKeyedMutex`

[in] A D3DKMT_HANDLE data type that represents a kernel-mode handle to the keyed mutex object to acquire.

### `Key`

[in] A 64-bit value that specifies the key value to acquire the mutex for.

### `pTimeout`

[in] A pointer to a time-out value that specifies the absolute or relative time, in 100-nanosecond units, at which acquiring the mutex is to be completed.

A positive value specifies an absolute time, relative to January 1, 1601. A negative value specifies an interval relative to the current time. Absolute expiration times track any changes in the system time; relative expiration times are not affected by system time changes.

If ***pTimeout** = 0, [**D3DKMTAcquireKeyedMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtacquirekeyedmutex) returns without waiting. If the caller supplies a NULL pointer, **D3DKMTAcquireKeyedMutex** waits indefinitely until the mutex object is set to the signaled state.

### `FenceValue`

[out] A 64-bit value that specifies the current fence value of the GPU synchronization object.

## See also

[**D3DKMTAcquireKeyedMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtacquirekeyedmutex)