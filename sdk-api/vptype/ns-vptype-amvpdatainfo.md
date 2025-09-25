# AMVPDATAINFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AMVPDATAINFO** structure specifies the data-specific characteristics of the VP input stream.

## Members

### `dwSize`

Size of the structure, in bytes.

### `dwMicrosecondsPerField`

Time taken by each field.

### `amvpDimInfo`

Dimensional information.

### `dwPictAspectRatioX`

The X dimension of picture aspect ratio.

### `dwPictAspectRatioY`

The Y dimension of picture aspect ratio.

### `bEnableDoubleClock`

Video port should enable double clocking.

### `bEnableVACT`

Video port should use an external VACT signal.

### `bDataIsInterlaced`

Indicates that the signal is interlaced.

### `lHalfLinesOdd`

Number of half lines in the odd field.

### `bFieldPolarityInverted`

Video port should invert the field polarity.

### `dwNumLinesInVREF`

Number of lines of data in VREF.

### `lHalfLinesEven`

Number of half lines in the even field.

### `dwReserved1`

Reserved for future use.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)