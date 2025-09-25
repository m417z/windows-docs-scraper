# IMediaSample::SetSyncPoint

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetSyncPoint` method specifies whether the beginning of this sample is a synchronization point.

## Parameters

### `bIsSyncPoint` [in]

Boolean value that specifies whether this is a synchronization point. If **TRUE**, this is a synchronization point.

## Return value

Returns S_OK or an **HRESULT** value indicating the cause of the error.

## Remarks

The filter that first generates the data in the sample should set this flag to **TRUE** or **FALSE**, as appropriate. For uncompressed video and PCM audio, set every sample to **TRUE**. For compressed video, set key frames to **TRUE** and delta frames to **FALSE**.

This flag is purely informational. Other filters downstream might check this flag; for example, a filter might need to skip to the next key frame.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSample Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample)

[IMediaSample::IsSyncPoint](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediasample-issyncpoint)