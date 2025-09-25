# IMediaSample::SetMediaTime

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetMediaTime` method sets the media times for this sample.

## Parameters

### `pTimeStart` [in]

Pointer to the beginning media time.

### `pTimeEnd` [in]

Pointer to the ending media time.

## Return value

Returns S_OK, or an **HRESULT** value indicating the cause of the error.

## Remarks

To invalidate the media time, set *pTimeStart* and *pTimeEnd* to **NULL**. This will cause the [IMediaSample::GetMediaTime](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediasample-getmediatime) method to return VFW_E_MEDIA_TIME_NOT_SET.

For more information about media times, see [Time Stamps](https://learn.microsoft.com/windows/desktop/DirectShow/time-stamps).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSample Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample)