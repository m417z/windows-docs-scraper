# IMediaStreamFilter::GetCurrentStreamTime

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The **GetCurrentStreamTime** method retrieves the current stream time.

## Parameters

### `pCurrentStreamTime` [out]

Pointer to a variable that receives the stream time, in 100-nanosecond units.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **S_FALSE** | The graph is not running, or there is no reference clock. |
| **S_OK** | Success. |

## Remarks

Stream time is defined only when the graph is running and has a reference clock. Otherwise, **pCurrentStreamTime* is set to zero and the method returns S_FALSE.

## See also

[IMediaStreamFilter Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-imediastreamfilter)