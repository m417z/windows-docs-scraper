# NDK_FN_CONNECT_EVENT_CALLBACK callback function

## Description

The *NdkConnectEventCallback* (*NDK_FN_CONNECT_EVENT_CALLBACK*) function is called by an NDK provider to notify a consumer about an incoming connection request.

## Parameters

### `ConnectEventContext` [in, optional]

A context area that was specified in the *ConnectEventContext* parameter of the *NdkCreateListener* ([NDK_FN_CREATE_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_listener)) function when the listener object was created.

### `pNdkConnector` [in]

A pointer to an NDK connector object ([NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)) that represents a new incoming connection request.

## Remarks

**Note** This function is implemented by the NDK consumer and passed to the NDK provider.

The NDK consumer specified the *NdkConnectEventCallback* function in the *ConnectEventContext* parameter of the *NdkCreateListener* ([NDK_FN_CREATE_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_listener)) function when the listener object was created.

## See also

[NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)

[NDK_FN_CREATE_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_listener)