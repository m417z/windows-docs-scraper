# PFND3DDDI_CREATEPAGINGQUEUECB callback function

## Description

**pfnCreatePagingQueueCb** is used to create a device paging queue that can be used to synchronize with video memory management operations for the device, such as making the device resource resident.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

*pData* [out]

A pointer to a [D3DDDICB_CREATEPAGINGQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_createpagingqueue) structure that provides the details of the requested operation.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A device can have multiple paging queues created for it. Paging queues can be destroyed either explicitly by calling [pfnDestroyPagingQueueCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroypagingqueuecb), or by implicitly destroying the device they belong to. After the latter, paging queue handles will become invalid.