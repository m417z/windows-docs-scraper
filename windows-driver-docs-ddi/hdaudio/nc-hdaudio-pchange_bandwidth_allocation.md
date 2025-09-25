# PCHANGE_BANDWIDTH_ALLOCATION callback function

## Description

The `ChangeBandwidthAllocation` routine changes a DMA engine's bandwidth allocation on the HD Audio Link.

The function pointer type for a `ChangeBandwidthAllocation` routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** member of the [HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface), [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2), or [HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl) structure.

### `Handle` [in]

Handle identifying the DMA engine. This handle value was obtained from a previous call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine).

### `StreamFormat` [in]

Specifies the requested stream format. This parameter points to a caller-allocated structure of type [HDAUDIO_STREAM_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_stream_format) that specifies a data format for the stream.

### `ConverterFormat` [out]

Retrieves the converter format. This parameter points to a caller-allocated structure of type [HDAUDIO_CONVERTER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_converter_format) into which the routine writes the encoded format. For more information, see the following Remarks section.

## Return value

`ChangeBandwidthAllocation` returns STATUS_SUCCESS if the call succeeds. Otherwise, the routine returns an appropriate error code. The following table shows some of the possible return error codes.

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | Indicates that the caller is running at an IRQL that is too high. |
| **STATUS_INVALID_HANDLE** | Indicates that the *handle* parameter value is invalid. |
| **STATUS_INVALID_PARAMETER** | Indicates that one of the parameter values is not correct (bad pointer or invalid stream format). |
| **STATUS_BUFFER_TOO_SMALL** | Indicates that the DMA engine is unable to allocate sufficient internal FIFO storage to support the requested stream format. |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates that insufficient bandwidth is available to satisfy the request. |
| **STATUS_INVALID_DEVICE_REQUEST** | Indicates that the stream is not in the reset state or that a buffer is still allocated for the DMA engine. |

## Remarks

The caller obtains an initial bandwidth allocation for a DMA engine by calling [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine). Thereafter, the caller can change the bandwidth allocation by calling `ChangeBandwidthAllocation`.

Through the *converterFormat* parameter, the routine outputs a stream descriptor value that the caller can use to program the input or output converters. The routine encodes the information from the *streamFormat* parameter into a 16-bit integer. For more information, see [HDAUDIO_CONVERTER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_converter_format).

This routine fails and returns error code STATUS_INVALID_DEVICE_REQUEST in either of the following circumstances:

* Any previously allocated DMA buffer has not been freed (by calling [FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer) or [FreeContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_contiguous_dma_buffer)).
* The stream is in a state other than reset.

If the `ChangeBandwidthAllocation` call fails, the existing bandwidth reservation remains in effect. The bandwidth allocation changes only if the call succeeds.

In Windows Vista and later, a wave miniport driver calls this routine during execution of its **SetFormat** method (after calling one of the Allocate*Xxx*DmaEngine routines in the HD Audio DDI). For more information, see [IMiniportWavePciStream::SetFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-setformat).

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[FreeContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_contiguous_dma_buffer)

[FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer)

[HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface)

[HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)

[HDAUDIO_CONVERTER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_converter_format)

[HDAUDIO_STREAM_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_stream_format)

[IMiniportWavePciStream::SetFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-setformat)