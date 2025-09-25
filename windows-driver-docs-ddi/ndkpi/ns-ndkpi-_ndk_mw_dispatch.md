# _NDK_MW_DISPATCH structure

## Description

The **NDK_MW_DISPATCH** structure specifies dispatch function entry points for the NDK memory window (MW) object.

## Members

### `NdkCloseMw`

The entry point for the object's [NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object) dispatch function.

### `NdkQueryExtension`

The entry point for the object's [NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface) dispatch function.

### `NdkGetRemoteTokenFromMw`

The entry point for the object's [NDK_FN_GET_REMOTE_TOKEN_FROM_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_remote_token_from_mw) dispatch function.

## Remarks

The **NDK_MW_DISPATCH** structure is used in the [NDK_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw) structure.

## See also

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_GET_REMOTE_TOKEN_FROM_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_remote_token_from_mw)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw)