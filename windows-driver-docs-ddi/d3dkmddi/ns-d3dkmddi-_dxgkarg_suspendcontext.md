# DXGKARG_SUSPENDCONTEXT structure

## Description

The **DXGKARG_SUSPENDCONTEXT** structure contains arguments used in the [**DxgkddiSuspendContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_suspendcontext) callback function.

## Members

### `hContext`

[in] The hardware context to be preempted and marked as suspended. This type of preemption request does not have a grace period, and is expected to be honored by the GPU as soon as possible.

### `contextSuspendFence`

[in] A monotonically increasing per-context value that will be reported by the GPU context suspended interrupt once the preemption request is completed. Until the fence is signaled, the OS cannot assume GPU is suspended.

## Remarks

The context suspend fence value is necessary to handle cases when the OS suspends a context, doesn’t wait for the suspend fence acknowledgment, resumes, and suspends a context again. The suspend fence value will allow the OS to distinguish between the previous suspend acknowledgement and the latest one.

## See also

[**DxgkddiSuspendContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_suspendcontext)