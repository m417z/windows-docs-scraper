# IWMPAudioRenderConfig::put_audioOutputDevice

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_audioOutputDevice** sets the current audio output device for the Windows Media Player ActiveX control.

## Parameters

### `bstrOutputDevice`

An MMDeviceAPI device ID that represents the device. If you pass **NULL** or an empty **BSTR** to this method, the Windows Media Player ActiveX control reverts to the default audio output device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method validates that the endpoint specified in *bstrOutputDevice* is a valid MMDeviceAPI device identifier string for an audio output endpoint. If it is not a valid identifier, the method fails. This method does not check to ensure that the specified endpoint is active.

## See also

[About MMDevice API](https://learn.microsoft.com/windows/desktop/CoreAudio/mmdevice-api)

[IMMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice)

[IWMPAudioRenderConfig](https://learn.microsoft.com/windows/desktop/api/wmprealestate/nn-wmprealestate-iwmpaudiorenderconfig)