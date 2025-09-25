# _HDAUDIO_STREAM_FORMAT structure

## Description

The HDAUDIO_STREAM_FORMAT structure describes the data format of a capture or render stream.

## Members

### `SampleRate`

Specifies the sample rate in samples per second. This member indicates the rate at which each channel should be played or recorded.

### `ValidBitsPerSample`

Specifies the number of valid bits per sample. The valid bits are left justified within the container. Any unused bits to the right of the valid bits must be set to zero.

### `ContainerSize`

Specifies the size in bits of a sample container. Valid values for this member are 8, 16, 24, and 32.

### `NumberOfChannels`

Specifies the number of channels of audio data. For monophonic audio, set this member to 1. For stereo, set this member to 2.

## Remarks

The [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine), [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine), and [ChangeBandwidthAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pchange_bandwidth_allocation) routines take as an input parameter an HDAUDIO_STREAM_FORMAT structure and output the corresponding [HDAUDIO_CONVERTER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_converter_format) structure. The information in a valid HDAUDIO_STREAM_FORMAT value can be encoded as an HDAUDIO_CONVERTER_FORMAT value.

This structure is similar to the [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-waveformatextensible) structure, but it omits certain parameters that are in WAVEFORMATEXTENSIBLE but are not relevant to the task of managing codecs that are connected to an HD Audio controller.

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[ChangeBandwidthAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pchange_bandwidth_allocation)

[HDAUDIO_CONVERTER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_converter_format)