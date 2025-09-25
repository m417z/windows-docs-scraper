# _D3DKMT_CREATEKEYEDMUTEX structure

## Description

The D3DKMT_CREATEKEYEDMUTEX structure describes a keyed mutex that the [D3DKMTCreateKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatekeyedmutex) function creates.

## Members

### `InitialValue` [in]

A 64-bit value that specifies the initial value to create the keyed mutex for.

### `hSharedHandle` [out]

A D3DKMT_HANDLE data type that represents a kernel-mode shared global handle to the keyed mutex object.

### `hKeyedMutex` [out]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the keyed mutex object in the current process.

## See also

[D3DKMTCreateKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatekeyedmutex)