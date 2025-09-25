# PALLOCATE_CONTIGUOUS_DMA_BUFFER callback function

## Description

The `AllocateContiguousDmaBuffer` routine allocates a DMA buffer that consists of a single, contiguous block of physical memory.

The function pointer type for an `AllocateContiguousDmaBuffer` routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** member of the [HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl) structure.

### `Handle` [in]

Handle identifying the DMA engine. This handle value was obtained from a previous call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine).

### `RequestedBufferSize`

Specifies the requested buffer size in bytes.

### `DataBuffer` [out]

Retrieves the data buffer. This parameter points to a caller-allocated PVOID variable into which the routine writes the system virtual address of the data buffer.

### `BdlBuffer` [out]

Retrieves the buffer descriptor list (BDL). This parameter points to a caller-allocated PVOID variable into which the routine writes the system virtual address of the BDL. The BDL allocation size is exactly one memory page and the BDL begins on a page boundary.

## Return value

`AllocateContiguousDmaBuffer` returns STATUS_SUCCESS if the call succeeds. Otherwise, the routine returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | Indicates that the caller is running at an interrupt request level (IRQL) that is too high. |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates that buffer allocation failed. |
| **STATUS_INVALID_HANDLE** | Indicates that the handle parameter value is invalid. |
| **STATUS_INVALID_PARAMETER** | Indicates that one of the parameter values is incorrect (bad pointer). |
| **STATUS_DEVICE_NOT_READY** | Indicates that the hardware programming timed out. If this occurs, the hardware might be in a compromised state. |
| **STATUS_INVALID_DEVICE_REQUEST** | Indicates that the stream is not in the reset state or that a buffer is already allocated for the DMA engine. |

## Remarks

The `AllocateContiguousDmaBuffer` routine is used in conjunction with the [SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl) and [FreeContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_contiguous_dma_buffer) routines. These three routines are available only in the HDAUDIO_BUS_INTERFACE_BDL version of the HD Audio DDI. This DDI does not include the [AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer) and [FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer) routines, which are never used in conjunction with `AllocateContiguousDmaBuffer`, **SetupDmaEngineWithBdl**, and **FreeContiguousDmaBuffer**. Unlike **SetupDmaEngineWithBdl**, which configures the DMA engine to use a previously allocated DMA buffer, `AllocateDmaBuffer` both allocates a DMA buffer and configures the DMA engine to use the buffer. For more information, see [Differences between the Two DDI Versions](https://learn.microsoft.com/windows-hardware/drivers/audio/differences-between-the-hd-audio-ddi-versions).

`AllocateContiguousDmaBuffer` allocates a data buffer for the specified DMA engine. It also allocates a page of memory for the BDL. Depending on the host processor architecture, a typical page size might be 4,096 or 8,192 bytes. The data buffer consists of a single, contiguous block of physical memory.

The handle parameter specifies the DMA engine that is to use the data buffer and BDL. The routine allocates storage that meets the DMA engine's size, alignment, and position requirements.

The storage that the routine allocates for the data buffer and BDL is uninitialized. The function driver is responsible for filling in the BDL before submitting it to the **SetupDmaEngineWithBdl** routine. The function driver is also responsible for programming the codec to manage the data transfers and to recognize the stream identifier.

To generate IOC interrupts at precise intervals, the function driver might be required to divide the data buffer allocation into several fragments of a particular size. Each fragment is described by a BDL entry. The fragment size can be adjusted to tune the interrupt rate. According to the Intel High Definition Audio Specification (see the [Intel HD Audio](https://go.microsoft.com/fwlink/p/?linkid=42508) website), each fragment must begin on a 128-byte boundary, although no such alignment requirement applies to the length of the fragment. Thus, a gap might exist between the end of one fragment and the beginning of the next. When calling **SetupDmaEngineWithBdl**, the function driver must specify a value for the *bufferSize* parameter that represents the sum of the sizes of the individual fragments that the BDL entries describe. This size will be less than or equal to the number of bytes specified in the `AllocateContiguousDmaBuffer` routine's *requestedBufferSize* parameter.

During the lifetime of a DMA engine handle, `AllocateContiguousDmaBuffer` can be called successively to allocate new DMA buffers. However, before calling `AllocateContiguousDmaBuffer`, any previously allocated DMA buffer must first be freed by calling **FreeContiguousDmaBuffer**.

During calls to `AllocateContiguousDmaBuffer`, **SetupDmaEngineWithBdl**, and **FreeContiguousDmaBuffer**, the DMA engine must be in the reset stream state. The DMA engine is in the reset state immediately following the call to Allocate*Xxx*DmaEngine. To change the DMA engine to the run state, call [SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state).

This routine fails and returns error code STATUS_INVALID_DEVICE_REQUEST in either of the following circumstances:

* Any previously allocated DMA buffer has not been freed (by calling **FreeContiguousDmaBuffer**).
* The stream is in a state other than reset.

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[FreeContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_contiguous_dma_buffer)

[FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer)

[HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl)

[SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state)

[SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl)