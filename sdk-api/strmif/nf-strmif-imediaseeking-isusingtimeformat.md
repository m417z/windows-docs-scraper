# IMediaSeeking::IsUsingTimeFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `IsUsingTimeFormat` method determines whether seek operations are currently using a specified time format.

## Parameters

### `pFormat` [in]

Pointer to a GUID that specifies the time format. See [Time Format GUIDs](https://learn.microsoft.com/windows/desktop/DirectShow/time-format-guids).

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The specified format is not the current format. |
| **S_OK** | The specified format is the current format. |
| **E_NOTIMPL** | Not implemented. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

This method is slightly more efficient than the [IMediaSeeking::GetTimeFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-gettimeformat) method, because it does not require copying the GUID.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSeeking Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaseeking)

[IMediaSeeking::SetTimeFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-settimeformat)