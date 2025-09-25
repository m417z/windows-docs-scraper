# _NDK_OPERATION_TYPE enumeration

## Description

The **NDK_OPERATION_TYPE** enumeration defines types of NDK operations. Its enumeration values are used in the **Type** member of the [NDK_RESULT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result_ex) structure.

## Constants

### `NdkOperationTypeReceive`

An *NdkReceive* ([NDK_FN_RECEIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_receive)) operation.

### `NdkOperationTypeReceiveAndInvalidate`

An *NdkSendAndInvalidate* ([NDK_FN_SEND_AND_INVALIDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_send_and_invalidate)) operation.

### `NdkOperationTypeSend`

An *NdkSend* ([NDK_FN_SEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_send)) operation.

### `NdkOperationTypeFastRegister`

An *NdkFastRegister* ([NDK_FN_FAST_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_fast_register)) operation.

### `NdkOperationTypeBind`

An *NdkBind* ([NDK_FN_BIND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_bind)) operation.

### `NdkOperationTypeInvalidate`

An *NdkInvalidate* ([NDK_FN_INVALIDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_invalidate)) operation.

### `NdkOperationTypeRead`

An *NdkRead* ([NDK_FN_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_read)) operation.

### `NdkOperationTypeWrite`

An *NdkWrite* ([NDK_FN_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_write)) operation.

## See also

[NDK_RESULT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result_ex)