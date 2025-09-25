# IMediaSeeking::SetTimeFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetTimeFormat` method sets the time format for subsequent seek operations.

## Parameters

### `pFormat` [in]

Pointer to a GUID that specifies the time format. See [Time Format GUIDs](https://learn.microsoft.com/windows/desktop/DirectShow/time-format-guids).

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_NOTIMPL** | Method is not supported. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_WRONG_STATE** | Filter graph is not stopped. |

## Remarks

This method specifies the time units used by other **IMediaSeeking** methods, such as [IMediaSeeking::GetPositions](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-getpositions) and [IMediaSeeking::SetPositions](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-setpositions). Whenever you call one of these other methods, any parameters that express time values are given in units of the current time format.

The default time format is [REFERENCE_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/reference-time) units (100 nanoseconds). Other time formats include frames, samples, and bytes. To determine if a given format is supported, call the [IMediaSeeking::IsFormatSupported](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-isformatsupported) method. If a format is supported, you can switch to that format by calling `SetTimeFormat`. Only one time format is active at any one time.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSeeking Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaseeking)

[IMediaSeeking::GetTimeFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-gettimeformat)

[IMediaSeeking::QueryPreferredFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-querypreferredformat)