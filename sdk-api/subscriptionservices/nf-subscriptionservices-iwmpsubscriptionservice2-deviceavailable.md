# IWMPSubscriptionService2::deviceAvailable

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **deviceAvailable** method is implemented by the online store to initiate device-specific processing tasks.

## Parameters

### `bstrDeviceName` [in]

String containing the device name.

### `pCB` [in]

Pointer to an **IWMPSubscriptionServiceCallback** interface. The online store uses this pointer to notify Windows Media Player that device-specific processing is complete.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Windows Media Player calls this method after a synchronization operation if the time elapsed since the last call is one week or more.

Your code should not perform lengthy operations synchronously when Windows Media Player calls this method. Instead, you must perform time-consuming tasks on a separate worker thread. When the worker thread has completed its work, it must call [IWMPSubscriptionServiceCallback::onComplete](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nf-subscriptionservices-iwmpsubscriptionservicecallback-oncomplete).

Use the following procedure to provide your worker thread with a pointer to an **IWMPSubscriptionServiceCallback** interface.

1. Pass *pCB* to **CoMarshalInterThreadInterfaceInStream**, which returns an **IStream** pointer.
2. Pass the **IStream** pointer to your worker thread.
3. In your worker thread, call **CoGetInterfaceAndReleaseStream**, which returns an interface pointer that you can use to call **onComplete**.

The string contained in *bstrDeviceName* is not the same name retrieved by using [IWMPSyncDevice::get_deviceName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-get_devicename). Rather, it is the canonical name retrieved by using the **IWMDMDevice2::GetCanonicalName** method provided by the Windows Media Device Manager SDK.

## See also

[IWMPSubscriptionService2 Interface](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nn-subscriptionservices-iwmpsubscriptionservice2)

[IWMPSubscriptionServiceCallback Interface](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nn-subscriptionservices-iwmpsubscriptionservicecallback)