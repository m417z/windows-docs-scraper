# VIDEO_STREAM_CONFIG_CAPS structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VIDEO_STREAM_CONFIG_CAPS** structure describes a range of video formats. Video compression and video capture filters use this structure to describe what formats they can produce.

**Note** Most of this structure is deprecated, with the exception of the following structure members:

* **guid**
* **VideoStandard**
* **MinFrameInterval**
* **MaxFrameInterval**

Applications can use **MinFrameInterval** and **MaxFrameInterval** to get the range of supported frame rates from a video capture device. Applications should avoid using any of the other members of this structure. Instead, use the [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure returned by the [IAMStreamConfig::GetFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-getformat) method.

## Members

### `guid`

**GUID** that identifies the format type. For example, **FORMAT_VideoInfo** or **FORMAT_VideoInfo2**. For more information, see the **formattype** member of the [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure.

### `VideoStandard`

The analog video standard supported. The value is a bitwise combination of flags from the [AnalogVideoStandard](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-analogvideostandard) enumeration type, or zero.

### `InputSize`

Native size of the incoming video signal. For a compressor, the size is taken from the input pin. For a capture filter, the size is the largest signal the filter can digitize with every pixel remaining unique.

**Note** Deprecated.

### `MinCroppingSize`

Smallest source rectangle allowed. The source rectangle is defined in the **rcSource** member of the [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) or [VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2) structure.

**Note** Deprecated.

### `MaxCroppingSize`

Largest source rectangle allowed.

**Note** Deprecated.

### `CropGranularityX`

Horizontal granularity of the source rectangle. This value specifies the increments that are valid between **MinCroppingSize** and **MaxCroppingSize**.

**Note** Deprecated.

### `CropGranularityY`

Vertical granularity of the source rectangle. This value specifies the increments that are valid between **MinCroppingSize** and **MaxCroppingSize**.

**Note** Deprecated.

### `CropAlignX`

Required horizontal alignment of the source rectangle.

**Note** Deprecated.

### `CropAlignY`

Required vertical alignment of the source rectangle.

**Note** Deprecated.

### `MinOutputSize`

Minimum output size.

**Note** Deprecated.

### `MaxOutputSize`

Maximum output size.

**Note** Deprecated.

### `OutputGranularityX`

Granularity of the output width. This value specifies the increments that are valid between **MinOutputSize** and **MaxOutputSize**.

**Note** Deprecated.

### `OutputGranularityY`

Granularity of output height. This value specifies the increments that are valid between **MinOutputSize** and **MaxOutputSize**.

**Note** Deprecated.

### `StretchTapsX`

Indicates how well the filter can stretch the image horizontally.

**Note** Deprecated.

### `StretchTapsY`

Indicates how well the filter can stretch the image vertically.

**Note** Deprecated.

### `ShrinkTapsX`

Indicates how well the filter can shrink the image horizontally.

**Note** Deprecated.

### `ShrinkTapsY`

Indicates how well the filter can shrink the image vertically.

**Note** Deprecated.

The previous four structure members use the following values:

| Value | Meaning |
| --- | --- |
| **0** | Does not support stretching/shrinking. |
| **1** | Uses pixel doubling (stretching) or eliminates pixels (shrinking) |
| **2** | Uses interpolation (2 taps) |
| **3 and higher** | Uses interpolation (>2 taps) |

### `MinFrameInterval`

The minimum frame duration, in 100-nanosecond units. This value applies only to capture filters.

### `MaxFrameInterval`

The maximum frame duration, in 100-nanosecond units. This value applies only to capture filters.

### `MinBitsPerSecond`

Minimum data rate this pin can produce.

**Note** Deprecated.

### `MaxBitsPerSecond`

Maximum data rate this pin can produce.

**Note** Deprecated.

## Remarks

The [IAMStreamConfig::GetStreamCaps](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-getstreamcaps) method returns this structure. An application can use this information to modify the output format on a video compression filter or video capture filter.

For example, assume that filter returns the following values for the source rectangle:

* MinCroppingSize = (160, 120)
* MaxCroppingSize = (320, 240)
* CropGranularityX = 4
* CropGranularityY = 8
* CropAlignX = 2
* CropAlignY = 4

These numbers define the set of rectangles that are valid for the **rcSource** member of the [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) or [VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2) structure. In this example, the minimum source rectangle is 160 pixels wide x 120 pixels high. The width can be increased in steps of 4 pixels, to a maximum of 320. The height can be increased in steps of 8 pixels, to a maximum of 240. In other words, the valid widths are 160, 164, 168 ... 320; and the valid heights are 120, 128, 136 ... 240.

The **CropAlignX** and **CropAlignY** members define where the top-left corner of the source rectangle can sit. For example, the following rectangles are valid, given the previous values:

* (0, 0, 160, 120)
* (2, 0, 162, 120)
* (2, 8, 162, 128)

In a similar way, the **MinOutputSize**, **MaxOutputSize**, **OutputGranularityX**, and **OutputGranularityY** members define what values are supported for the **biWidth** and **biHeight** members of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure.

For capture filters, the **MinFrameInterval** and **MaxFrameInterval** members define the minimum and maximum duration of each frame, as given in the **AvgTimePerFrame** member of the [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) or [VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2) structure. The filter may not support every frame rate that falls between these two values. The [IAMStreamConfig::SetFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-setformat) method will set the frame rate to the closest value that the filter supports. If **SetFormat** succeeds, call [IAMStreamConfig::GetFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-getformat) to determine the actual frame rate.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)