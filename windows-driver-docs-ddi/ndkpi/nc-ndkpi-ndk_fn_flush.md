# NDK_FN_FLUSH callback function

## Description

The *NdkFlush* (*NDK_FN_FLUSH*) function initiates cancelling of the receive and the initiator queue requests that are currently pending on an NDK queue pair (QP) object.

## Parameters

### `pNdkQp` [in]

A pointer to an NDK queue pair (QP) object ([NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)).

## Remarks

*NdkFlush* cancels the receive and the initiator queue requests that are currently pending on a QP. The flushed requests have STATUS_CANCELLED as completion status.

If the NDK consumer wants to verify that all of the requests are flushed after issuing *NdkFlush*, the consumer must empty the CQ until it sees completions for all requests that were queued prior to calling *NdkFlush*.

## See also

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)