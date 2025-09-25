# IWMPSyncDevice::get_status

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_status** method retrieves a value that indicates the status of the relationship between Windows Media Player and the device.

## Parameters

### `pwmpds` [out]

Pointer to a **WMPDeviceStatus** enumeration value indicating the current status.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_PDA_INITIALIZINGDEVICES (0xC00D118D)** | Windows Media Player is currently busy initializing devices. Please try again later. |

## Remarks

Windows Media Player 10 or later supports up to 16 device partnerships. The Player allows one partnership with one computer for each device. Creating a new partnership destroys any existing partnership with the current device.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPSyncDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncdevice)

[Retrieving Device Attributes](https://learn.microsoft.com/windows/desktop/WMP/retrieving-device-attributes)

[WMPDeviceStatus](https://learn.microsoft.com/windows/desktop/api/wmp/ne-wmp-wmpdevicestatus)