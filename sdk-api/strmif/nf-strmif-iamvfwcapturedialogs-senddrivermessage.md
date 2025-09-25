# IAMVfwCaptureDialogs::SendDriverMessage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SendDriverMessage` method sends a driver-specific message.

## Parameters

### `iDialog` [in]

Handle of the driver dialog box. This is a member of the [VfwCaptureDialogs](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vfwcapturedialogs) enumeration.

### `uMsg` [in]

Message to send to the driver.

### `dw1` [in]

Message data.

### `dw2` [in]

Message data.

## Return value

Return value varies depending on the implementation within each driver.

## Remarks

You should never need to use this method. This method can send any private message to the capture driver. Behavior might be undetermined in response to arbitrary messages; use this method at your own risk.

This method calls the Video for Windows **videoMessage** function to send the driver message.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVfwCaptureDialogs Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvfwcapturedialogs)