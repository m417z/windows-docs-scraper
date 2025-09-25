# IDvdInfo2::GetCurrentUOPS

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentUOPS` method retrieves a set of flags indicating which navigation commands, if any, the content authors have explicitly disabled for the current disc location.

## Parameters

### `pulUOPs` [out]

Receives a bitwise [VALID_UOP_FLAG](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-valid_uop_flag) values. Each bit represents the state (valid or not valid) of a user operation (UOP). If the bit is set, then that user operation is prohibited. See Remarks.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | *pulUOPs* is not a valid pointer. |

## Remarks

DVD authors can insert UOP commands at almost any place on the disc to disallow a navigation command that would otherwise be permitted within the current DVD domain. In other words, UOP commands enable disc authors to override the usual navigation permissions.

A DVD player application should normally never have to use this method because the DVD Navigator automatically checks all UOP permissions before proceeding with any command, and will return VFW_E_DVD_OPERATION_INHIBITED from any method if the command is invalid under the current UOP. If your application needs to track the current UOP permissions itself, you can call `GetCurrentUOPS` whenever the current UOP permissions are required, or you can handle the [EC_DVD_VALID_UOPS_CHANGE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-valid-uops-change) event notification in your message loop and retrieve the UOP information from the *lParam1* parameter. The latter approach is generally more efficient.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)