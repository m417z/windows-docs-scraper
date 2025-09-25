# _D3DKMT_OPENSYNCHRONIZATIONOBJECT structure

## Description

The D3DKMT_OPENSYNCHRONIZATIONOBJECT structure describes a synchronization object that the [D3DKMTOpenSynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopensynchronizationobject) function opens.

## Members

### `hSharedHandle` [in]

A shared handle to the synchronization object to be opened.

### `hSyncObject` [out]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the kernel-mode synchronization object in the current process.

### `Reserved` [in]

An array of 64-bit values that are reserved for future use.

## See also

[D3DKMTOpenSynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopensynchronizationobject)