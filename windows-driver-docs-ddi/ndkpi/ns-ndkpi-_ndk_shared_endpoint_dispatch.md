# _NDK_SHARED_ENDPOINT_DISPATCH structure

## Description

The **NDK_SHARED_ENDPOINT_DISPATCH** structure specifies dispatch function entry points for the NDK shared endpoint object.

## Members

### `NdkCloseSharedEndpoint`

The entry point for the object's [NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object) dispatch function.

### `NdkQueryExtension`

The entry point for the object's [NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface) dispatch function.

### `NdkGetLocalAddress`

The entry point for the object's [NDK_FN_GET_SHARED_ENDPOINT_LOCAL_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_shared_endpoint_local_address) dispatch function.

## Remarks

The **NDK_SHARED_ENDPOINT_DISPATCH** structure is used in the [NDK_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_shared_endpoint) structure.

## See also

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_GET_SHARED_ENDPOINT_LOCAL_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_shared_endpoint_local_address)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_shared_endpoint)