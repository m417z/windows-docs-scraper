# NDK_FN_SEND_AND_INVALIDATE callback function

## Description

The *NdkSendAndInvalidate* (*NDK_FN_SEND_AND_INVALIDATE*) function posts a send request on an NDK queue pair (QP) and supplies a token to be invalidated at the remote peer upon receive completion.

## Parameters

### `pNdkQp` [in]

A pointer to an NDK queue pair (QP) object
([NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)).

### `RequestContext` [in, optional]

A context value to be returned in the **RequestContext** member of the [NDK_RESULT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result_ex) structure for this request.

### `pSgl`

An array of SGE ([NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge)) structures that represent the buffers holding the data to send.

### `nSge` [in]

The number of SGE structures in the array that is specified in the *pSgl*
parameter.

### `Flags` [in]

A bitwise OR of flags that specify the operations that are allowed. The following flags are supported:

| Value | Meaning |
| --- | --- |
| **NDK_OP_FLAG_SILENT_SUCCESS**<br><br>0x00000001 | If this request succeeds, it does not generate a completion event in the outbound completion queue. However, if it fails, it does generate a completion event in the outbound completion queue. |
| **NDK_OP_FLAG_READ_FENCE**<br><br>0x00000002 | All prior read requests must be complete before the hardware begins processing this request. |
| **NDK_OP_FLAG_SEND_AND_SOLICIT_EVENT**<br><br>0x00000004 | The completion queue for the peer generates a notification. For more information about **NDK_OP_FLAG_SEND_AND_SOLICIT_EVENT**, see the Remarks section. |
| **NDK_OP_FLAG_INLINE**<br><br>0x00000040 | Indicates that the memory referenced by the SGEs should be transferred inline. Also, the **MemoryRegionToken** value in the [NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge) entries might be invalid. Inline requests do not need to limit the number of entries in the SGE list to the **MaxInitiatorRequestSge** value that is specified when the queue pair was created. The amount of memory transferred inline must be within the inline data limits of the queue pair. |
| **NDK_OP_FLAG_DEFER**<br><br>0x00000200 | Indicates to the NDK provider that it may defer indicating the request to hardware for processing. For more information about this flag, see [NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme).<br><br>**Note** This flag is supported only in NDKPI 1.2 (Windows Server 2012 R2) and later. |

### `RemoteToken` [in]

The remote token to be invalidated at the peer upon receive completion. The NDK provider at the receiving peer must abort the connection, as specified by lower layer transport rules, if an invalid token was specified by the sending peer.

## Return value

The
*NdkSendAndInvalidate* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The request was posted successfully. A completion entry will be queued to the completion queue (CQ) when the work request is completed. |
| **STATUS_CONNECTION_INVALID** | The queue pair (QP) is not connected. |
| **Other status codes** | An error occurred. |

## Remarks

You can use the **NDK_OP_FLAG_SEND_AND_SOLICIT_EVENT** flag if you issue multiple, related send requests. Set this flag on the last request in the group.

An NDK consumer can use this flag when issuing multiple, related send requests. The NDK consumer sets this flag only on the last, related send request. The peer will receive all the send requests as normal. However, when the peer receives the last send request (the request with the **NDK_OP_FLAG_SEND_AND_SOLICIT_EVENT** flag set), the completion queue for the peer generates a notification. The notification is generated after the receive request completes. This flag has no meaning to the receiver (peer) unless the receiver has previously called the *NdkArmCq* ([NDK_FN_ARM_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_arm_cq)) function with the notification type set to **NDK_CQ_NOTIFY_SOLICITED**.

**Note** Requests that complete with an error always match the **NDK_CQ_NOTIFY_SOLICITED** notification type.

The NDK consumer should ensure that the *NdkSendAndInvalidate* function is not called if the receiving peer does not support remote invalidation. The consumer must either negotiate this capability using an out-of-band mechanism or not use this function. If the consumer violates this requirement, the provider's behavior is undefined.

Any [NDK_RESULT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result_ex) structure that is added to a completion queue as a result of a call to this function must specify **NdkOperationTypeSend** for the **Type** member. Note that you do not need to specify a value for the **TypeSpecificCompletionOutput** member of the **NDK_RESULT_EX** structure.

## See also

[NDKPI Completion Handling Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-completion-handling-requirements)

[NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme)

[NDKPI Work Request Posting Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-work-request-posting-requirements)

[NDK_FN_ARM_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_arm_cq)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)

[NDK_RESULT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result_ex)

[NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge)