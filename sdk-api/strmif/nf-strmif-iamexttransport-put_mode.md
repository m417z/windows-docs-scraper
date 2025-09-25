# IAMExtTransport::put_Mode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_Mode** method sets the transport mode; for example, play, stop, or record.

## Parameters

### `Mode` [in]

Specifies the transport mode. Use one of the following values.

| Value | Description |
| --- | --- |
| ED_MODE_PLAY | Play. |
| ED_MODE_STOP | Stop. |
| ED_MODE_FREEZE | Pause. |
| ED_MODE_THAW | Resume. |
| ED_MODE_FF | Fast forward. |
| ED_MODE_REW | Rewind. |
| ED_MODE_RECORD | Record. |
| ED_MODE_RECORD_FREEZE | Pause recording. |
| ED_MODE_RECORD_STROBE | Record single frame. |
| ED_MODE_STEP_FWD | Single step forward. |
| ED_MODE_STEP_REV | Single step backward. |
| ED_MODE_SHUTTLE | Shuttle (high-speed movement with visible picture). Use with [IAMExtTransport::put_Rate](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-put_rate) to set the transport speed. |
| ED_MODE_EDIT_CUE | Position transport to the cue point for an active edit event. |
| ED_MODE_LINK_ON | Link this method to the graph's [IMediaControl::Run](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-run), [IMediaControl::Stop](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-stop), and [IMediaControl::Pause](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-pause) methods. |
| ED_MODE_LINK_OFF | Disengage this method from the graph's **IMediaControl** methods. |

## Return value

Returns an HRESULT. Possible errors include the following.

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_REQ_NOT_ACCEP)** | The device did not accept the command. |
| **S_OK** | Success. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::get_Mode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-get_mode)