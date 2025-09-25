# IAMVfwCaptureDialogs::ShowDialog

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ShowDialog` method displays the specified VFW dialog box.

## Parameters

### `iDialog` [in]

Dialog box to display. This is a member of the [VfwCaptureDialogs](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vfwcapturedialogs) enumeration.

### `hwnd` [in]

Handle of the dialog box's parent window.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | Success. |
| **VFW_E_CANNOT_CONNECT** | Could not reconnect with the new format. |
| **VFW_E_NOT_STOPPED** | The filter graph is not stopped. |

## Remarks

Stop the filter graph before calling this method. Otherwise, the method fails and returns VFW_E_NOT_STOPPED.

The Video Format dialog (VfwCaptureDialog_Format) may change the video format. If so, the method tries to reconnect the capture filter. If the downstream filter rejects the new format, the method returns VFW_E_CANNOT_CONNECT.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVfwCaptureDialogs Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvfwcapturedialogs)