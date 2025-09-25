# _D3DKMT_CREATEKEYEDMUTEX2 structure

## Description

Describes a keyed mutex that the [D3DKMTCreateKeyedMutex2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatekeyedmutex2) function creates that includes private data.

## Members

### `InitialValue` [in]

A 64-bit value that specifies the initial value to create the keyed mutex for.

### `hSharedHandle` [out]

A value of type **D3DKMT_HANDLE** that represents a kernel-mode shared global handle to the keyed mutex object.

### `hKeyedMutex` [out]

A value of type **D3DKMT_HANDLE** that represents a kernel-mode handle to the keyed mutex object in the current process.

### `pPrivateRuntimeData` [in]

A pointer to a caller-supplied buffer where the runtime private data associated with the resource is stored.

### `PrivateRuntimeDataSize` [in]

The size, in bytes, of the buffer pointed to by the **pPrivateRuntimeData** member.

### `Flags` [in]

A [D3DKMT_CREATEKEYEDMUTEX2_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex2_flags) structure that indicates how to specify a handle to a keyed mutex object.

## See also

[D3DKMTCreateKeyedMutex2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatekeyedmutex2)

[D3DKMT_CREATEKEYEDMUTEX2_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex2_flags)