# IVPNotify2::SetVPSyncMaster

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetVPSyncMaster` method sets whether the video port controls vertical synchronization of the VGA.

## Parameters

### `bVPSyncMaster` [in]

Value specifying whether the video port controls the vertical synchronization of the VGA monitor. **TRUE** if the port controls the monitor's synchronization; **FALSE** otherwise.

## Return value

Returns an **HRESULT** value.

## Remarks

Include Vptype.h before Vpnotify.h.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVPNotify2 Interface](https://learn.microsoft.com/windows/desktop/api/vpnotify/nn-vpnotify-ivpnotify2)