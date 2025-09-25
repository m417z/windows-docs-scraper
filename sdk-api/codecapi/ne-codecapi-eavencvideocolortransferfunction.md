# eAVEncVideoColorTransferFunction enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the conversion function from R'G'B' to RGB. This enumeration is used with the [AVEncVideoInputColorTransferFunction](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideoinputcolortransferfunction-property) and [AVEncVideoOutputColorTransferFunction](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideooutputcolortransferfunction-property) properties.

## Constants

### `eAVEncVideoColorTransferFunction_SameAsSource:0`

Use the same function as the input video. This flag applies to the **AVEncVideoOutputColorTransferFunction** property only.

### `eAVEncVideoColorTransferFunction_10:1`

Linear RGB (gamma = 1.0).

### `eAVEncVideoColorTransferFunction_18:2`

True 1.8 gamma. L' = L^1/1.8.

### `eAVEncVideoColorTransferFunction_20:3`

True 2.0 gamma. L' = L^1/2.0..

### `eAVEncVideoColorTransferFunction_22:4`

True 2.2 gamma. L' = L^1/2.2..

### `eAVEncVideoColorTransferFunction_22_709:5`

Gamma 2.2 curve with a linear segment in the lower range. L' = 4.5L, for L < 0.018; L' = 1.099L^0.45.- 0.099, for L >= 0.018. This transfer function is used in BT-709, SMPTE 296M, SMPTE 170M, BT-470, and SPMTE 274M.

### `eAVEncVideoColorTransferFunction_22_240M:6`

Gamma 2.2 curve with a linear segment in the lower range. L' = 4.0L, for L < 0.0228; L' = 1.1115^L0.45.- 0.01115, for L >= 0.0228. This transfer function is used in SPMTE 240M.

### `eAVEncVideoColorTransferFunction_22_8bit_sRGB:7`

Gamma 2.4 curve with a linear segment in the lower range. L' = L/12.92, for L < 0.03928; L' = ((L + 0.055) / 1.055)^2.4., for L >= 0.03928.

### `eAVEncVideoColorTransferFunction_28:8`

True 2.8 gamma. L' = L^1/2.8..

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)