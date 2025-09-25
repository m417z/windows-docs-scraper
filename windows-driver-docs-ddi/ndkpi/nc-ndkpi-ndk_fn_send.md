# NDK_FN_SEND callback function

## Description

The *NdkSend* (*NDK_FN_SEND*) function posts a send request on an NDK queue pair (QP).

## Parameters

### `pNdkQp` [in]

A pointer to an NDK queue pair (QP) object
([NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)).

### `RequestContext` [in, optional]

A context value to be returned in the **RequestContext** member of the [NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result) structure for this request.

### `pSgl`

An array of SGE structures ([NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge)) that represent the buffers holding the data to send.

### `nSge` [in]

The number of SGE structures in the array that is specified in the *pSgl*
parameter.

### `Flags` [in]

A bitwise OR of flags which specifies the operations that are allowed. The following flags are supported:

| Value | Meaning |
| --- | --- |
| **NDK_OP_FLAG_SILENT_SUCCESS**<br><br>0x00000001 | Indicates the successful completion of this request does not generate a completion event in the outbound completion queue. However, requests that fail do generate an event in the completion queue. |
| **NDK_OP_FLAG_READ_FENCE**<br><br>0x00000002 | Indicates that all prior read requests must be complete before the hardware begins processing this request. |
| **NDK_OP_FLAG_SEND_AND_SOLICIT_EVENT**<br><br>0x00000004 | Indicates that the completion queue for the peer generates a notification. For more information about **NDK_OP_FLAG_SEND_AND_SOLICIT_EVENT**, see the Remarks section. |
| **NDK_OP_FLAG_INLINE**<br><br>0x00000040 | Indicates that the memory referenced by the SGEs should be transferred inline. Also, the **MemoryRegionToken** value in the [NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge) entries might be invalid. Inline requests do not need to limit the number of entries in the SGE list to the **MaxInitiatorRequestSge** value that is specified when the queue pair was created. The amount of memory transferred inline must be within the inline data limits of the queue pair. |
| **NDK_OP_FLAG_DEFER**<br><br>0x00000200 | Indicates to the NDK provider that it may defer indicating the request to hardware for processing. For more information about this flag, see [NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme).<br><br>**Note** This flag is supported only in NDKPI 1.2 (Windows Server 2012 R2) and later. |

## Return value

The
*NdkSend* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The send request was posted successfully. A completion entry will be queued to the completion queue (CQ) when the work request is completed. |
| **STATUS_CONNECTION_INVALID** | The queue pair (QP) is not connected. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkSend* posts a send request on a queue pair (QP).

You can use the **NDK_OP_FLAG_SEND_AND_SOLICIT_EVENT** flag if you issue multiple, related send requests. Set this flag on the last request in the group of related send requests.

An NDK consumer can use this flag when issuing multiple, related send requests. The NDK consumer sets this flag only on the last, related send request. The peer will receive all the send requests as normal. However, when the peer receives the last send request (the request with the **NDK_OP_FLAG_SEND_AND_SOLICIT_EVENT** flag set), the completion queue for the peer generates a notification. The notification is generated after the receive request completes. This flag has no meaning to the receiver (peer) unless the receiver has previously called the *NdkArmCq* ([NDK_FN_ARM_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_arm_cq)) function with the notification type set to **NDK_CQ_NOTIFY_SOLICITED**.

**Note** Requests that complete with an error always match the **NDK_CQ_NOTIFY_SOLICITED** notification type.

## See also

[NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme)

[NDKPI Work Request Posting Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-work-request-posting-requirements)

[NDK_FN_ARM_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_arm_cq)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)

[NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result)

[NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge)