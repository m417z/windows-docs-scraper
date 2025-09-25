# tagKS_MPEG1VIDEOINFO structure

## Description

The KS_MPEG1VIDEOINFO structure describes an MPEG-1 video stream.

## Members

### `hdr`

Specifies a [KS_VIDEOINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader) structure that describes the details of the video stream.

### `dwStartTimeCode`

A 25-bit "group-of-pictures" time code at the start of data.

### `cbSequenceHeader`

The length of the **bSequenceHeader** member, in bytes.

### `bSequenceHeader`

The length of the **bSequenceHeader** member, in bytes.

## See also

[KS_VIDEOINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader)