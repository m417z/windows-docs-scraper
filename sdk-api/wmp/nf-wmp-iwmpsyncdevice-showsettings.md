# IWMPSyncDevice::showSettings

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **showSettings** method displays the Windows Media Player synchronization settings dialog box.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_NO_PDA (0xC00D1179L)** | The device is not connected. |
| **NS_E_PDA_INITIALIZINGDEVICES (0xC00D118D)** | Windows Media Player is currently busy initializing devices. Please try again later. |
| **NS_E_PDA_MANUALDEVICE (0xC00D1183)** | The status for the current device is wmpdsManualDevice. |
| **NS_E_PDA_PARTNERSHIPNOTEXIST** | The current status for the device is wmpdsPartnershipDeclined, wmpdsPartnershipAnother, or wmpdsNewDevice. This method only shows the settings dialog box for devices for which a partnership exists with the current instance of Windows Media Player. |

## Remarks

The remoted instance of Windows Media Player undocks, if necessary, and shows the device settings dialog box. If the Player was in skin mode, it returns to full mode. If the Player is locked in skin mode by corporate policy, the call fails.

When the user closes the dialog box, Windows Media Player returns to its original docking state.

Note that the events for docking and undocking Windows Media Player will occur normally.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPSyncDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncdevice)