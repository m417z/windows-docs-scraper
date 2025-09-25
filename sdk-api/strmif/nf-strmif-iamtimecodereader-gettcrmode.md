# IAMTimecodeReader::GetTCRMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetTCRMode` method retrieves the timecode reader's properties.

This method is not implemented.

## Parameters

### `Param` [in]

Timecode reader property to get (either ED_TCR_SOURCE or ED_TCR_NOTIFY_ENABLE).

### `pValue` [out]

Pointer to the value of the requested timecode reader property. If *Param* is set to ED_TCR_NOTIFY_ENABLE, then this parameter will return OATRUE—meaning that notifications are enabled—or OAFALSE. If *Param* is set to ED_TCR_SOURCE, then this value must be one of the following.

| Value | Description |
| --- | --- |
| ED_TCR_CT | Control track |
| ED_TCR_LTC | Linear timecode |
| ED_TCR_VITC | Vertical interval timecode |
| ED_TCR_LAST_VALUE | Last read value |

## Return value

Returns E_NOTIMPL.

## Remarks

Linear timecode is recorded on an analog audio track as a bi-phase mark -encoded signal. Each timecode frame is one video frame time in duration.

Vertical timecode is usually stored in two lines of a video signal's vertical interval, somewhere between lines 11 and 20.

Control track is a once-per-frame signal recorded on a special track on a tape. The head and drive servo mechanisms use it to keep everything locked. It is also used to drive the counter on machines without timecode capability, and can optionally be used on machines equipped with a timecode reader.

Note that ED_TCR_LAST_VALUE is used when implementing timecode notification because the application does not want to initiate another timecode request to the external device. This method is not recommended for frame-accurate applications because of multithreading issues.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTimecodeReader Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtimecodereader)

[IAMTimecodeReader::SetTCRMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtimecodereader-settcrmode)