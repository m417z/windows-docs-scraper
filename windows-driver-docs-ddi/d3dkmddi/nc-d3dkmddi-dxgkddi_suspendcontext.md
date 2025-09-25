# DXGKDDI_SUSPENDCONTEXT callback function

## Description

**DxgkddiSuspendContext** instructs the GPU to suspend a context. If the GPU doesn’t acknowledge the suspend completion within the TDR (timeout detection and recovery) timeout, the OS will detect the engine timeout and perform an engine reset.

## Parameters

### `hAdapter`

[in] The hardware context to be preempted and marked as suspended. This type of preemption request doesn't have a grace period, and is expected to be honored by the GPU as soon as possible.

### `pSuspendContext`

[in] Pointer to a [**DXGKARG_SUSPENDCONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_suspendcontext) structure that contains additional arguments for this function.

## Return value

**DxgkddiSuspendContext** returns STATUS_SUCCESS if the context is already suspended at the time of this call. Otherwise, this value is set to STATUS_PENDING, and the suspend operation will be finished when **contextSuspendFence** is signaled via an interrupt.

## Remarks

Register your implementation of this callback function by setting it in [**DRIVER_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_driver_initialization_data).

Even though the round robin preemption can be initiated by the GPU, the OS still needs a way to preempt the context for other reasons; for example, if it needs to move its allocations around or perform a GPU power transition.

The context suspend value is necessary to handle cases when the OS suspends a context, doesn’t wait for the suspend acknowledgment, resumes, and suspends a context again. The suspend value will allow the OS to distinguish between the previous suspend acknowledgement and the latest one.

Once a context is suspended, it is assumed that all references to it are gone from the GPU, and the OS is free to destroy the context or move its memory around. Unlike WDDM 2.3 or earlier, no separate NULL context switch command (previously indicated by the **ContextSwitch** flag in **DxgkDdiSubmitCommandVirtual**) is present in WDDM 2.4 scheduling mode, because **DxgkddiSuspendContext** is supposed to do this work.

## See also

[**DxgkddiResumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resumecontext)

[**DXGKARG_SUSPENDCONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_suspendcontext)