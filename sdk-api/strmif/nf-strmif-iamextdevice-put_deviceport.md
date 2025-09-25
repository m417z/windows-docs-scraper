# IAMExtDevice::put_DevicePort

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_DevicePort` method assigns the communication port to which the external device is connected.

This method is not implemented.

## Parameters

### `DevicePort` [in]

Specifies the port to which the device will connect. Use one of the following values.

| Value | Description |
| --- | --- |
| DEV_PORT_1394 | IEEE 1394 Bus |
| DEV_PORT_ARTI | ARTI driver |
| DEV_PORT_COM1 | COM1 |
| DEV_PORT_COM2 | COM2 |
| DEV_PORT_COM3 | COM3 |
| DEV_PORT_COM4 | COM4 |
| DEV_PORT_DIAQ | Diaquest driver |
| DEV_PORT_MIN | DEV_PORT_SIM |
| DEV_PORT_SIM | Simulation port (used for "no hardware" simulation) |
| DEV_PORT_USB | Universal serial bus |

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtDevice Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamextdevice)

[IAMExtDevice::get_DevicePort](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamextdevice-get_deviceport)