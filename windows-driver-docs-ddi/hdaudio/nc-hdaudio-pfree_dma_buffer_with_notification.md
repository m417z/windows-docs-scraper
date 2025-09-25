# PFREE_DMA_BUFFER_WITH_NOTIFICATION callback function

## Description

The `FreeDmaBufferWithNotification` routine frees a DMA buffer that was previously allocated by a call to [AllocateDmaBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer_with_notification).

The function pointer type for a FreeDmaBufferWithNotification routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the Context member of the [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2) structure.

### `Handle` [in]

Handle that identifies the DMA engine. This handle value was obtained from a previous call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine).

### `BufferMdl` [in]

A pointer to the buffer MDL. This value was obtained from a previous call to AllocateDmaBufferWithNotification.

### `BufferSize` [in]

The size of the buffer to be freed. This value was obtained from a previous call to AllocateDmaBufferWithNotification.

## Return value

`FreeDmaBufferWithNotification` returns STATUS_SUCCESS if the call succeeds. Otherwise, `FreeDmaBufferWithNotification` returns an appropriate error code. The following table shows some of the possible return error codes.

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | Indicates that the caller is running at an IRQL that is too high. |
| **STATUS_INVALID_HANDLE** | Indicates that the *handle* parameter value is invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | Indicates that the stream is not in the reset state or that no buffer is currently allocated for the DMA engine. |

## Remarks

The `FreeDmaBufferWithNotification` routine is used together with the AllocateDmaBufferWithNotification routine. These two routines are available only in the HDAUDIO_BUS_INTERFACE_V2 version of the HD Audio DDI.

Callers of FreeDmaBufferWithNotification must be running at IRQL PASSIVE_LEVEL.

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateDmaBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer_with_notification)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)