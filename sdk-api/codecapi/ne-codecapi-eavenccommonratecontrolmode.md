# eAVEncCommonRateControlMode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the rate control mode for an encoder. This enumeration is used with the [AVEncCommonRateControlMode](https://learn.microsoft.com/windows/desktop/DirectShow/avenccommonratecontrolmode-property) codec property.

## Constants

### `eAVEncCommonRateControlMode_CBR:0`

Constant bit rate (CBR) encoding.

### `eAVEncCommonRateControlMode_PeakConstrainedVBR:1`

Constrained variable bit rate (VBR) encoding.

### `eAVEncCommonRateControlMode_UnconstrainedVBR:2`

Unconstrained VBR encoding.

### `eAVEncCommonRateControlMode_Quality:3`

Quality-based VBR encoding. The encoder selects the bit rate to match a specified quality level. To specify the quality level, set the [AVEncCommonQuality](https://learn.microsoft.com/windows/desktop/DirectShow/avenccommonquality-property) property.

### `eAVEncCommonRateControlMode_LowDelayVBR:4`

Low delay VBR encoding. H.264 extension.

Requires Windows 8.

### `eAVEncCommonRateControlMode_GlobalVBR:5`

Global VBR encoding. H.264 extension.

Requires Windows 8.

### `eAVEncCommonRateControlMode_GlobalLowDelayVBR:6`

Global low delay VBR encoding. H.264 extension.

Requires Windows 8.

## Remarks

This enumeration is also used with [H.264 UVC 1.5 camera encoders](https://learn.microsoft.com/windows/desktop/medfound/camera-encoder-h264-uvc-1-5).

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)