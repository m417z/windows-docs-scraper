# IAMWstDecoder::GetHoldPage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Downstream filters use the `GetHoldPage` method to determine whether the current WST page is held. When the WST decoder holds a page, any updates from the TV stream are turned off. It is though the page was paused in real time.

## Parameters

### `pbHoldPage` [out]

Pointer to a **BOOL** to receive the status of the WST page.

| Value | Description |
| --- | --- |
| **TRUE** | The current page is held. |
| **FALSE** | The current page is not held. |

## Return value

When the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMWstDecoder Interface](https://learn.microsoft.com/windows/desktop/api/iwstdec/nn-iwstdec-iamwstdecoder)