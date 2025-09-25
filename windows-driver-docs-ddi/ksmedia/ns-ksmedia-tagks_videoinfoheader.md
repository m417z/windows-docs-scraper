# tagKS_VIDEOINFOHEADER structure

## Description

The KS_VIDEOINFOHEADER structure describes the bitmap and color information for a video stream.

## Members

### `rcSource`

Specifies a clipping rectangle that selects the portion of the active video signal to use.

### `rcTarget`

Specifies a rectangle that defines the target destination video window.

### `dwBitRate`

Specifies a value that indicates the video stream's approximate data rate, in bits per second.

### `dwBitErrorRate`

Specifies a value that indicates the video stream's data error rate, in bit errors per second.

### `AvgTimePerFrame`

Specifies the average time per frame, in 100-nanosecond units.

### `bmiHeader`

Describes a [KS_BITMAPINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_bitmapinfoheader) structure that contains color and dimension information about the video image bitmap.

## Remarks

To describe a video stream with bob or weave settings, use [KS_VIDEOINFOHEADER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader2).

The KS_VIDEOINFOHEADER structure is identical to the Microsoft DirectShow VIDEOINFOHEADER structure.

A source filter can request that the sink filter take only a section of the video by providing values that effectively define a clipping rectangle in the **rcSource** member. However, if the sink filter does not check for the clipping rectangle on connection, the sink filter simply renders all of the video, effectively ignoring any clipping information passed from the source filter to the sink filter.

Ideally, a sink filter checks **rcSource** and if the sink filter does not support image extraction, and the rectangle is *not* empty, then it rejects the connection. A filter should use the Win32 function **SetRectEmpty** to reset a rectangle to all zeros (and set **IsRectEmpty** to later check the rectangle).

The **rcTarget** member specifies the destination rectangle for the video. Most source filters set this member to all zeros. A downstream filter can request that the video be placed in a particular area of the buffers that it supplies. In this case, it calls the Win32 function **QueryAccept** with a nonempty target.

## See also

[KS_BITMAPINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_bitmapinfoheader)

[KS_VIDEOINFOHEADER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader2)