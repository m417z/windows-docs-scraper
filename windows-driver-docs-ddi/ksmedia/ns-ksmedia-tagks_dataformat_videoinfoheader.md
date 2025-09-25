# tagKS_DATAFORMAT_VIDEOINFOHEADER structure

## Description

The KS_DATAFORMAT_VIDEOINFOHEADER structure describes a video stream that does not include bob or weave settings.

## Members

### `DataFormat`

Specifies the data format.

### `VideoInfoHeader`

Specifies the details of the video stream.

## Remarks

This format is used for most capture output streams.

Minidrivers that must specify a data format that contains settings for bob or weave must use the [KS_DATAFORMAT_VIDEOINFOHEADER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_dataformat_videoinfoheader2) structure.

## See also

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)

[KS_DATAFORMAT_VIDEOINFOHEADER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_dataformat_videoinfoheader2)

[KS_VIDEOINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader)