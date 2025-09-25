# PALLOCATE_DMA_BUFFER callback function

## Description

The `AllocateDmaBuffer` routine allocates a data buffer in system memory for a DMA engine.

The function pointer type for an `AllocateDmaBuffer` routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** members of the [HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface) and [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2) structures.

### `Handle` [in]

Handle identifying the DMA engine. This handle value was obtained from a previous call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine).

### `RequestedBufferSize` [in]

Specifies the requested buffer size in bytes.

### `BufferMdl` [out]

Retrieves the physical memory pages that contains the allocated buffer. This parameter points to a caller-allocated PMDL variable into which the routine writes a pointer to a memory descriptor list (MDL) that describes the buffer.

### `AllocatedBufferSize` [out]

Retrieves the allocated buffer size in bytes. This parameter points to a caller-allocated SIZE_T variable into which the routine writes the size of the allocated buffer.

### `StreamId` [out]

Retrieves the stream identifier. This parameter points to a caller-allocated UCHAR variable into which the routine writes the stream identifier that it assigns to the stream.

### `FifoSize` [out]

Retrieves the DMA engine's FIFO size in bytes. This parameter points to a caller-allocated ULONG variable into which the routine writes the FIFO size.

## Return value

`AllocateDmaBuffer` returns STATUS_SUCCESS if the call succeeds. Otherwise, the routine returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | Indicates that the caller is running at an IRQL that is too high. |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates that buffer allocation failed. |
| **STATUS_INVALID_HANDLE** | Indicates that the handle parameter value is invalid. |
| **STATUS_INVALID_PARAMETER** | Indicates that one of the parameter values is incorrect (bad pointer). |
| **STATUS_DEVICE_NOT_READY** | Indicates that the hardware programming timed out. If this occurs, the hardware might be in a compromised state. |
| **STATUS_INVALID_DEVICE_REQUEST** | Indicates that the stream is not in the reset state or that a buffer is already allocated for the DMA engine. |

## Remarks

The `AllocateDmaBuffer` routine is used in conjunction with the [FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer) routine. These two routines are available only in the HDAUDIO_BUS_INTERFACE and the HDAUDIO_BUS_INTERFACE_V2 versions of the HD Audio DDI. This DDI does not include the [AllocateContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_contiguous_dma_buffer), [SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl), and [FreeContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_contiguous_dma_buffer) routines, which are never used in conjunction with `AllocateDmaBuffer` and **FreeDmaBuffer**. Unlike **SetupDmaEngineWithBdl**, which configures the DMA engine to use a previously allocated DMA buffer, `AllocateDmaBuffer` both allocates a DMA buffer and configures the DMA engine to use the buffer.

If the DMA engine cannot use a buffer of the size requested in parameter *requestedBufferSize*, the routine allocates a buffer that is as close as possible to the requested size.

The function driver for an audio or modem codec is responsible for programming the codec to manage the data transfers and to recognize the stream identifier.

The routine outputs an MDL that lists the physical memory pages that contain the buffer. The buffer base address coincides with the start of the first physical page in the list.

During the lifetime of a DMA engine handle, `AllocateDmaBuffer` can be called successively to allocate new DMA buffers. However, before calling `AllocateDmaBuffer`, any previously allocated DMA buffer must first be freed by calling **FreeDmaBuffer**.

During calls to `AllocateDmaBuffer` and **FreeDmaBuffer**, the DMA engine must be in the reset stream state. The DMA engine is in the reset state immediately following the call to Allocate*Xxx*DmaEngine. To change the DMA engine to the run state, call [SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state).

The FIFO size is the maximum number of bytes that the DMA engine can hold in its internal buffer. Depending on the hardware implementation, a DMA engine's FIFO size can either be static or vary dynamically with changes in the stream format. For more information about the FIFO size, see the Intel High Definition Audio Specification at the [Intel HD Audio](https://go.microsoft.com/fwlink/p/?linkid=42508) website.

This routine fails and returns error code STATUS_INVALID_DEVICE_REQUEST in either of the following circumstances:

* Any previously allocated DMA buffer has not been freed (by calling **FreeDmaBuffer**).
* The stream is in a state other than reset.

In Windows Server 2003, Windows XP, Windows 2000, and Windows Me/98, a WDM audio driver calls this routine during execution of its **NewStream** method (at pin-creation time) or **SetFormat** method (after calling one of the Allocate*Xxx*DmaEngine routines in the HD Audio DDI). For more information, see [IMiniportWavePci::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-newstream) and [IMiniportWavePciStream::SetFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-setformat).

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer)

[FreeDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_engine)

[HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)

[IMiniportWavePci::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-newstream)

[IMiniportWavePciStream::SetFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-setformat)

[SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state)

[SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl)