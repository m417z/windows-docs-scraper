# eAVEncVideoColorPrimaries enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the color primaries of the video. This enumeration is used with the [AVEncVideoInputColorPrimaries](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideoinputcolorprimaries-property) and [AVEncVideoOutputColorPrimaries](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideooutputcolorprimaries-property) properties.

## Constants

### `eAVEncVideoColorPrimaries_SameAsSource:0`

Use the same primaries as the input video. This flag applies to the **AVEncVideoOutputColorPrimaries** property only.

### `eAVEncVideoColorPrimaries_Reserved:1`

Reserved. Do not use.

### `eAVEncVideoColorPrimaries_BT709:2`

ITU-R BT.709 (including sRGB and scRGB).

### `eAVEncVideoColorPrimaries_BT470_2_SysM:3`

ITU-R.BT.470-4 System M (NTSC).

### `eAVEncVideoColorPrimaries_BT470_2_SysBG:4`

ITU-R.BT.470-4 System B,G (NTSC).

### `eAVEncVideoColorPrimaries_SMPTE170M:5`

SMPTE 170M.

### `eAVEncVideoColorPrimaries_SMPTE240M:6`

SMPTE 240M.

### `eAVEncVideoColorPrimaries_EBU3231:7`

EBU 3213.

### `eAVEncVideoColorPrimaries_SMPTE_C:8`

SPMTE C (NTSC).

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)