# IWMPSyncDevice::get_connected

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_connected** method retrieves a value indicating whether the device is connected to Windows Media Player.

## Parameters

### `pvbConnected` [out]

**VARIANT_BOOL** indicating whether the device is connected. The following table describes the possible values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | The device is connected. |
| VARIANT_FALSE | The device is not connected. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_PDA_INITIALIZINGDEVICES (0xC00D118D)** | Windows Media Player is currently busy initializing devices. Please try again later. |

## Remarks

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[Enumerating Devices](https://learn.microsoft.com/windows/desktop/WMP/enumerating-devices)

[IWMPSyncDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncdevice)

[Retrieving Device Attributes](https://learn.microsoft.com/windows/desktop/WMP/retrieving-device-attributes)