# PFND3DDDI_DESTROYPAGINGQUEUECB callback function

## Description

**pfnDestroyPagingQueueCb** waits for a paging queue to finish all operations queued to it and destroys it along with the associated sync object.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDI_DESTROYPAGINGQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_destroypagingqueue) structure that describes the operation to perform.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In addition to **hPagingQueue**, this device driver interface (DDI) invalidates **hSyncObject** and **FenceValueCPUVirtualAddress** values returned from [pfnCreatePagingQueueCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createpagingqueuecb).

## See also

[D3DDDI_DESTROYPAGINGQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_destroypagingqueue)

[pfnCreatePagingQueueCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createpagingqueuecb)