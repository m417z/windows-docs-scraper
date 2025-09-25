# tagKS_DATARANGE_VIDEO2 structure

## Description

The KS_DATARANGE_VIDEO2 structure describes a video stream including bob or weave settings.

## Members

### `DataRange`

Specifies the major identifier for the format.

### `bFixedSizeSamples`

Specifies that all the samples are the same size if set to **TRUE**.

### `bTemporalCompression`

Specifies whether each sample can stand independently on its own, without relying on previous or future samples.

### `StreamDescriptionFlags`

Unused and should be set to zero.

### `MemoryAllocationFlags`

Unused and should be set to zero.

### `ConfigCaps`

Specifies the configuration of the stream, including scaling, cropping, and frame and data rates.

### `VideoInfoHeader`

Specifies the details of the video stream.

## Remarks

This structure should be used instead of a [KS_DATARANGE_VIDEO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_datarange_video) structure when a minidriver must describe content with bob or weave settings.

## See also

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KS_VIDEOINFOHEADER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader2)

[KS_VIDEO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ks_video_stream_config_caps)