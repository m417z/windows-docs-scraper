# AM_LINE21_CCSERVICE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates the closed captioning service.

## Constants

### `AM_L21_CCSERVICE_None:0`

No current service.

### `AM_L21_CCSERVICE_Caption1`

CC1 (caption channel).

### `AM_L21_CCSERVICE_Caption2`

CC2 (caption channel).

### `AM_L21_CCSERVICE_Text1`

T1 (text channel).

### `AM_L21_CCSERVICE_Text2`

T2 (text channel)

### `AM_L21_CCSERVICE_XDS`

Extended Data Services (XDS or EDS).

### `AM_L21_CCSERVICE_DefChannel:10`

### `AM_L21_CCSERVICE_Invalid`

## Remarks

The Line 21 decoder supports CC1 and CC2 only.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMLine21Decoder::GetCurrentService](https://learn.microsoft.com/windows/desktop/api/il21dec/nf-il21dec-iamline21decoder-getcurrentservice)

[IAMLine21Decoder::SetCurrentService](https://learn.microsoft.com/windows/desktop/api/il21dec/nf-il21dec-iamline21decoder-setcurrentservice)