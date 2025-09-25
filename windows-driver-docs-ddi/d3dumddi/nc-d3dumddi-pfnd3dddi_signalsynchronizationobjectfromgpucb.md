# PFND3DDDI_SIGNALSYNCHRONIZATIONOBJECTFROMGPUCB callback function

## Description

**pfnSignalSynchronizationObjectFromGpuCb** is used to signal a monitored fence. When a particular graphics processing unit (GPU) engine is not capable of writing a new monitored fence value directly using its GPU virtual address, the driver needs to flush its command buffer and issue a signal from a GPU packet using [pfnSignalSynchronizationObjectFromGpu2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectfromgpu2cb). For Windows Display Driver Model (WDDM) v2 drivers, existing [pfnSignalSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectcb) and [pfnSignalSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb) callbacks are deprecated and will eventually be removed. WDDM v2 user mode drivers should switch to **pfnSignalSynchronizationObjectFromGpuCb**, as it supports all synchronization object types.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMGPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_signalsynchronizationobjectfromgpu) structure that provides the details of the requested operation.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function semantics are similar to existing [pfnSignalSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb) call. In addition, the function supports monitored fence objects and an array of monitored fence values to signal.

## See also

[D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMGPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_signalsynchronizationobjectfromgpu)

[pfnSignalSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb)

[pfnSignalSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectcb)

[pfnSignalSynchronizationObjectFromGpu2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectfromgpu2cb)