# IWMPSyncDevice::get_partnershipIndex

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_partnershipIndex** method retrieves the index of the device partnership.

## Parameters

### `plIndex` [out]

Pointer to a **long** that contains the partnership index value. Possible values range from 0 to 16.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_PDA_INITIALIZINGDEVICES (0xC00D118D)** | Windows Media Player is currently busy initializing devices. Please try again later. |

## Remarks

Windows Media Player 10 or later supports up to 16 device partnerships, numbered 1 to 16. The Player allows one partnership with one computer for each device. Creating a new partnership destroys any existing partnership with the current device.

When *plIndex* equals zero, no partnership exists.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPSyncDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncdevice)

[IWMPSyncDevice::createPartnership](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-createpartnership)

[IWMPSyncDevice::deletePartnership](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-deletepartnership)

[IWMPSyncDevice::get_deviceId](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-get_deviceid)