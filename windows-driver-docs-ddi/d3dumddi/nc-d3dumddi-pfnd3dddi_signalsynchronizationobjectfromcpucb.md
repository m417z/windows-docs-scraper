# PFND3DDDI_SIGNALSYNCHRONIZATIONOBJECTFROMCPUCB callback function

## Description

**pfnSignalSynchronizationObjectFromCpuCb** enables a driver to signal a monitored fence.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMCPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_signalsynchronizationobjectfromcpu) structure that provides the details of the requested operation.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a monitored fence object is signaled by the CPU, the graphics kernel will update the fence memory location with the signaled value, so it becomes immediately visible to any user mode reader as well as immediately un-wait any satisfied waiters.
However, the caller cannot assume that the signal operation will be completed upon the return from this function. Instead, the caller should use appropriate *Wait* functions to check for signal completion.

**Note** A signal from a graphics processing unit (GPU) call is not provided. Instead, a driver can signal a new fence value by inserting a GPU write command for **FenceValueGPUVirtualAddress** into a command buffer.