# IWMPSyncDevice::createPartnership

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **createPartnership** method creates a partnership between Windows Media Player and the device.

## Parameters

### `vbShowUI` [out]

**VARIANT_BOOL** that specifies whether Windows Media Player displays the **Device Setup** dialog box. The following table describes the behavior for each possible value.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | The remoted instance of Windows Media Player undocks, if necessary, and shows the device settings dialog box. If the Player is in skin mode, it returns to full mode. If the Player is locked in skin mode by corporate policy, the call fails.When the user closes the dialog box, Windows Media Player returns to its original docking state.<br><br>Note that the events for docking and undocking the Player will occur normally. |
| VARIANT_FALSE | Windows Media Player attempts to create a partnership using a default set of device synchronization playlists. The Player does not change its current visible state or mode. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded or a partnership exists. |
| **E_ABORT** | The user canceled the operation. |
| **NS_E_NO_PDA (0xC00D1179L)** | The device is not connected. |
| **NS_E_PDA_INITIALIZINGDEVICES (0xC00D118D)** | Windows Media Player is currently busy initializing devices. Please try again later. |
| **NS_E_PDA_MANUALDEVICE (0xC00D1183)** | The status for the current device is wmpdsManualDevice. |

## Remarks

This method starts the asynchronous process of creating a partnership. To get the result, you must handle the **CreatePartnershipComplete** event. If the partnership exists already, this method returns S_OK and no event occurs.

Windows Media Player 10 or later supports up to 16 device partnerships. The Player allows one partnership with one computer for each device. This means that creating a new partnership destroys any existing partnership with the current device.

Windows Media Player cannot create a partnership with a device having the status wmpdsManualDevice.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPEvents2::CreatePartnershipComplete](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents2-createpartnershipcomplete)

[IWMPSyncDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsyncdevice)

[IWMPSyncDevice::get_deviceId](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-get_deviceid)