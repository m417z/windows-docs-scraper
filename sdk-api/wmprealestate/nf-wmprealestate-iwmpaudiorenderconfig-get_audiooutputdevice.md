# IWMPAudioRenderConfig::get_audioOutputDevice

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_audioOutputDevice** method retrieves the current audio output device used by the Windows Media Player ActiveX control.

## Parameters

### `pbstrOutputDevice`

An MMDeviceAPI device ID that represents the currently configured audio output device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If no default audio device is configured, this method retrieves an empty **BSTR**. If the ActiveX control is hosted in the Windows Media Player, and the Player has configured an output device, this method retrieves the output device configured by the Player.

If this method retrieves an empty string, the Windows Media Player ActiveX control will render using the default audio rendering device.

## See also

[About MMDevice API](https://learn.microsoft.com/windows/desktop/CoreAudio/mmdevice-api)

[IMMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice)

[IWMPAudioRenderConfig](https://learn.microsoft.com/windows/desktop/api/wmprealestate/nn-wmprealestate-iwmpaudiorenderconfig)