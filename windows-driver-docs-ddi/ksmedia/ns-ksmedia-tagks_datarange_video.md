# tagKS_DATARANGE_VIDEO structure

## Description

The KS_DATARANGE_VIDEO structure describes a range of video streams without bob or weave settings.

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

The KS_DATARANGE_VIDEO structure is used for two related purposes:

1. At minidriver initialization time, the minidriver returns an array of KS_DATARANGE_VIDEO structures exposing all the supported formats for a given pin, including possible cropping and scaling options.
2. When a particular format is selected by a user-mode client, the members (and their settings) of this structure determine whether a proposed format is supported by the minidriver. User-mode clients modify the contents of the **VideoInfoHeader** member but must leave all other members of KS_DATARANGE_VIDEO unchanged. The minidriver then verifies the requested parameters and returns a KS_DATAFORMAT_VIDEO structure. The minidriver then calculates members that are unique to the particular format requested.

For example, a stream that supports RGB16, RGB24, YVU9, and JPEG capture formats defines an array of four KS_DATAFORMAT_VIDEO structures.

## See also

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KS_VIDEOINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader)

[KS_VIDEO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ks_video_stream_config_caps)