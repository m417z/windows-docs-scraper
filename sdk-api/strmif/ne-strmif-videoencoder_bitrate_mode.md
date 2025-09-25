# VIDEOENCODER_BITRATE_MODE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VIDEOENCODER_BITRATE_MODE** enumeration type defines the three types of bitrates supported by the [IEncoderAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi) interface.

## Constants

### `ConstantBitRate:0`

The bit rate used for encoding is constant.

### `VariableBitRateAverage`

The bit rate used for encoding is variable with the specified bitrate used as a guaranteed average over a specified window. The default window size is considered to be five minutes.

### `VariableBitRatePeak`

The **ENCAPIPARAM_BITRATE** value is the expected (not guaranteed) average bit rate over a given time period and that the **ENCAPIPARAM_PEAK_BITRATE** value is the peak which the bit rate must not exceed. The default window size is considered to be 500ms (which is traditionally equal to one GOP).

## See also

[IEncoderAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi)