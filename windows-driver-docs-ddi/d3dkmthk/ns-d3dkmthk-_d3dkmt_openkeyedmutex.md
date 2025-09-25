# _D3DKMT_OPENKEYEDMUTEX structure

## Description

The D3DKMT_OPENKEYEDMUTEX structure describes a keyed mutex that the [D3DKMTOpenKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenkeyedmutex) function opens.

## Members

### `hSharedHandle` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode shared global handle to the keyed mutex object.

### `hKeyedMutex` [out]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the keyed mutex object in the current process.

## See also

[D3DKMTOpenKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenkeyedmutex)