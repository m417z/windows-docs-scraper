# tagKS_DATARANGE_VIDEO_VBI structure

## Description

The KS_DATARANGE_VIDEO_VBI structure describes a range of data formats containing vertical blanking interval (VBI) data.

## Members

### `DataRange`

Specifies major, minor, and specifier identifiers of the range of formats being described.

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

### `VBIInfoHeader`

Indicates VBI-specific information for the range of formats being described.

## See also

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KS_VBIINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_vbiinfoheader)

[KS_VIDEO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ks_video_stream_config_caps)