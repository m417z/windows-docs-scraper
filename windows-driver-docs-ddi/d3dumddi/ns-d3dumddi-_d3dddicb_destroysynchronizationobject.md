# _D3DDDICB_DESTROYSYNCHRONIZATIONOBJECT structure

## Description

The D3DDDICB_DESTROYSYNCHRONIZATIONOBJECT structure contains the handle to a synchronization object to destroy.

## Members

### `hSyncObject` [in]

A D3DKMT_HANDLE value that represents the kernel-mode handle that the [pfnCreateSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobjectcb) function returns and that identifies the kernel-mode synchronization object to destroy.

## See also

[pfnCreateSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobjectcb)

[pfnDestroySynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroysynchronizationobjectcb)