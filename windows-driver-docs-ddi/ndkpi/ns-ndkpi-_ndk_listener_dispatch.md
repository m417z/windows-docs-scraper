# _NDK_LISTENER_DISPATCH structure

## Description

The **NDK_LISTENER_DISPATCH** structure specifies dispatch function entry points for the NDK listener object.

## Members

### `NdkCloseListener`

The entry point for the object's [NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object) dispatch function.

### `NdkQueryExtension`

The entry point for the object's [NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface) dispatch function.

### `NdkListen`

The entry point for the object's [NDK_FN_LISTEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_listen) dispatch function.

### `NdkGetLocalAddress`

The entry point for the object's [NDK_FN_GET_LISTENER_LOCAL_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_listener_local_address) dispatch function.

### `NdkControlConnectEvents`

The entry point for the object's [NDK_FN_CONTROL_CONNECT_EVENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_control_connect_events) dispatch function.

## Remarks

The **NDK_LISTENER_DISPATCH** structure is used in the [NDK_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener) structure.

## See also

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_CONTROL_CONNECT_EVENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_control_connect_events)

[NDK_FN_GET_LISTENER_LOCAL_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_listener_local_address)

[NDK_FN_LISTEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_listen)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener)