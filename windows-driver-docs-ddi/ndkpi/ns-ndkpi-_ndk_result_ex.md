# _NDK_RESULT_EX structure

## Description

The **NDK_RESULT_EX** structure returns the results for an NDK request operation. It is identical to the [NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result) structure, except that it has additional **Type** and **TypeSpecificCompletionOutput** members.

## Members

### `Status`

The NDK request completion status.

### `BytesTransferred`

The number of bytes transferred. The value of this member is valid only for *NdkReceive* ([NDK_FN_RECEIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_receive)) request completions. The member is undefined for all other NDK request completions.

### `QPContext`

A context value for all requests that are posted over a queue pair (QP). The NDK consumer specified this pointer when it called the *NdkCreateQp* ([NDK_FN_CREATE_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_qp)) function to create the [NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp) object.

### `RequestContext`

A request context value specified by the NDK consumer when a request is posted.

### `Type`

An [NDK_OPERATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ne-ndkpi-_ndk_operation_type) enumeration value that specifies the type of operation that is being completed.

### `ProviderErrorCode`

If **Status** returns STATUS_SUCCESS, then **ProviderErrorCode** must be **zero**.

If **Status** does not return STATUS_SUCCESS, then **zero** indicates the NDK provider does not support the **ProviderErrorCode** capability yet or did not provide an error code. A **non-zero** value provides additional provider information to diagnose the **Status** code.

**ProviderErrorCode** uses padding that's only available on 64-bit systems. On 32-bit systems, this padding isn't available, and when **ProviderErrorCode** returns **zero**, it can cause **null** pointers. This issue occurs when memory is cast incorrectly as the value for the **TypeSpecificCompletionOutput** pointer. It's important to note that the interface contract is broken if the Provider uses an NDK 2.1 memory layout that includes **ProviderErrorCode**, while the Consumer still uses an NDK 2.0 memory layout without this new field. Therefore, this structure is no longer backwards compatible for 32-bit systems between 2.1 and pre-2.1 versions.

### `TypeSpecificCompletionOutput`

The type-specific completion output, if any. If the **Type** member is **NdkOperationTypeReceiveAndInvalidate**, this member is a 32-bit field, which contains the token to be invalidated before signaling this completion. Otherwise, this member is undefined.

## See also

[NDK_FN_CREATE_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_qp)

[NDK_OPERATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ne-ndkpi-_ndk_operation_type)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)

[NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result)