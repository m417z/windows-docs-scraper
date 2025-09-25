# IWMPEvents2::CreatePartnershipComplete

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CreatePartnershipComplete** event occurs when an asynchronous call to **IWMPSyncDevice::createPartnership** completes.

## Parameters

### `pDevice` [in]

Address of the **IWMPSyncDevice** interface that represents the device object for which the partnership was created.

### `hrResult` [in]

The success or error **HRESULT** for the create partnership operation.

## Remarks

A call to **IWMPSyncDevice::createPartnership** starts the asynchronous operation of creating a partnership between Windows Media Player and a device. This call returns immediately. When the operation that creates the partnership ends, **CreatePartnershipComplete** occurs.

Receiving this event notification does not guarantee that a partnership exists.

This event is broadcasted to all remoted Windows Media Player control instances.

Use **IWMPSyncDevice::isIdentical** to determine whether a particular device matches the device for which the partnership was created.

You can also handle this event through an **IDispatch** event sink by using the **_WMPOCXEvents** interface.

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPEvents2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents2)

[IWMPSyncDevice::createPartnership](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-createpartnership)

[IWMPSyncDevice::isIdentical](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-isidentical)

[_WMPOCXEvents Interface](https://learn.microsoft.com/windows/desktop/WMP/-wmpocxevents-interface)