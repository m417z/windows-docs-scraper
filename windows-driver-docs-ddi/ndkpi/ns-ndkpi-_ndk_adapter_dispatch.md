# _NDK_ADAPTER_DISPATCH structure

## Description

The **NDK_ADAPTER_DISPATCH** structure specifies dispatch function entry points for the NDK adapter object.

## Members

### `NdkQueryExtension`

The entry point for the object's [NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface) dispatch function.

### `NdkQueryAdapterInfo`

The entry point for the object's [NDK_FN_QUERY_ADAPTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_adapter_info) dispatch function.

### `NdkCreateCq`

The entry point for the object's [NDK_FN_CREATE_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_cq) dispatch function.

### `NdkCreatePd`

The entry point for the object's [NDK_FN_CREATE_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_pd) dispatch function.

### `NdkCreateSharedEndpoint`

The entry point for the object's [NDK_FN_CREATE_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_shared_endpoint) dispatch function.

### `NdkCreateConnector`

The entry point for the object's [NDK_FN_CREATE_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_connector) dispatch function.

### `NdkCreateListener`

The entry point for the object's [NDK_FN_CREATE_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_listener) dispatch function.

### `NdkBuildLAM`

The entry point for the object's [NDK_FN_BUILD_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_build_lam) dispatch function.

### `NdkReleaseLAM`

The entry point for the object's [NDK_FN_RELEASE_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_release_lam) dispatch function.

## Remarks

The **NDK_ADAPTER_DISPATCH** structure is used in the [NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter) structure.

## See also

[NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)

[NDK_FN_BUILD_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_build_lam)

[NDK_FN_CREATE_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_connector)

[NDK_FN_CREATE_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_cq)

[NDK_FN_CREATE_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_listener)

[NDK_FN_CREATE_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_pd)

[NDK_FN_CREATE_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_shared_endpoint)

[NDK_FN_QUERY_ADAPTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_adapter_info)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_FN_RELEASE_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_release_lam)