# PALLOCATE_RENDER_DMA_ENGINE callback function

## Description

The `AllocateRenderDmaEngine` routine allocates a DMA engine for a render stream.

The function pointer type for an `AllocateRenderDmaEngine` routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** members of the [HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface),[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2), or [HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl) structures.

### `StreamFormat` [in]

Specifies the requested stream format. This parameter points to a caller-allocated structure of type [HDAUDIO_STREAM_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_stream_format) that specifies a data format for the stream.

### `Stripe` [in]

Specifies whether to enable striping. If **TRUE**, the routine enables striping in the DMA transfers. If **FALSE**, striping is disabled.

### `Handle` [out]

Retrieves the handle to the DMA engine. This parameter points to a caller-allocated HANDLE variable into which the routine writes a handle that identifies the DMA engine.

### `ConverterFormat` [out]

Retrieves the converter format. This parameter points to a caller-allocated structure of type [HDAUDIO_CONVERTER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_converter_format) into which the routine writes the encoded format.

## Return value

`AllocateRenderDmaEngine` returns STATUS_SUCCESS if the call succeeds in reserving a DMA engine. Otherwise, the routine returns an appropriate error code. The following table shows some of the possible return error codes.

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | Indicates that the DMA engine is unable to allocate sufficient internal FIFO storage to support the requested stream format. |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates that either no DMA engine is available or the request exceeds the available bandwidth resources. |
| **STATUS_INVALID_PARAMETER** | Indicates that one of the parameter values is incorrect (invalid parameter value or bad pointer). |

## Remarks

This routine allocates a render DMA engine and specifies the data format for the stream. If successful, the routine outputs a handle that the caller subsequently uses to identify the DMA engine.

The `AllocateRenderDmaEngine` routine reserves hardware resources (the DMA engine) but does not configure the DMA hardware. After calling this routine to reserve a DMA engine, a function driver must assign a DMA buffer to the DMA engine and configure the engine to use the buffer:

* If using the HDAUDIO_BUS_INTERFACE version of the HD Audio DDI, the function driver calls the [AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer) routine to have the HD Audio bus driver allocate a data buffer for DMA transfers and set up the DMA engine to use the buffer.
* If using the HDAUDIO_BUS_INTERFACE_BDL version of the DDI, the function driver calls [AllocateContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_contiguous_dma_buffer) to allocate the DMA buffer and calls the [SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl) routine to set up the DMA engine to use the buffer.

The *streamFormat* parameter specifies the data format for the capture stream. Following the call to `AllocateRenderDmaEngine`, the stream's format can be changed by calling [ChangeBandwidthAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pchange_bandwidth_allocation).

The *stripe* parameter specifies whether the DMA engine is to use striping to speed up data transfers. For more information, see [Striping](https://learn.microsoft.com/windows-hardware/drivers/audio/striping).

Through the handle parameter, the routine outputs a handle that the caller uses to identify the allocated DMA engine in subsequent calls to **AllocateDmaBuffer**, **ChangeBandwidthAllocation**, [FreeDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_buffer), **SetupDmaEngineWithBdl**, and [SetDmaEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pset_dma_engine_state). The function driver frees the handle by calling [FreeDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_engine).

Through the *converterFormat* parameter, the routine outputs a stream descriptor value that the caller can use to program the output converters. The routine encodes the information from the *streamFormat* parameter into a 16-bit integer. For more information, see [HDAUDIO_CONVERTER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_converter_format).

Immediately following a successful call to `AllocateRenderDmaEngine`, the DMA engine is in the reset stream state. Before calling **SetDmaEngineState** to change the DMA engine to the running, paused, or stopped state, the client must first allocate a DMA buffer for the engine.

A WDM audio driver calls `AllocateRenderDmaEngine` at pin-creation time during execution of its **NewStream** method (for example, see [IMiniportWavePci::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-newstream)).

## See also

[AllocateDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer)

[ChangeBandwidthAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pchange_bandwidth_allocation)

[FreeDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pfree_dma_engine)

[HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface)

[HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)

[HDAUDIO_CONVERTER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_converter_format)

[HDAUDIO_STREAM_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_stream_format)

[IMiniportWavePci::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-newstream)