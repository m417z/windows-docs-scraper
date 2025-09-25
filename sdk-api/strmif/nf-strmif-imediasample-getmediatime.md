# IMediaSample::GetMediaTime

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetMediaTime` method retrieves the media times for this sample.

## Parameters

### `pTimeStart` [out]

Pointer to a variable that receives the media start time.

### `pTimeEnd` [out]

Pointer to a variable that receives the media stop time.

## Return value

Returns an HRESULT value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_MEDIA_TIME_NOT_SET** | Media times are not set on this sample. |

## Remarks

For more information about media times, see [Time and Clocks in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/time-and-clocks-in-directshow).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSample Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample)