# PALLOCATE_DMA_BUFFER_WITH_NOTIFICATION callback function

## Description

The `AllocateDmaBufferWithNotification` routine allocates a data buffer in system memory for a DMA engine.

The function pointer type for an `AllocateDmaBufferWithNotification` routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the Context member of the [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2) structure.

### `Handle` [in]

A handle that identifies the DMA engine. This handle value was obtained from a previous call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine).

### `NotificationCount` [in]

Specifies the number of notifications that are needed, based on DMA progression through the audio buffer. Currently, a value of 1 or 2 is supported. When the value is 1, any registered notification events are signaled each time the cyclic audio buffer is completed and DMA wraps back to the beginning. When the value is 2, any registered notification events are notified as DMA passes the midpoint of the audio buffer as well as at the end (or the wraparound point).

### `RequestedBufferSize` [in]

Specifies the requested buffer size, in bytes.

### `BufferMdl` [out]

Retrieves the physical memory pages that contain the allocated buffer. This parameter points to a caller-allocated variable that is a pointer to a memory descriptor list (PMDL). This routine writes a pointer that describes the memory descriptor list buffer, to the PMDL variable.

### `AllocatedBufferSize` [out]

Retrieves the allocated buffer size, in bytes. This parameter points to a caller-allocated SIZE_T variable into which the routine writes the size of the allocated buffer.

### `OffsetFromFirstPage`

### `StreamId` [out]

Retrieves the stream identifier. This parameter points to a caller-allocated UCHAR variable into which the routine writes the stream identifier that the routine assigns to the stream.

### `FifoSize` [out]

Retrieves the DMA engine's FIFO size, in bytes. This parameter points to a caller-allocated ULONG variable into which the routine writes the FIFO size.

## Return value

The `AllocateDmaBufferWithNotification` routine returns STATUS_SUCCESS if the call succeeds. Otherwise, the routine returns an appropriate error code. The following table shows some of the possible return error codes.

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | Indicates that the caller is running at an IRQL that is too high. |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates that the buffer allocation has failed. |
| **STATUS_INVALID_HANDLE** | Indicates that the handle parameter value is invalid. |
| **STATUS_INVALID_PARAMETER** | Indicates that one of the parameter values is incorrect (bad pointer). |
| **STATUS_DEVICE_NOT_READY** | Indicates that the hardware programming timed out. If this occurs, the hardware might be in a compromised state. |
| **STATUS_INVALID_DEVICE_REQUEST** | Indicates that the stream is not in the reset state or that a buffer is already allocated for the DMA engine and has not yet been freed. |

## Remarks

The `AllocateDmaBufferWithNotification` routine is used together with the [FreeDmaBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer_with_notification) routine. These two routines are available only in the HDAUDIO_BUS_INTERFACE_V2 version of the HD Audio DDI. Unlike [SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl), which configures the DMA engine to use a previously allocated DMA buffer, `AllocateDmaBufferWithNotification` allocates a DMA buffer and also configures the DMA engine to use the buffer.

If the DMA engine cannot use a buffer of the size that is requested in parameter *requestedBufferSize*, the routine allocates a buffer that is as close as possible to the requested size.

The function driver for an audio or modem codec is responsible for programming the codec to manage the data transfers and to recognize the stream identifier.

`AllocateDmaBufferWithNotification` outputs an MDL that lists the physical memory pages that contain the buffer. The buffer base address coincides with the start of the first physical page in the list.

During the lifetime of a DMA engine handle, `AllocateDmaBufferWithNotification` can be called successively to allocate new DMA buffers. However, before calling `AllocateDmaBufferWithNotification`, any previously allocated DMA buffer must first be freed by calling FreeDmaBufferWithNotification.

During calls to `AllocateDmaBufferWithNotification` and **FreeDmaBufferWithNotification**, the DMA engine must be in the reset stream state. The DMA engine is in the reset stream state immediately following the call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine). To change the DMA engine to the run state, call [SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state).

The FIFO size is the maximum number of bytes that the DMA engine can hold in its internal buffer. Depending on the hardware implementation, a DMA engine's FIFO size can either be static or vary dynamically with changes in the stream format. For more information about the FIFO size, see the [Intel High Definition Audio Specification](https://go.microsoft.com/fwlink/p/?linkid=42508).

In Windows Vista and later versions of Windows, a WaveRT miniport driver calls this routine when it receives the [KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer-with-notification) property request.

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)

[KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer-with-notification)

[SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state)

[SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl)