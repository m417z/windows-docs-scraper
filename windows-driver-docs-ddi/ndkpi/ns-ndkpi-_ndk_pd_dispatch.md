# _NDK_PD_DISPATCH structure

## Description

The **NDK_PD_DISPATCH** structure specifies dispatch function entry points for the NDK protection domain (PD) object.

## Members

### `NdkClosePd`

The entry point for the object's [NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object) dispatch function.

### `NdkQueryExtension`

The entry point for the object's [NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface) dispatch function.

### `NdkCreateMr`

The entry point for the object's [NDK_FN_CREATE_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_mr) dispatch function.

### `NdkCreateMw`

The entry point for the object's [NDK_FN_CREATE_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_mw) dispatch function.

### `NdkCreateSrq`

The entry point for the object's [NDK_FN_CREATE_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_srq) dispatch function.

### `NdkCreateQp`

The entry point for the object's [NDK_FN_CREATE_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_qp) dispatch function.

### `NdkCreateQpWithSrq`

The entry point for the object's [NDK_FN_CREATE_QP_WITH_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_qp_with_srq) dispatch function.

### `NdkGetPrivilegedMemoryRegionToken`

The entry point for the object's [NDK_FN_GET_PRIVILEGED_MEMORY_REGION_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_privileged_memory_region_token) dispatch function.

## Remarks

The **NDK_PD_DISPATCH** structure is used in the [NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd) structure.

## See also

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_CREATE_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_mr)

[NDK_FN_CREATE_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_mw)

[NDK_FN_CREATE_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_qp)

[NDK_FN_CREATE_QP_WITH_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_qp_with_srq)

[NDK_FN_CREATE_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_srq)

[NDK_FN_GET_PRIVILEGED_MEMORY_REGION_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_privileged_memory_region_token)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd)