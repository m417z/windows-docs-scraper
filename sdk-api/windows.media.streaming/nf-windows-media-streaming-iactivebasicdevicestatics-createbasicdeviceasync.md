# IActiveBasicDeviceStatics::streaming

## Description

\[The feature associated with this page, [Windows Media Streaming API](https://learn.microsoft.com/windows/win32/mediastreaming/media-streaming-api-portal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). **Media Casting** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Media Casting** instead of **Windows Media Streaming API**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Asynchronously creates an active basic device.

## Parameters

### `deviceIdentifier` [in]

The identifier of the device.

### `type` [in]

The type of the device.

### `value` [out, retval]

The asynchronous operation. Upon completion, [IAsyncOperation.GetResults](https://learn.microsoft.com/previous-versions/br205815(v=vs.85)) returns a [ActiveBasicDevice](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn385755(v=vs.85)) object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ActiveBasicDevice](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn385755(v=vs.85))

[BasicDevice](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828813(v=vs.85))

[IActiveBasicDeviceStatics](https://learn.microsoft.com/previous-versions/windows/desktop/api/windows.media.streaming/nn-windows-media-streaming-iactivebasicdevicestatics)