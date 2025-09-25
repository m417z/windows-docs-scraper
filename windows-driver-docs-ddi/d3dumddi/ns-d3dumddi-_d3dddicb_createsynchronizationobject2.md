# _D3DDDICB_CREATESYNCHRONIZATIONOBJECT2 structure

## Description

Describes a synchronization object that the [pfnCreateSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobject2cb) function creates.

## Members

### `Info` [in]

A [D3DDDI_SYNCHRONIZATIONOBJECTINFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2) structure that contains information about the kernel-mode synchronization object to create.

### `hSyncObject` [out]

A **D3DKMT_HANDLE** value that represents a kernel-mode handle to the created kernel-mode GPU synchronization object.

## See also

[D3DDDI_SYNCHRONIZATIONOBJECTINFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2)

[pfnCreateSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobject2cb)