# NDK_FN_SRQ_RECEIVE callback function

## Description

The *NdkSrqReceive* (*NDK_FN_SRQ_RECEIVE*) function posts a receive request on an NDK shared receive queue (SRQ).

## Parameters

### `pNdkSrq` [in]

A pointer to an NDK shared receive queue (SRQ) object
([NDK_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq)).

### `RequestContext` [in, optional]

A context value to be returned in the **RequestContext** member of the [NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result) structure for this request.

### `pSgl`

An array of SGE structures ([NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge)) that represent the buffers to receive incoming data.

### `nSge` [in]

The number of SGE structures in the array that is specified in the *pSgl*
parameter.

## Return value

The
*NdkSrqReceive* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The receive request was posted successfully. A completion entry will be queued to the completion queue (CQ) when the request is completed. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkSrqReceive* posts a receive request to a shared receive queue (SRQ).

## See also

[NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result)

[NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge)

[NDK_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq)