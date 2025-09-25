## Description

The *NdkDisconnectEventCallbackEx* (*NDK_FN_DISCONNECT_EVENT_CALLBACK_EX*) function is called by the NDK provider once when the peer disconnects.

## Parameters

### `DisconnectEventContext` [in, optional]

A context area that was specified in the *DisconnectEvent* parameter of the *NdkCompleteConnectEx* ([NDK_FN_COMPLETE_CONNECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect_ex)) or *NdkAcceptEx* ([NDK_FN_ACCEPT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept_ex)) function when the completion queue (CQ) object was created.

### `ProviderDisconnectReason` [in]

A provider specific code that indicates why the connection has disconnected.

**Zero** indicates the NDK provider does not support the disconnect reason capability yet or did not provide one.

## Remarks

> [!NOTE]
> This routine is implemented by the NDK consumer and passed to the NDK provider.

*NdkDisconnectEventCallbackEx* is a callback function for connection disconnect events. A disconnect notification callback function is specified for a connection with the *NdkCompleteConnectEx* ([NDK_FN_COMPLETE_CONNECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect_ex)) function on the initiator side and with the *NdkAcceptEx* ([NDK_FN_ACCEPT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept_ex)) function on the listener side. The NDK provider invokes this callback only once when the peer disconnects. The provider should not flush outstanding work requests when it indicates a disconnect event because of an incoming disconnect request from the peer.

## See also

[NDK_FN_COMPLETE_CONNECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect_ex)

[NDK_FN_ACCEPT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept_ex)