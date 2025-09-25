# IActiveBasicDevice::streaming

## Description

\[The feature associated with this page, [Windows Media Streaming API](https://learn.microsoft.com/windows/win32/mediastreaming/media-streaming-api-portal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). **Media Casting** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Media Casting** instead of **Windows Media Streaming API**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Sets the cached sink protocol info for the device.

## Parameters

### `value`

The cached sink protocol info for the device.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IActiveBasicDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/windows.media.streaming/nn-windows-media-streaming-iactivebasicdevice)

[IBasicDevice](https://learn.microsoft.com/windows/desktop/mediastreaming/ibasicdevice)