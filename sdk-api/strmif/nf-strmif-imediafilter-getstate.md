# IMediaFilter::GetState

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetState** method retrieves the filter's state (running, stopped, or paused).

## Parameters

### `dwMilliSecsTimeout` [in]

Time-out interval, in milliseconds. To block indefinitely, use the value **INFINITE**.

### `State` [out]

Receives a member of the [FILTER_STATE](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-filter_state) enumerated type, indicating the filter's state.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_S_STATE_INTERMEDIATE** | Intermediate state. |
| **VFW_S_CANT_CUE** | The filter is active, but cannot deliver data. |

## Remarks

State transitions can be asynchronous. If the filter is transitioning to a new state, and the method times out before the transition completes, the method returns **VFW_S_STATE_INTERMEDIATE**.

If a filter cannot deliver data for some reason, it returns **VFW_S_CANT_CUE**. Live capture filters return this value while paused, because they do not deliver data in the paused state.

For more information, see [Data Flow in the Filter Graph](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-filter-graph).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter)

[IMediaFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediafilter)