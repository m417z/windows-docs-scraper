# VIDEOINFOHEADER structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VIDEOINFOHEADER** structure describes the bitmap and color information for a video image.

## Members

### `rcSource`

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the source video window. This structure can be a clipping rectangle, to select a portion of the source video stream.

### `rcTarget`

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the destination video window.

### `dwBitRate`

Approximate data rate of the video stream, in bits per second.

### `dwBitErrorRate`

Data error rate, in bit errors per second.

### `AvgTimePerFrame`

The desired average display time of the video frames, in 100-nanosecond units. The actual time per frame may be longer. See Remarks.

### `bmiHeader`

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure that contains color and dimension information for the video image bitmap. If the format block contains a color table or color masks, they immediately follow the **bmiHeader** member. You can get the first color entry by casting the address of member to a **BITMAPINFO** pointer.

When used inside a **VIDEOINFOHEADER** structure, the semantics of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure differ slightly from how the structure is used in GDI. For more information, refer to the topic [BITMAPINFOHEADER Structure](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader).

## Remarks

For information about using the **rcSource** and **rcTarget** members, see [Source and Target Rectangles in Video Renderers](https://learn.microsoft.com/windows/desktop/DirectShow/source-and-target-rectangles-in-video-renderers).

### Frame Rates

The value of **AvgTimePerFrame** is usually set by the source filter, which obtains the value from the media stream. This value can be used to calculate the authored frame rate, which is the intended frame rate for the video to be rendered. During playback, the system may not be able to render the stream at the authored rate, so the actual frame rate may be less. This can happen if the machine's resources become over-committed. Also, the monitor's refresh rate can interfere with the playback rate of the video. For example, if the intended rate is 60,000/1001 (NTSC TV) and the monitor's refresh rate is 60Hz, the intended rate and the actual rate will never match. To retrieve the actual frame rate achieved during playback, use the [IQualProp::get_AvgFrameRate](https://learn.microsoft.com/previous-versions/ms786607(v=vs.85)) method on the video renderer.

During playback, applications can retrieve the authored frame rate as follows:

* If the old [Video Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/video-renderer-filter) filter is rendering, call the [IBasicVideo::get_AvgTimePerFrame](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicvideo-get_avgtimeperframe) method.
* If the Video Mixing Renderer (VMR) is rendering, call [IPin::ConnectionMediaType](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-connectionmediatype) on the input pin and examine the format block. The VMR supports multiple input streams, and they are not required to have the same frame rates.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)