# PFREE_CONTIGUOUS_DMA_BUFFER callback function

## Description

The `FreeContiguousDmaBuffer` routine frees a DMA buffer and buffer descriptor list (BDL) that were allocated by a call to **AllocateContiguousDmaBuffer**.

The function pointer type for a `FreeContiguousDmaBuffer` routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** member of the [HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl) structure.

### `Handle` [in]

Handle identifying the DMA engine. This handle value was obtained from a previous call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine).

## Return value

`FreeContiguousDmaBuffer` returns STATUS_SUCCESS if the call succeeds. Otherwise, the routine returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | Indicates that the caller is running at an IRQL that is too high. |
| **STATUS_INVALID_HANDLE** | Indicates that the handle parameter value is invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | Indicates that the stream is not in the reset state or that no buffer is currently allocated for the DMA engine. |

## Remarks

The `FreeContiguousDmaBuffer` routine is used in conjunction with the [SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl) and [AllocateContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_contiguous_dma_buffer) routines. These three routines are available only in the HDAUDIO_BUS_INTERFACE_BDL version of the HD Audio DDI. This DDI does not include the [AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer) and [FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer) routines, which are never used in conjunction with **AllocateContiguousDmaBuffer**, **SetupDmaEngineWithBdl**, and `FreeContiguousDmaBuffer`. Unlike **SetupDmaEngineWithBdl**, which configures the DMA engine to use a previously allocated DMA buffer, **AllocateDmaBuffer** both allocates a DMA buffer and configures the DMA engine to use the buffer. For more information, see [Differences between the Two DDI Versions](https://learn.microsoft.com/windows-hardware/drivers/audio/differences-between-the-hd-audio-ddi-versions).

The routine fails and returns error code STATUS_INVALID_DEVICE_REQUEST in either of the following circumstances:

* The client calls `FreeContiguousDmaBuffer` when no buffer is currently allocated for the DMA engine.
* The stream is in a state other than reset.

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_contiguous_dma_buffer)

[AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer)

[HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl)

[SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl)