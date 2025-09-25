# _NDK_MR_DISPATCH structure

## Description

The **NDK_MR_DISPATCH** structure specifies dispatch function entry points for the NDK memory region (MR) object.

## Members

### `NdkCloseMr`

The entry point for the object's [NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object) dispatch function.

### `NdkQueryExtension`

The entry point for the object's [NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface) dispatch function.

### `NdkRegisterMr`

The entry point for the object's [NDK_FN_REGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_register_mr) dispatch function.

### `NdkDeregisterMr`

The entry point for the object's [NDK_FN_DEREGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_deregister_mr) dispatch function.

### `NdkInitializeFastRegisterMr`

The entry point for the object's [NDK_FN_INITIALIZE_FAST_REGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_initialize_fast_register_mr) dispatch function.

### `NdkGetRemoteTokenFromMr`

The entry point for the object's [NDK_FN_GET_REMOTE_TOKEN_FROM_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_remote_token_from_mr) dispatch function.

### `NdkGetLocalTokenFromMr`

The entry point for the object's [NDK_FN_GET_LOCAL_TOKEN_FROM_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_local_token_from_mr) dispatch function.

## Remarks

The **NDK_MR_DISPATCH** structure is used in the [NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr) structure.

## See also

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_DEREGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_deregister_mr)

[NDK_FN_GET_LOCAL_TOKEN_FROM_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_local_token_from_mr)

[NDK_FN_GET_REMOTE_TOKEN_FROM_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_remote_token_from_mr)

[NDK_FN_INITIALIZE_FAST_REGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_initialize_fast_register_mr)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_FN_REGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_register_mr)

[NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)