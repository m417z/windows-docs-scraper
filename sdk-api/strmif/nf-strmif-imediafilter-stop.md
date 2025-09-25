# IMediaFilter::Stop

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Stop` method stops the filter.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Transition is not complete. |
| **S_OK** | Success. Transition is complete. |

## Remarks

When a filter is stopped, it does not process or deliver any samples, and it rejects samples from upstream filters.

The state transition might be asynchronous. If the method returns before the transition completes, the return value is S_FALSE.

This method always sets the filter's state to State_Stopped, even if the method returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[FILTER_STATE Enumeration](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-filter_state)

[IMediaFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediafilter)