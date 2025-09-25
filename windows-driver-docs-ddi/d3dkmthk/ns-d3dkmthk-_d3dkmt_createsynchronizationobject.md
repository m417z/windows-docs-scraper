# _D3DKMT_CREATESYNCHRONIZATIONOBJECT structure

## Description

The D3DKMT_CREATESYNCHRONIZATIONOBJECT structure describes a synchronization object that the [D3DKMTCreateSynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatesynchronizationobject) function creates.

## Members

### `hDevice` [in]

A handle to the device that the synchronization object is associated with.

### `Info` [in]

A [D3DDDI_SYNCHRONIZATIONOBJECTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo) structure that describes information about the kernel-mode synchronization object.

### `hSyncObject` [out]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the kernel-mode synchronization object.

## See also

[D3DDDI_SYNCHRONIZATIONOBJECTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo)

[D3DKMTCreateSynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatesynchronizationobject)