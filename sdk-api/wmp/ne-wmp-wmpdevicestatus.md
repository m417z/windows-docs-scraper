# WMPDeviceStatus enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPDeviceStatus** enumeration type defines the possible values for the current status of a device. To use this enumeration, you must create a remoted instance of the Windows Media Player 10 or later control.

## Constants

### `wmpdsUnknown:0`

Not a valid status.

### `wmpdsPartnershipExists`

A partnership between Windows Media Player and the device exists.

### `wmpdsPartnershipDeclined`

The user declined to create a partnership with the device. A device will also have this status when the partnership was deleted programmatically by calling [IWMPSyncDevice::deletePartnership](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-deletepartnership).

### `wmpdsPartnershipAnother`

A partnership exists with another computer or user. Windows Media Player 10 or later allows one partnership with one computer per device.

### `wmpdsManualDevice`

The current device supports manual transfers only.

### `wmpdsNewDevice`

The device is a new device; Windows Media Player has information stored for the device.

### `wmpdsLast`

Last enumerated value. Not a valid device state.

## Remarks

Windows Media Player 10 Mobile: This enumeration is not supported.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/enumeration-types)

[IWMPEvents2::DeviceStatusChange](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents2-devicestatuschange)

[IWMPSyncDevice::get_status](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-get_status)

[Interfaces](https://learn.microsoft.com/windows/desktop/WMP/interfaces)

[Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control)