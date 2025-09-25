# IActiveBasicDevice::streaming

## Description

\[The feature associated with this page, [Windows Media Streaming API](https://learn.microsoft.com/windows/win32/mediastreaming/media-streaming-api-portal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). **Media Casting** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Media Casting** instead of **Windows Media Streaming API**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Called by the application to indicate that the device is being used for active streaming.

## Parameters

### `fIsStreaming`

**true** indicates that streaming is on. **false** indicates that streaming if off.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called by the application to indicate that the device is being used for active streaming. A value of **true** means that streaming is on. A value of **false** means that streaming is off.

The on/off calls must be matching calls from the application.

In response to this notification, the [ActiveBasicDevice](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn385755(v=vs.85)) object can take actions to keep the connection to the device active.

## See also

[IActiveBasicDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/windows.media.streaming/nn-windows-media-streaming-iactivebasicdevice)