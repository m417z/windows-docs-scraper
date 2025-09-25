# _NDK_RESULT structure

## Description

The **NDK_RESULT** structure returns the results for an NDK request operation.

## Members

### `Status`

The NDK request completion status.

### `BytesTransferred`

The number of bytes transferred. The value of this member is valid only for *NdkReceive* ([NDK_FN_RECEIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_receive)) request completions. The member is undefined for all other NDK request completions.

### `QPContext`

A context value for all requests that are posted over a queue pair (QP). The NDK consumer specified this pointer when it called the *NdkCreateQp* ([NDK_FN_CREATE_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_qp)) function to create the [NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp) object.

### `RequestContext`

A request context value specified by the NDK consumer when a request is posted.

## Remarks

 The *NdkGetCqResults* ([NDK_FN_GET_CQ_RESULTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_cq_results)) function gets an array of **NDK_RESULT** structures that are filled with completion results that were removed from the CQ.

## See also

[NDK_FN_CREATE_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_qp)

[NDK_FN_GET_CQ_RESULTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_cq_results)

[NDK_FN_RECEIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_receive)