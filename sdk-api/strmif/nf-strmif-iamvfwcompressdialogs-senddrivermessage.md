# IAMVfwCompressDialogs::SendDriverMessage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SendDriverMessage` method sends a driver-specific message.

## Parameters

### `uMsg` [in]

Message to send to the driver.

### `dw1` [in]

Message data.

### `dw2` [in]

Message data.

## Return value

Return value varies depending on the implementation within each driver.

## Remarks

You should never need to use this method. This method can send any private message to the video compressor (codec). Behavior might be undetermined in response to arbitrary messages; use this method at your own risk.

This method calls the Video for Windows video compression manager (VCM) [ICSendMessage](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icsendmessage) function to send the message.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVfwCompressDialogs Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvfwcompressdialogs)