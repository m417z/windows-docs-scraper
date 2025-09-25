# IWMPSubscriptionService2::prepareForSync

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **prepareForSync** method is implemented by the online store and called by Windows Media Player just before synchronization happens. Use this method to perform tasks related to synchronizing a digital media file to a device.

## Parameters

### `bstrFilename` [in]

String containing the name of the digital media file being synchronized.

### `bstrDeviceName` [in]

String containing the canonical name of the device.

### `pCB` [in]

Pointer to an [IWMPSubscriptionServiceCallback](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nn-subscriptionservices-iwmpsubscriptionservicecallback) interface. The online store uses this pointer to notify Windows Media Player that preparation for synchronization is complete.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The string contained in *bstrDeviceName* is not the same name retrieved using [IWMPSyncDevice::get_deviceName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsyncdevice-get_devicename). Rather, it is the canonical name retrieved by using the **IWMDMDevice2::GetCanonicalName** method provided by the Windows Media Device Manager SDK.

Your code should not perform lengthy operations synchronously when Windows Media Player calls this method. Instead, you must perform time-consuming tasks on a separate worker thread. When the worker thread has completed its work, it must call [IWMPSubscriptionServiceCallback::onComplete](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nf-subscriptionservices-iwmpsubscriptionservicecallback-oncomplete).

Use the following procedure to provide your worker thread with a pointer to an **IWMPSubscriptionServiceCallback** interface.

1. Pass *pCB* to **CoMarshalInterThreadInterfaceInStream**, which returns an **IStream** pointer.
2. Pass the **IStream** pointer to your worker thread.
3. In your worker thread, call **CoGetInterfaceAndReleaseStream**, which returns an interface pointer that you can use to call **onComplete**.

When you call [IWMPSubscriptionServiceCallback::onComplete](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nf-subscriptionservices-iwmpsubscriptionservicecallback-oncomplete), you should return a success code to allow Windows Media Player to continue synchronizing the specified digital media file, or an error code to disallow synchronization. Windows Media Player displays an error message based on the error code you provide. You should avoid using generic **HRESULTs**, such as E_FAIL. Instead, you can return the **HRESULT** error code you receive from a call to one of the Windows Media SDKs, such as the Windows Media Device Manager SDK, or one of the error codes in nserror.h, which can be found in the \Include folder where you installed the Windows Media Player SDK.

## See also

[IWMPSubscriptionService2 Interface](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nn-subscriptionservices-iwmpsubscriptionservice2)

[IWMPSubscriptionServiceCallback Interface](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nn-subscriptionservices-iwmpsubscriptionservicecallback)