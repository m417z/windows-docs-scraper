# D3DKMT_OPENRESOURCEFROMNTHANDLE structure

## Description

The **D3DKMT_OPENRESOURCEFROMNTHANDLE** structure contains information required to open a shared resource from an NT handle to the process. The shared resource can be a set of allocations, a keyed mutex, or a synchronization object.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents the device.

### `hNtHandle` [in]

An NT handle to the process.

### `NumAllocations` [in]

The number of allocations associated with the resource.

### `pOpenAllocationInfo2` [in]

This member is reserved and should be set to zero.

### `PrivateRuntimeDataSize` [in]

The size, in bytes, of the buffer pointed to by the **pPrivateRuntimeData** member.

### `pPrivateRuntimeData` [in]

A caller-supplied buffer where the runtime private data associated with this resource will be copied to.

### `ResourcePrivateDriverDataSize` [in]

The size, in bytes, of the buffer pointed to by the **pResourcePrivateDriverData** member.

### `pResourcePrivateDriverData` [in]

A caller-supplied buffer where the driver private data associated with the resource will be copied to.

### `TotalPrivateDriverDataBufferSize` [in]

The size, in bytes, of the buffer pointed to by the **pTotalPrivateDriverDataBuffer** member.

[out] The size, in bytes, of the data written to **pTotalPrivateDriverDataBuffer**.

### `pTotalPrivateDriverDataBuffer` [in]

A pointer to a caller-supplied buffer where the driver private data will be stored.

### `hResource` [out]

A handle to the resource in this process.

### `hKeyedMutex` [out]

A handle to the keyed mutex in this process.

### `pKeyedMutexPrivateRuntimeDat` [in]

A buffer that contains initial private data.

The data in this buffer will be copied only if the keyed mutex does not already have private data.

If this member has a value of NULL, the value of the **KeyedMutexPrivateRuntimeDataSize** member must be zero.

### `KeyedMutexPrivateRuntimeDataSize` [in]

The size, in bytes, of the buffer pointed to by the **pKeyedMutexPrivateRuntimeData** member.

### `hSyncObject` [out]

A handle to the synchronization object in this process.

## See also

[**D3DDDI_OPENALLOCATIONINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo2)

[**D3DKMTOpenNtHandleFromName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopennthandlefromname)

[**D3DKMTShareObjects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects)