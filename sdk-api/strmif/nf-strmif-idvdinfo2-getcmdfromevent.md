# IDvdInfo2::GetCmdFromEvent

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCmdFromEvent` method retrieves an [IDvdCmd](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcmd) object from an [EC_DVD_CMD_START](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-cmd-start) or [EC_DVD_CMD_END](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-cmd-end) event.

## Parameters

### `lParam1` [in]

Event notification's *lParam1* parameter.

### `pCmdObj` [out]

Receives a pointer to the [IDvdCmd](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcmd) interface that is associated with the command that fired the event.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | The command no longer exists. |
| **E_POINTER** | Invalid argument. |

## Remarks

This method maps the *lParam1* parameter of an EC_DVD_CMD_START or EC_DVD_CMD_END event into an [IDvdCmd](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcmd) object that is associated with the command that fired the event. You can then call [WaitForStart](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcmd-waitforstart) or [WaitForEnd](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcmd-waitforend) to control the blocking behavior of the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) with respect to that command. The IDvdCmd object is created by the DVD Navigator and the returned pointer has already had its reference count incremented, so you must release it after **WaitForStart** or **WaitForEnd** returns.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)

[Synchronizing DVD Commands](https://learn.microsoft.com/windows/desktop/DirectShow/synchronizing-dvd-commands)