# _NDK_QP_DISPATCH structure

## Description

The **NDK_QP_DISPATCH** structure specifies dispatch function entry points for the NDK queue pair (QP) object.

## Members

### `NdkCloseQp`

The entry point for the object's [NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object) dispatch function.

### `NdkQueryExtension`

The entry point for the object's [NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface) dispatch function.

### `NdkFlush`

The entry point for the object's [NDK_FN_FLUSH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_flush) dispatch function.

### `NdkSend`

The entry point for the object's [NDK_FN_SEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_send) dispatch function.

### `NdkReceive`

The entry point for the object's [NDK_FN_RECEIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_receive) dispatch function.

### `NdkBind`

The entry point for the object's [NDK_FN_BIND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_bind) dispatch function.

### `NdkFastRegister`

The entry point for the object's [NDK_FN_FAST_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_fast_register) dispatch function.

### `NdkInvalidate`

The entry point for the object's [NDK_FN_INVALIDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_invalidate) dispatch function.

### `NdkRead`

The entry point for the object's [NDK_FN_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_read) dispatch function.

### `NdkWrite`

The entry point for the object's [NDK_FN_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_write) dispatch function.

### `NdkSendAndInvalidate`

The entry point for the object's [NDK_FN_SEND_AND_INVALIDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_send_and_invalidate) dispatch function.

**Note** This member is supported only in NDKPI 1.2 (Windows Server 2012 R2) and later.

## Remarks

The **NDK_QP_DISPATCH** structure is used in the [NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp) structure.

## See also

[NDK_FN_BIND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_bind)

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_FAST_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_fast_register)

[NDK_FN_FLUSH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_flush)

[NDK_FN_INVALIDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_invalidate)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_FN_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_read)

[NDK_FN_RECEIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_receive)

[NDK_FN_SEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_send)

[NDK_FN_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_write)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)