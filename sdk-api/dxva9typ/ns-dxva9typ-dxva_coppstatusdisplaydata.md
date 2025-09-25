# DXVA_COPPStatusDisplayData structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains the result of a Display Data query in Certified Output Protection Protocol (COPP).

## Members

### `rApp`

A 128-bit random number that was passed by the application in the [AMCOPPStatusInput](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-amcoppstatusinput) structure.

### `dwFlags`

Status flag. See [COPP_StatusFlags](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ne-dxva9typ-copp_statusflags).

### `DisplayWidth`

Width of the display mode, in pixels.

### `DisplayHeight`

Height of the display mode, in pixels.

### `Format`

Contains a **DXVA_ExtendedFormat** structure packed into a **ULONG**, describing the video format.

### `d3dFormat`

Contains a **D3DFORMAT** value that describes the video format. For more information, see the Direct3D SDK documentation.

### `FreqNumerator`

The numerator of the refresh rate of the current display mode.

### `FreqDenominator`

The denominator of the refresh rate of the current display mode.

## Remarks

The refresh rate is expressed as a fraction. For example, if the refresh rate is 72 Hz, **FreqNumerator** = 72 and **FreqDenominator** = 1. For NTSC television, the values are **FreqNumerator** = 60000 and **FreqDenominator** = 1001 (59.94 fields per second).

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)