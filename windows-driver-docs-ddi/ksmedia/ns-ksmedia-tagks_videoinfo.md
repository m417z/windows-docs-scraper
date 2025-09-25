# tagKS_VIDEOINFO structure

## Description

The KS_VIDEOINFO structure describes the bitmap and color information for a video stream.

## Members

### `rcSource`

Specifies a clipping rectangle that selects the portion of the active video signal to use.

### `rcTarget`

Specifies a rectangle that indicates which part of the target buffer to use.

### `dwBitRate`

Specifies a value that indicates the video stream's approximate data rate, in bits per second.

### `dwBitErrorRate`

Specifies a value that indicates the video stream's data error rate, in bit errors per second.

### `AvgTimePerFrame`

Specifies the average time per frame in 100-nanosecond units.

### `bmiHeader`

Describes a [KS_BITMAPINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_bitmapinfoheader) structure that contains color and dimension information about the video image bitmap.

### `bmiColors`

Array of KS_RGBQUAD structures that specifies the video's color palette. Each structure represents a single color, which is a combination of red, green, and blue intensities.

### `dwBitMasks`

Array of DWORD values that specify true-color bitmasks.

### `TrueColorInfo`

[KS_TRUECOLORINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tag_ks_truecolorinfo) structure that contains both a color palette and an array of color bitmasks.

## Remarks

This structure must not be used unless the **biSize** member of the KS_BITMAPINFOHEADER member is set to **sizeof**(KS_BITMAPINFOHEADER).

A source filter can request that the sink filter take only a section of the video by providing values that effectively define a clipping rectangle in the **rcSource** member. However, if the sink filter does not check for the clipping rectangle on connection, the sink filter simply renders all of the video, effectively ignoring any clipping information passed from the source filter to the sink filter.

Ideally, a sink filter checks **rcSource** and if the sink filter does not support image extraction and the rectangle is *not* empty, then it rejects the connection. A filter should use the Win32 function **SetRectEmpty** to reset a rectangle to all zeros (and **IsRectEmpty** to later check the rectangle).

The **rcTarget** member specifies the destination rectangle for the video. Most source filters set this member to all zeros. A downstream filter can request that the video be placed in a particular area of the buffers it supplies. In this case, it calls the Win32 function **QueryAccept** with a nonempty target.

## See also

[KS_BITMAPINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_bitmapinfoheader)

[KS_RGBQUAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_rgbquad)

[KS_TRUECOLORINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tag_ks_truecolorinfo)