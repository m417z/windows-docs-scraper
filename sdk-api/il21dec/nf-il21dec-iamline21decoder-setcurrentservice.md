# IAMLine21Decoder::SetCurrentService

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetCurrentService` method sets the closed captioning service.

## Parameters

### `Service`

Member of the [AM_LINE21_CCSERVICE](https://learn.microsoft.com/previous-versions/windows/desktop/api/il21dec/ne-il21dec-am_line21_ccservice) enumeration that specifies the closed captioning service. The default service is CC1.

## Return value

| Value | Description |
| --- | --- |
| E_INVALIDARG | Invalid argument |
| E_NOTIMPL | The requested service is not implemented. |
| S_OK | Success |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMLine21Decoder Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/il21dec/nn-il21dec-iamline21decoder)

[IAMLine21Decoder::GetCurrentService](https://learn.microsoft.com/windows/desktop/api/il21dec/nf-il21dec-iamline21decoder-getcurrentservice)