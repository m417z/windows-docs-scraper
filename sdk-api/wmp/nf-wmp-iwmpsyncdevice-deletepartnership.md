# IWMPSyncDevice::deletePartnership

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **deletePartnership** method terminates the partnership between Windows Media Player and the device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The method succeeded, but there was no partnership to delete. This occurs when the current status is wmpdsPartnershipDeclined or wmpdsNewDevice. |
| **NS_E_PDA_INITIALIZINGDEVICES (0xC00D118D)** | Windows Media Player is currently busy initializing devices. Please try again later. |
| **NS_E_PDA_MANUALDEVICE (0xC00D1183)** | The status for the current device is wmpdsManualDevice. |
| **NS_E_PDA_PARTNERSHIPNOTEXIST (0xC00D1184)** | The method failed because the current status for the device is wmpdsPartnershipAnother. This method will only delete partnerships that exist for the current instance of Windows Media Player. |

## Remarks

When the partnership is deleted, the device status is set to **wmpdsPartnershipDeclined**. If no partnership exists, this method simply returns S_OK.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPSyncDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncdevice)