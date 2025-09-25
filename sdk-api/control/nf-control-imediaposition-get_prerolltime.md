# IMediaPosition::get_PrerollTime

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_PrerollTime` method retrieves the amount of data that will be queued before the start position.

## Parameters

### `pllTime` [out]

Pointer to a variable that receives the preroll time, in seconds.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Not implemented. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

The *preroll* is the time prior to the start position at which nonrandom access devices, such as tape players, should start rolling.

If no filter in the graph implements this method, the Filter Graph Manager sets the value of **pllTime* to zero and returns S_OK.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaPosition Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaposition)