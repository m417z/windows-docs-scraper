# NDK_FN_WRITE callback function

## Description

The *NdkWrite* (*NDK_FN_WRITE*) function posts a write request on an NDK queue pair (QP).

## Parameters

### `pNdkQp` [in]

A pointer to an NDK queue pair (QP) object ([NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)).

### `RequestContext` [in, optional]

A context value to be returned in the **RequestContext** member of the [NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result) structure for this request.

### `pSgl`

An array of SGE structures ([NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge)) that represent the buffers holding the data to write.

### `nSge` [in]

The number of SGE structures in the array that is specified in the *pSgl*
parameter.

### `RemoteAddress` [in]

The remote address to write to, provided in the local host's byte order. The NDK consumer might have added an offset to the remotely-provided value.

### `RemoteToken` [in]

The remotely-provided memory token, an opaque array of bytes from the NDK consumer.

### `Flags` [in]

A bitwise OR of flags which specifies the operations that are allowed. The following flags are supported:

| Value | Meaning |
| --- | --- |
| **NDK_OP_FLAG_SILENT_SUCCESS**<br><br>0x00000001 | Indicates the successful completion of this request but does not generate a completion event in the outbound completion queue. However, requests that fail do generate a completion in the completion queue. |
| **NDK_OP_FLAG_READ_FENCE**<br><br>0x00000002 | Indicates that all prior read requests must be complete before the hardware begins processing this request. |
| **NDK_OP_FLAG_DEFER**<br><br>0x00000200 | Indicates to the NDK provider that it may defer indicating the request to hardware for processing. For more information about this flag, see [NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme).<br><br>**Note** This flag is supported only in NDKPI 1.2 (Windows Server 2012 R2) and later. |

## Return value

The *NdkWrite* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The request was posted successfully. A completion entry will be queued to the completion queue (CQ) when the work request is completed. |
| **STATUS_CONNECTION_INVALID** | The queue pair (QP) is not connected. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkWrite* posts a write request on a queue pair (QP).

## See also

[NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme)

[NDKPI Work Request Posting Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-work-request-posting-requirements)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)

[NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result)

[NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge)