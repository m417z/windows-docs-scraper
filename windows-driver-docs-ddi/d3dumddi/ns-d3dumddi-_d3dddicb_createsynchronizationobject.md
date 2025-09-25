# _D3DDDICB_CREATESYNCHRONIZATIONOBJECT structure

## Description

The D3DDDICB_CREATESYNCHRONIZATIONOBJECT structure describes a synchronization object that the [pfnCreateSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobjectcb) function creates.

## Members

### `Info` [in]

A [D3DDDI_SYNCHRONIZATIONOBJECTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo) structure that contains information about the kernel-mode synchronization object.

### `hSyncObject` [out]

A **D3DKMT_HANDLE** value that represents a kernel-mode handle to the kernel-mode synchronization object.

## See also

[D3DDDI_SYNCHRONIZATIONOBJECTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo)

[pfnCreateSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobjectcb)