# _NDK_CONNECTOR_DISPATCH structure

## Description

The **NDK_CONNECTOR_DISPATCH** structure specifies dispatch function entry points for the NDK connector object.

## Members

### `NdkCloseConnector`

The entry point for the object's [NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object) dispatch function.

### `NdkQueryExtension`

The entry point for the object's [NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface) dispatch function.

### `NdkConnect`

The entry point for the object's [NDK_FN_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect) dispatch function.

### `NdkConnectWithSharedEndpoint`

The entry point for the object's [NDK_FN_CONNECT_WITH_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect_with_shared_endpoint) dispatch function.

### `NdkCompleteConnect`

The entry point for the object's [NDK_FN_COMPLETE_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect) dispatch function.

### `NdkAccept`

The entry point for the object's [NDK_FN_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept) dispatch function.

### `NdkReject`

The entry point for the object's [NDK_FN_REJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_reject) dispatch function.

### `NdkGetConnectionData`

The entry point for the object's [NDK_FN_GET_CONNECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_connection_data) dispatch function.

### `NdkGetLocalAddress`

The entry point for the object's [NDK_FN_GET_LOCAL_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_local_address) dispatch function.

### `NdkGetPeerAddress`

The entry point for the object's [NDK_FN_GET_PEER_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_peer_address) dispatch function.

### `NdkDisconnect`

The entry point for the object's [NDK_FN_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_disconnect) dispatch function.

### `NdkCompleteConnectEx`

The entry point for the object's [NDK_FN_COMPLETE_CONNECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect_ex) dispatch function.

### `NdkAcceptEx`

The entry point for the object's [NDK_FN_ACCEPT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept_ex) dispatch function.

## Remarks

The **NDK_CONNECTOR_DISPATCH** structure is used in the [NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector) structure.

## See also

[NDK_FN_ACCEPT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept_ex)

[NDK_FN_COMPLETE_CONNECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect_ex)

[NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)

[NDK_FN_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_accept)

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_COMPLETE_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_complete_connect)

[NDK_FN_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect)

[NDK_FN_CONNECT_WITH_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect_with_shared_endpoint)

[NDK_FN_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_disconnect)

[NDK_FN_GET_CONNECTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_connection_data)

[NDK_FN_GET_LOCAL_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_local_address)

[NDK_FN_GET_PEER_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_peer_address)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_FN_REJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_reject)