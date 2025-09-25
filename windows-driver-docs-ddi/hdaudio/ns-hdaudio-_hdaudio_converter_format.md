# _HDAUDIO_CONVERTER_FORMAT structure

## Description

The HDAUDIO_CONVERTER_FORMAT structure specifies the 16-bit encoded stream format for an input or output converter, as defined in the Intel High Definition Audio Specification (see the [Intel HD Audio](https://go.microsoft.com/fwlink/p/?linkid=42508) website).

## Members

Specifies the number of channels in the stream's data format. For more information, see the Remarks section.

### `NumberOfChannels`

Specifies the number of channels in the stream's data format. For more information, see the following Remarks section.

### `BitsPerSample`

Specifies the number of bits per sample. For more information, see the following Remarks section.

### `SampleRate`

Specifies the stream's sample rate. For more information, see the following Remarks section.

### `StreamType`

Specifies the stream type. If **StreamType**=0, the stream contains PCM data. If **StreamType**=1, the stream contains non-PCM data.

### `ConverterFormat`

Specifies the stream's data format as an encoded 16-bit value. For more information, see the following Remarks section.

## Remarks

For information about the encoding of the individual bitfields in the structure definition, see the discussion of the stream descriptor in the Intel High Definition Audio Specification at the [Intel HD Audio](https://go.microsoft.com/fwlink/p/?linkid=42508) website.

The HD Audio bus driver sets the unnamed bitfield in the structure definition to zero.

The [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine), [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine), and [ChangeBandwidthAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pchange_bandwidth_allocation) routines take as an input parameter an [HDAUDIO_STREAM_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_stream_format) structure and output the corresponding HDAUDIO_CONVERTER_FORMAT structure. The caller can use the output value to program the input or output converters.

Each valid HDAUDIO_CONVERTER_FORMAT encoding has a one-to-one correspondence to an HDAUDIO_STREAM_FORMAT structure that contains a valid set of parameters.

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[ChangeBandwidthAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pchange_bandwidth_allocation)

[HDAUDIO_STREAM_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_stream_format)