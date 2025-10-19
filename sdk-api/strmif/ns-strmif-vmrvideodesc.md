# VMRVideoDesc structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

This topic applies to Windows XP Service Pack 1 or later.

The `VMRVideoDesc` structure describes a video stream to be deinterlaced.

## Members

### `dwSize`

Size of the structure, in bytes.

### `dwSampleWidth`

Width of the video to be deinterlaced, in pixels.

### `dwSampleHeight`

Height of the video to be deinterlaced, in pixels.

### `SingleFieldPerSample`

Specifies one of the following values.

| Value | Meaning |
| --- | --- |
| **TRUE** | Each field is delivered as a separate sample. |
| **FALSE** | Pairs of fields are combined into single samples. |

### `dwFourCC`

Specifies a FOURCC code. Valid values include NV12, YV12, YUY2, UYVY, IMC1, IMC2, IMC3 and IMC4

### `InputSampleFreq`

A [VMRFrequency](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-vmrfrequency) structure that specifies the input frequency. For NTSC TV, the frequency would be expressed as 30,000:1001.

### `OutputFrameFreq`

A [VMRFrequency](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-vmrfrequency) structure that specifies the output frequency. For NTSC TV, the frequency would be expressed as 60,000:1001.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)