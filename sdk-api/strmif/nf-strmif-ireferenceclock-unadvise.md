# IReferenceClock::Unadvise

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Unadvise` method removes a pending advise request.

## Parameters

### `dwAdviseCookie` [in]

Identifier of the request to remove. Use the value returned by [IReferenceClock::AdviseTime](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ireferenceclock-advisetime) or [IReferenceClock::AdvisePeriodic](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ireferenceclock-adviseperiodic) in the *pdwAdviseToken* parameter.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Not found. |
| **S_OK** | Success. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IReferenceClock Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ireferenceclock)