# NDK_FN_DISCONNECT_EVENT_CALLBACK callback function

## Description

The *NdkDisconnectEventCallback* (*NDK_FN_DISCONNECT_EVENT_CALLBACK*) function is called by the NDK provider once when the peer disconnects.

## Parameters

### `DisconnectEventContext` [in, optional]

A context area that was specified in the *DisconnectEvent* parameter of the *NdkCompleteConnect* ([NDK_FN_COMPLETE_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect)) or *NdkAccept* ([NDK_FN_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept)) function when the completion queue (CQ) object was created.

## Remarks

**Note** This routine is implemented by the NDK consumer and passed to the NDK provider.

*NdkDisconnectEventCallback* is a callback function for connection disconnect events. A disconnect notification callback function is specified for a connection with the *NdkCompleteConnect* ([NDK_FN_COMPLETE_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect)) function on the initiator side and with the *NdkAccept* ([NDK_FN_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept)) function on the listener side. The NDK provider invokes this callback only once when the peer disconnects. The provider should not flush outstanding work requests when it indicates a disconnect event because of an incoming disconnect request from the peer.

## See also

[NDK_FN_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept)

[NDK_FN_COMPLETE_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect)