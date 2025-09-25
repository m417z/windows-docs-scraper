# WMPSyncState enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPSyncState** enumeration type defines the possible operational states of Windows Media Player as it synchronizes digital media to a device. To use this enumeration you must create a remoted instance of the Windows Media Player 10 or later control.

## Constants

### `wmpssUnknown:0`

Synchronization state is unknown.

### `wmpssSynchronizing`

Windows Media Player is synchronizing the device.

### `wmpssStopped`

Synchronization has stopped.

### `wmpssEstimating`

An estimation of synchronization size is in progress. Requires Windows Media Player 12.

### `wmpssLast`

Last enumerated value. Not a valid state.

## Remarks

Windows Media Player 10 Mobile: This enumeration is not supported.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/enumeration-types)

[IWMPEvents2::DeviceSyncStateChange](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents2-devicesyncstatechange)

[IWMPSyncDevice3::estimateSyncSize](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice3-estimatesyncsize)

[IWMPSyncDevice::get_syncState](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-get_syncstate)

[Interfaces](https://learn.microsoft.com/windows/desktop/WMP/interfaces)

[Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control)