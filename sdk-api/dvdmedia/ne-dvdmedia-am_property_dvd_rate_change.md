# AM_PROPERTY_DVD_RATE_CHANGE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AM_PROPERTY_DVD_RATE_CHANGE** enumeration is not used.

## Constants

### `AM_RATE_ChangeRate:1`

Reserved.

### `AM_RATE_FullDataRateMax:2`

Reserved.

### `AM_RATE_ReverseDecode:3`

Reserved.

### `AM_RATE_DecoderPosition:4`

Reserved.

### `AM_RATE_DecoderVersion:5`

Reserved.

## Remarks

This enumeration is defined in dvdmedia.h but was never used. It is included here for the sake of completeness. For DVD rate-change control, use the [Rate Change Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/rate-change-property-set).

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)