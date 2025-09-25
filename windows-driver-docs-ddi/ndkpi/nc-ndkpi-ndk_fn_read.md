# NDK_FN_READ callback function

## Description

The *NdkRead* (*NDK_FN_READ*) function posts a read request on an NDK queue pair (QP).

## Parameters

### `pNdkQp` [in]

A pointer to an NDK queue pair (QP) object ([NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)).

### `RequestContext` [in, optional]

A context value to be returned in the **RequestContext** member of the [NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result) structure for this request.

### `pSgl`

An array of SGE structures ([NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge)) that represent the buffers to place incoming data into.

### `nSge` [in]

The number of SGE structures in the array that is specified in the *pSgl*
parameter.

### `RemoteAddress` [in]

A remote address to read from that is presented in the local host's byte order. The NDK consumer can add an offset to the remotely-provided value.

### `RemoteToken` [in]

A remotely-provided memory token that is an opaque array of bytes from the NDK consumer.

### `Flags` [in]

A bitwise OR of flags which specifies the operations that are allowed. The following flags are supported:

| Value | Meaning |
| --- | --- |
| **NDK_OP_FLAG_SILENT_SUCCESS**<br><br>0x00000001 | Indicates the successful completion of this request does not generate a completion event in the outbound completion queue. However, requests that fail do generate an event in the completion queue. |
| **NDK_OP_FLAG_READ_FENCE**<br><br>0x00000002 | Indicates that all prior read requests must be complete before the hardware begins processing this request. |
| **NDK_OP_FLAG_RDMA_READ_LOCAL_INVALIDATE**<br><br>0x00000200 | If this flag is set and the provider also reports **NDK_ADAPTER_FLAG_RDMA_READ_LOCAL_INVALIDATE_SUPPORTED** adapter capability in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure, successful completion of the *NdkRead* function means that the first buffer specified in the *pSgl* parameter is invalidated. Unsuccessful completion leaves the buffer and token in an undefined state. This flag is ignored if the provider does not report **NDK_ADAPTER_FLAG_RDMA_READ_LOCAL_INVALIDATE_SUPPORTED** adapter capability in the **NDK_ADAPTER_INFO** structure.<br><br>**Note** This flag is supported only in NDKPI 1.2 (Windows Server 2012 R2) and later. |
| **NDK_OP_FLAG_DEFER**<br><br>0x00000200 | Indicates to the NDK provider that it may defer indicating the request to hardware for processing. For more information about this flag, see [NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme).<br><br>**Note** This flag is supported only in NDKPI 1.2 (Windows Server 2012 R2) and later. |

## Return value

The
*NdkRead* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The request was posted successfully. A completion entry will be queued to the CQ when the work request is completed. |
| **STATUS_CONNECTION_INVALID** | The QP is not connected. |
| **STATUS_REMOTE_RESOURCES** | The request tried to read beyond the size of the remote memory. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkRead* posts a read request on a queue pair (QP).

## See also

[NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme)

[NDKPI Work Request Posting Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-work-request-posting-requirements)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)

[NDK_FN_ARM_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_arm_cq)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)

[NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result)

[NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge)