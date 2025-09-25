# IWMPEvents2::DeviceSyncStateChange

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DeviceSyncStateChange** event occurs when the synchronization state of a device changes.

## Parameters

### `pDevice` [in]

Address of the **IWMPSyncDevice** interface that represents the device for which the synchronization state changed.

### `NewState` [in]

**WMPSyncState** enumeration value that represents the new synchronization state for the device specified by *pDevice*.

## Remarks

Use **IWMPSyncDevice::isIdentical** to determine whether a particular device matches the device for which the synchronization state changed.

You can also handle this event through an **IDispatch** event sink by using the **_WMPOCXEvents** interface.

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPEvents2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents2)

[IWMPSyncDevice::isIdentical](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-isidentical)

[WMPSyncState](https://learn.microsoft.com/windows/desktop/api/wmp/ne-wmp-wmpsyncstate)

[_WMPOCXEvents Interface](https://learn.microsoft.com/windows/desktop/WMP/-wmpocxevents-interface)