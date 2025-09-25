# IWMPSubscriptionServiceCallback::onComplete

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **onComplete** method notifies Windows Media Player when a background process is completed.

## Parameters

### `hrResult` [in]

**HRESULT** success or error code.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

[IWMPSubscriptionService2::prepareForSync](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nf-subscriptionservices-iwmpsubscriptionservice2-prepareforsync) and [IWMPSubscriptionService2::deviceAvailable](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nf-subscriptionservices-iwmpsubscriptionservice2-deviceavailable) supply a pointer to an **IWMPSubscriptionServiceCallback** interface. When responding to calls from Windows Media Player to these methods, you must pass any time-consuming tasks to a separate worker thread and return immediately. When the worker thread has completed its task, it must call **IWMPSubscriptionServiceCallback::onComplete**.

In your **prepareForSync** and **deviceAvailable** methods, use the following procedure to provide your worker thread with a pointer to an **IWMPSubscriptionServiceCallback** interface.

1. Pass the pointer supplied in the *pCB* parameter to **CoMarshalInterThreadInterfaceInStream**, which returns an **IStream** pointer.
2. Pass the **IStream** pointer to your worker thread.
3. In your worker thread, call **CoGetInterfaceAndReleaseStream**, which returns an interface pointer that you can use to call **onComplete**.

## See also

[IWMPSubscriptionServiceCallback Interface](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nn-subscriptionservices-iwmpsubscriptionservicecallback)