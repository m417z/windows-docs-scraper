# IWMPEvents2::DeviceSyncError

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DeviceSyncError** event occurs in response to a synchronization error.

## Parameters

### `pDevice` [in]

Address of the **IWMPSyncDevice** interface that represents the device for which the synchronization error occurred.

### `pMedia` [in]

Address of the **IWMPDispatch** interface that represents the media item for which the synchronization error occurred.

## Remarks

You should call **QueryInterface** on *pMedia* to get the **IWMPMedia2** interface for the **Media** object. You can then use **IWMPMedia2::get_error** to retrieve more information about the error that occurred.

Use **IWMPSyncDevice::isIdentical** to determine whether a particular device matches the device for which the error occurred.

You can also handle this event through an **IDispatch** event sink by using the **_WMPOCXEvents** interface.

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPEvents2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents2)

[IWMPMedia2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia2)

[IWMPSyncDevice::isIdentical](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-isidentical)

[_WMPOCXEvents Interface](https://learn.microsoft.com/windows/desktop/WMP/-wmpocxevents-interface)