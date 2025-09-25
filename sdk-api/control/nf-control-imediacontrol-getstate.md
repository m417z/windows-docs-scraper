# IMediaControl::GetState

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetState` method retrieves the state of the filter graph—paused, running, or stopped.

State transitions are not necessarily synchronous. Therefore, when you call this method, the filter graph might be in transition to a new state. In that case, the method blocks until the transition completes or until the specified time-out elapses.

## Parameters

### `msTimeout` [in]

Duration of the time-out, in milliseconds, or INFINITE to specify an infinite time-out.

### `pfs` [out]

Receives a member of the [FILTER_STATE](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-filter_state) enumeration.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_S_STATE_INTERMEDIATE** | The filter graph is still in transition to the indicated state. |
| **VFW_S_CANT_CUE** | The filter graph is paused, but cannot cue data. |
| **E_FAIL** | Failure. |

## Remarks

Applications can use this method to determine whether playback has started after a call to [IMediaControl::Run](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-run). Generally, applications should have their own mechanism for tracking which state they have put the filter graph into. Applications typically use the current state to determine which user interface controls are enabled or disabled. For example, once the graph goes into the running state, the application might disable a "Play" button and enable "Stop" and "Pause" buttons.

If the filter graph is in a transition to a new state, the returned state is the new state, not the previous state.

This method returns an error if there is a call on another thread to change the state while this method is blocked.

Avoid specifying a time-out of INFINITE, because threads cannot process messages while waiting in `GetState`. If you call `GetState` from the thread that processes Windows messages, specify small wait times on the call in order to remain responsive to user input. This is especially important when the source is streaming over a network or from the Internet because state transitions in these environments can take significantly more time to complete.

The [FILTER_STATE](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-filter_state) enumeration. You can cast the variable as follows:

```cpp

FILTER_STATE fs;
hr = pControl->GetState(msTimeOut, (OAFilterState*)&fs);

```

For more information about filter graph states, see [Filter States](https://learn.microsoft.com/windows/desktop/DirectShow/filter-states).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaControl Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediacontrol)