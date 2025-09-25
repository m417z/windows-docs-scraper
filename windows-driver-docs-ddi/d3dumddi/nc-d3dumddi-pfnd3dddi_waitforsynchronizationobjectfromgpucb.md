# PFND3DDDI_WAITFORSYNCHRONIZATIONOBJECTFROMGPUCB callback function

## Description

**pfnWaitForSynchronizationObjectFromGpuCb** waits for a monitored fence to reach a certain value before processing subsequent context commands. For Windows Display Driver Model (WDDM) v2 drivers, existing [pfnWaitForSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectcb) and [pfnWaitForSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobject2cb) callbacks are deprecated and will eventually be removed. WDDM v2 user mode drivers should switch to **pfnWaitForSynchronizationObjectFromGpuCb**, as it supports all synchronization object types.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_WAITFORSYNCHRONIZATIONOBJECTFROMGPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_waitforsynchronizationobjectfromgpu) structure that provides the details of the requested operation.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function semantics are similar to existing [pfnWaitForSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobject2cb) call, except that this callback also supports monitored fence objects and an array of monitored fence values to wait for.

## See also

[D3DDDICB_WAITFORSYNCHRONIZATIONOBJECTFROMGPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_waitforsynchronizationobjectfromgpu)

*pfnWaitForSynchronizationObject2Cb*

[pfnWaitForSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectcb)