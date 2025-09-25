# PFREE_DMA_BUFFER callback function

## Description

The `FreeDmaBuffer` routine frees a DMA buffer that was previously allocated by a call to **AllocateDmaBuffer**.

The function pointer type for a `FreeDmaBuffer` routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** member of the [HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface) or the [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2) structure.

### `Handle` [in]

Handle identifying the DMA engine. This handle value was obtained from a previous call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine).

## Return value

`FreeDmaBuffer` returns STATUS_SUCCESS if the call succeeds. Otherwise, the routine returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | Indicates that the caller is running at an IRQL that is too high. |
| **STATUS_INVALID_HANDLE** | Indicates that the handle parameter value is invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | Indicates that the stream is not in the reset state or that no buffer is currently allocated for the DMA engine. |

## Remarks

The `FreeDmaBuffer` routine is used in conjunction with the [AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer) routine. These two routines are available only in the HDAUDIO_BUS_INTERFACE version of the HD Audio DDI. This DDI does not include the [AllocateContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_contiguous_dma_buffer), [SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl), and [FreeContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_contiguous_dma_buffer) routines, which are never used in conjunction with **AllocateDmaBuffer** and `FreeDmaBuffer`. Unlike **SetupDmaEngineWithBdl**, which configures the DMA engine to use a previously allocated DMA buffer, **AllocateDmaBuffer** both allocates a DMA buffer and configures the DMA engine to use the buffer.

The routine fails and returns error code STATUS_INVALID_DEVICE_REQUEST in either of the following circumstances:

* The client calls `FreeDmaBuffer` when no buffer is currently allocated for the DMA engine.
* The stream is in a state other than reset.

## See also

[AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer)

[HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)

[SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl)