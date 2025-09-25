# PSETUP_DMA_ENGINE_WITH_BDL callback function

## Description

The *SetupDmaEngineWithBdl* routine sets up a DMA engine to use a caller-allocated DMA buffer.

The function pointer type for a *SetupDmaEngineWithBdl* routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** member of the [HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl) structure.

### `Handle` [in]

Handle that identifies the DMA engine. This handle value was obtained from a previous call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine).

### `BufferLength` [in]

The length of the buffer.

### `Lvi` [in]

Specifies the last valid index (LVI). This parameter contains the index for the last valid buffer descriptor in the BDL. After the DMA engine processes this descriptor, it wraps back to the first descriptor in the list and continues processing. If the BDL contains *n* descriptors, they are numbered 0 to *n*-1. The *lvi* value must be at least 1; in other words, the BDL must contain at least two valid entries before the DMA engine can begin operation.

### `Isr` [in]

Function pointer to the caller's ISR. If the caller sets the interrupt-on-completion (IOC) bit in one or more of the buffer descriptors in the BDL, the HD Audio bus driver calls the ISR each time an IOC interrupt occurs on the stream. This parameter is a function pointer of type HDAUDIO_BDL_ISR, which is defined in the following Remarks section.

### `Context` [in]

The context.

### `StreamId` [out]

Retrieves the stream identifier. This parameter points to a caller-allocated UCHAR variable into which the routine writes the stream identifier that it assigns to the stream.

### `FifoSize` [out]

Retrieves the DMA engine's FIFO size in bytes. This parameter points to a caller-allocated UINT variable into which the routine writes the FIFO size.

## Return value

*SetupDmaEngineWithBdl* returns STATUS_SUCCESS if the call succeeds. Otherwise, the routine returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | Indicates that the caller is running at an IRQL that is too high. |
| **STATUS_INVALID_HANDLE** | Indicates that the *handle* parameter value is invalid. |
| **STATUS_INVALID_PARAMETER** | Indicates that one of the parameter values is incorrect (bad pointer or invalid stream format). |
| **STATUS_DEVICE_NOT_READY** | Indicates that the hardware programming timed out. If this occurs, the hardware might be in a compromised state. |
| **STATUS_INVALID_DEVICE_REQUEST** | Indicates that the DMA device or DMA buffer is not allocated or the stream is not in the Reset state. |

## Remarks

The *SetupDmaEngineWithBdl* routine is used in conjunction with the [AllocateContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_contiguous_dma_buffer) and [FreeContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_contiguous_dma_buffer) routines. These three routines are available only in the HDAUDIO_BUS_INTERFACE_BDL version of the HD Audio DDI. This DDI does not include the [AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer) and [FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer) routines, which are never used in conjunction with **AllocateContiguousDmaBuffer**, *SetupDmaEngineWithBdl*, and **FreeContiguousDmaBuffer**. Unlike *SetupDmaEngineWithBdl*, which configures the DMA engine to use a previously allocated DMA buffer, **AllocateDmaBuffer** both allocates a DMA buffer and configures the DMA engine to use the buffer.

The caller must call [AllocateContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_contiguous_dma_buffer) to allocate storage in the system memory for both the DMA buffer and the BDL that describes the physical memory pages in the buffer. The BDL entries must reside in memory that is physically contiguous. The BDL and buffer memory must meet the alignment requirements that are described in the *Intel High Definition Audio Specification* (see the [Intel HD Audio](https://go.microsoft.com/fwlink/p/?linkid=42508) website).

Both the BDL and the buffer memory that it describes must remain valid during DMA operations. Following the call to *SetupDmaEngineWithBdl*, the BDL and buffer memory must remain valid as long as the DMA engine continues to use the buffer. The DMA engine uses the buffer until the function driver replaces the buffer by calling *SetupDmaEngineWithBdl* again or frees the DMA engine by calling [FreeDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_engine). The function driver is responsible for calling [FreeContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_contiguous_dma_buffer) to free the buffer and BDL when they are no longer required.

When allocating memory for the buffer, the caller must satisfy all hardware constraints for the address, length, and alignment of the physically contiguous blocks of memory that the BDL specifies. Thus, only clients with significant knowledge of the bus controller and system hardware should use the *SetupDmaEngineWithBdl* routine.

Before calling *SetupDmaEngineWithBdl* to configure a DMA engine, the client must call [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine) to allocate the DMA engine. The handle parameter is the value obtained from the preceding call to Allocate *Xxx*DmaEngine.

The caller is responsible for programming the codec to manage the data transfers and to recognize the stream identifier.

A WDM audio driver calls this routine at pin-creation time during execution of its **NewStream** method (for example, see [IMiniportWavePci::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-newstream)).

Following the call to *SetupDmaEngineWithBdl*, the DMA engine is in the Reset state. To start the DMA engine, call [SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state).

Parameter *isr* specifies the ISR that the HD Audio bus driver is to call each time an IOC interrupt occurs on the stream. This parameter is a function pointer of type HDAUDIO_BDL_ISR, which is defined as:

```cpp
typedef void
  (*PHDAUDIO_BDL_ISR)
    (IN VOID *Context, IN ULONG InterruptBitMask);
```

The HD Audio bus driver calls the ISR with the same context value that the client specified in the context parameter of the preceding *SetupDmaEngineWithBdl* call. The *interruptBitMask* parameter contains the bits from the HD Audio controller device's stream status register that indicate the reason for the interrupt. The following table shows the meaning of the individual bits in *interruptBitMask*.

| Bit Numbers | Meaning |
| --- | --- |
| 31:5 | Unused. |
| 4 | Descriptor Error (DESE). If an error occurs during the fetch of a buffer descriptor, then the HD Audio controller sets the DESE bit to 1. |
| 3 | FIFO Error (FIFOE). If a FIFO error occurs (an overrun on an output stream or an underrun on an input stream), then the HD Audio controller sets the FIFOE bit to 1. |
| 2 | Buffer Completion Interrupt Status (BCIS). If the IOC bit is set to 1 in the command byte of the buffer descriptor, then the HD Audio controller sets the BCIS bit to 1 after the last sample of a buffer is processed. |
| 1:0 | Unused. |

The HD Audio bus driver sets the unused bits to zero. Instead of assuming that an IOC interrupt has occurred, the ISR must always check the *interruptBitMask* parameter to determine whether a stream error has occurred. For more information about the interrupt status bits shown in the preceding table, see the description of the stream status registers in the *Intel High Definition Audio Specification*.

The FIFO size is the maximum number of bytes that the DMA engine can hold in its internal buffer at any one time. Depending on the hardware implementation, a DMA engine's FIFO size can either be static or vary dynamically with changes in the stream format. For more information about the FIFO size, see the *Intel High Definition Audio Specification*.

The caller must allocate the buffer memory and BDL from the nonpaged pool.

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer)

[HDAUDIO_BUFFER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_buffer_descriptor)

[HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl)

[SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state)