# IDVSplitter::DiscardAlternateVideoFrames

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DiscardAlternateVideoFrames** method discards half of the frames in the video stream. For NTSC, the frame rate is reduced from 30 frames per second (fps) to 15 fps. For PAL, the frame rate is reduced from 25 fps to 12.5 fps.

## Parameters

### `nDiscard` [in]

Flag that specifies whether to discard frames. If the value is non-zero, the filter discards alternate frames. If the value is zero, the filter delivers every frame.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | Filter is paused or running. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDVSplitter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvsplitter)