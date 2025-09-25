# IPinConnection::IsEndPin

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `IsEndPin` method indicates whether a reconnection search should end at this pin.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | This pin is not a candidate for reconnection. (The reconnection search should not stop at this pin.) |
| **S_OK** | This pin is a candidate for reconnection. (The reconnection search should stop at this pin.) |

## Remarks

A filter or application can call this method to determine whether the pin is a candidate for dynamic reconnection.

Generally, a sink filter or a filter that splits or merges data should return S_OK. Other filters (for example, simple transform filters) should return S_FALSE.

## See also

[Dynamic Reconnection](https://learn.microsoft.com/windows/desktop/DirectShow/dynamic-reconnection)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPinConnection Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipinconnection)