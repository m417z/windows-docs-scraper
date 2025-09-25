# NDK_FN_INVALIDATE callback function

## Description

The *NdkInvalidate* (*NDK_FN_INVALIDATE*) function Invalidates a fast-register NDK memory region (MR) or memory window (MW).

## Parameters

### `pNdkQp` [in]

A pointer to an NDK queue pair (QP) object ([NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)).

### `RequestContext` [in, optional]

A context value to return in the **RequestContext** member of the [NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result) structure for this request.

### `pNdkMrOrMw` [in]

A pointer to either an memory region (MR) object ([NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)) or an memory (MW) object ([NDK_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw)) that is specified in an [NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header) structure. If an MR object is specified, the MR object must have been registered with the *NdkFastRegister* ([NDK_FN_FAST_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_fast_register)) function. The NDK consumer must never specify an MR object that was registered with the *NdkRegister* ([NDK_FN_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_register_mr)) function in the *pNdkMrOrMw* parameter. Access to MR objects registered with the *NdkRegister* (*NDK_FN_REGISTER*)) function can be removed with the NdkDeregisterMr ([NDK_FN_DEREGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_deregister_mr)) function.

### `Flags` [in]

A bitwise OR of flags which specifies the operations that are allowed. The following flags are supported:

| Value | Meaning |
| --- | --- |
| **NDK_OP_FLAG_SILENT_SUCCESS**<br><br>0x00000001 | Indicates the successful completion of this request does not generate a completion event in the outbound completion queue. However, requests that fail do generate an event in the completion queue. |
| **NDK_OP_FLAG_READ_FENCE**<br><br>0x00000002 | Indicates that all prior read requests must be complete before the hardware begins processing this request. |
| **NDK_OP_FLAG_DEFER**<br><br>0x00000200 | Indicates to the NDK provider that it may defer indicating the request to hardware for processing. For more information about this flag, see [NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme).<br><br>**Note** This flag is supported only in NDKPI 1.2 (Windows Server 2012 R2) and later. |

## Return value

The
*NdkInvalidate* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The request was posted successfully. A completion entry will be queued to the CQ when the work request is completed. |
| **STATUS_CONNECTION_INVALID** | The QP is not connected. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkInvalidate* invalidates an NDK fast-register MR or MW.

## See also

[NDKPI Completion Handling Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-completion-handling-requirements)

[NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme)

[NDKPI Work Request Posting Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-work-request-posting-requirements)

[NDK_FN_DEREGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_deregister_mr)

[NDK_FN_FAST_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_fast_register)

[NDK_FN_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_register_mr)

[NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)

[NDK_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw)

[NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)

[NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result)