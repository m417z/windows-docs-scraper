# IAMWMBufferPass::SetNotify

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetNotify** method is used by applications to provide the WM ASF Writer or [WM ASF Reader](https://learn.microsoft.com/windows/desktop/wmformat/wm-asf-reader-filter) filter with a pointer to the application's [IAMWMBufferPassCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd798277(v=vs.85)) interface.

## Parameters

### `pCallback` [in]

Pointer to the application's **IAMWMBufferPassCallback** interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

Call this method before putting the filter graph into the run state.

## See also

[IAMWMBufferPass Interface](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd798276(v=vs.85))