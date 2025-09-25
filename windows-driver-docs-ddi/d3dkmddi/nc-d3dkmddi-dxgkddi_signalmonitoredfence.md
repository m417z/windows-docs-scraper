# DXGKDDI_SIGNALMONITOREDFENCE callback function

## Description

Adds a GPU instruction to signal the paging monitored fence object to the DMA (direct memory access) buffer. This callback function is called from a Video memory management worker thread when submitting paging buffers, and from the application thread performing kernel submissions such as [PresentBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_submitpresentblttohwqueuecb) or [RenderGdi](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_rendergdi). The OS passes a hint to the driver regarding the kernel submission type.

## Parameters

### `hContext`

Driver context handle for the context that generated the kernel submission.

### `pSignalMonitoredFence`

Pointer to a [DXGKARG_SIGNALMONITOREDFENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_signalmonitoredfence) structure that contains parameters to signal the monitored fence object.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

DXGKDDI_SIGNALMONITOREDFENCE DxgkddiSignalmonitoredfence;

// Definition

NTSTATUS DxgkddiSignalmonitoredfence
(
    IN_CONST_HANDLE hContext
    INOUT_PDXGKARG_SIGNALMONITOREDFENCE pSignalMonitoredFence
)
{...}

```

## Remarks

WDDM synchronization class:

* [Zero Level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level) for RenderGdi and PresentBlt submission types.
* [First Level GPU Scheduler Class](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-first-level) for [BuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) submission type.

## See also

[DXGKARG_SIGNALMONITOREDFENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_signalmonitoredfence)