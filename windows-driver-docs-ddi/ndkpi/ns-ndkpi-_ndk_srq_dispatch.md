# _NDK_SRQ_DISPATCH structure

## Description

The **NDK_SRQ_DISPATCH** structure specifies dispatch function entry points for the NDK shared receive queue (SRQ) object.

## Members

### `NdkCloseSrq`

The entry point for the object's [NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object) dispatch function.

### `NdkQueryExtension`

The entry point for the object's [NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface) dispatch function.

### `NdkModifySrq`

The entry point for the object's [NDK_FN_MODIFY_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_modify_srq) dispatch function.

### `NdkSrqReceive`

The entry point for the object's [NDK_FN_SRQ_RECEIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_srq_receive) dispatch function.

## Remarks

The **NDK_SRQ_DISPATCH** structure is used in the [NDK_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq) structure.

## See also

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_MODIFY_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_modify_srq)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_FN_SRQ_RECEIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_srq_receive)

[NDK_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq)