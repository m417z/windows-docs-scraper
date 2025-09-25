# IVPManager::SetVideoPortIndex

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetVideoPortIndex` method instructs the Video Port Manager (VPM) to connect to the specified video port.

## Parameters

### `dwVideoPortIndex` [in]

Double word containing the video port index.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Use this method on a multi-monitor system to specify to the Video Port Manager which video port index is being used.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVPManager Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivpmanager)

[IVPManager::GetVideoPortIndex](https://learn.microsoft.com/windows/win32/api/strmif/nf-strmif-ivpmanager-getvideoportindex)