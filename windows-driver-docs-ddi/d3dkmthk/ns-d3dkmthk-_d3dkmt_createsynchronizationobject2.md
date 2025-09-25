# D3DKMT_CREATESYNCHRONIZATIONOBJECT2 structure

## Description

The **D3DKMT_CREATESYNCHRONIZATIONOBJECT2** structure describes a synchronization object that [**D3DKMTCreateSynchronizationObject2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatesynchronizationobject2) creates.

## Members

### `hDevice` [in]

A handle to the device that the synchronization object is associated with.

### `Info` [in]

A [**D3DDDI_SYNCHRONIZATIONOBJECTINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2) structure with additional information about the kernel-mode synchronization object.

### `hSyncObject` [out]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the kernel-mode synchronization object.

## See also

[**D3DDDI_SYNCHRONIZATIONOBJECTINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2)

[**D3DKMTCreateSynchronizationObject2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatesynchronizationobject2)