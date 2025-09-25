# VIDEOINFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VIDEOINFO** structure is equivalent to a [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure, but it contains enough memory to hold three color masks plus a color table with 256 colors.

If you are writing a video filter, you can use this structure to guarantee that the format block always has enough memory to contain the largest possible [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure.

## Members

### `rcSource`

Portion of the input video to use.

### `rcTarget`

Where the video should be displayed.

### `dwBitRate`

Approximate data rate in bits per second.

### `dwBitErrorRate`

Bit error rate for this stream.

### `AvgTimePerFrame`

The desired average time per frame, in 100-nanosecond units. For more information, see the Remarks section for the [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure.

### `bmiHeader`

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure that contains color and dimension information for a device-independent bitmap.

### `bmiColors`

Array of Win32 [RGBQUAD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgbquad) structures that specifies the video's color palette. Each structure represents a single color, which is a combination of red, green, and blue intensities.

### `dwBitMasks`

Array of **DWORD** values that specify true-color bitmasks.

### `TrueColorInfo`

[TRUECOLORINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-truecolorinfo) structure that contains both a color palette and an array of color bitmasks.

## Remarks

Never use this structure unless you are sure that you will use it only to store standard RGB formats. If you store anything other than standard RGB, the variable size of the **bmiHeader** structure will almost certainly cause problems, and you should use the [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure instead. If you find it absolutely necessary to use the **VIDEOINFO** structure, do not access the **TrueColorInfo**, **dwBitMasks**, or **bmiColors** members directly. Instead, use the [TRUECOLOR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd407230(v=vs.85)), [COLORS](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-colors), and [BITMASKS](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-bitmasks) macros to return the pointers to the color information. Which of these members is valid depends on the contents of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure.

The first five data members are equivalent to a [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure. They are expanded in full simply to reduce the amount of dereferencing needed when dealing with a pointer to a **VIDEOINFO** structure.

For information about using the **rcSource** and **rcTarget** members, see [Source and Target Rectangles in Video Renderers](https://learn.microsoft.com/windows/desktop/DirectShow/source-and-target-rectangles-in-video-renderers).

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)