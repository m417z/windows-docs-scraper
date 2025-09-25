# tagKS_DATARANGE_IMAGE structure

## Description

Specifies an image data range that is used in the [KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor) structure that describes a pin (or stream).

## Members

### `DataRange`

A [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structure that specifies the data range supported by this pin type.

### `ConfigCaps`

A [KS_VIDEO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ks_video_stream_config_caps) structure that specifies the configuration of the stream, including scaling, cropping, and frame and data rates.

### `ImageInfoHeader`

A [KS_BITMAPINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_bitmapinfoheader) structure that specifies image color and dimension information that the still image capture stream would provide.

## See also

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor)

[KS_BITMAPINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_bitmapinfoheader)

[KS_VIDEO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ks_video_stream_config_caps)