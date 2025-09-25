# _D3DKMT_DESTROYSYNCHRONIZATIONOBJECT structure

## Description

The D3DKMT_DESTROYSYNCHRONIZATIONOBJECT structure contains the handle to a synchronization object to destroy.

## Members

### `hSyncObject` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle that the [D3DKMTCreateSynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatesynchronizationobject) function returns and that identifies the kernel-mode synchronization object to destroy.

## See also

[D3DKMTCreateSynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatesynchronizationobject)

[D3DKMTDestroySynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroysynchronizationobject)