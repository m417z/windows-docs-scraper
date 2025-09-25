# D3DKMTSignalSynchronizationObjectFromCpu function

## Description

**D3DKMTSignalSynchronizationObjectFromCpu** enables a driver to signal a monitored fence.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMCPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_signalsynchronizationobjectfromcpu) structure that provides the details of the requested operation..

## Return value

**D3DKMTSignalSynchronizationObjectFromCpu** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The operation was successful. |

This function might also return other **NTSTATUS** values.

## Remarks

When a monitored fence object is signaled by the CPU, the graphics kernel will update the fence memory location with the signaled value, so it becomes immediately visible to any user mode reader as well as immediately un-wait any satisfied waiters. However, the caller cannot assume that the signal operation will be completed upon the return from this function. Instead, the caller should use appropriate wait functions to check for signal completion.

> [!NOTE]
> A signal from a graphics processing unit (GPU) call is not provided. Instead, a driver can signal a new fence value by inserting a GPU write command for **FenceValueGPUVirtualAddress** into a command buffer.

## See also

[D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMCPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_signalsynchronizationobjectfromcpu)