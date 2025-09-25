# NDK_FN_RECEIVE callback function

## Description

 The *NdkReceive* (*NDK_FN_RECEIVE*) function posts a receive request on an NDK queue pair (QP).

## Parameters

### `pNdkQp` [in]

A pointer to an NDK queue pair (QP) object
([NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)).

### `RequestContext` [in, optional]

A context value to be returned in the **RequestContext** member of the [NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result) structure for this request.

### `pSgl`

An array of SGE structures ([NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge)) that represent the buffers to receive incoming data.

### `nSge` [in]

The number of SGE structures in the array that is specified in the *pSgl*
parameter.

## Return value

The
*NdkReceive* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The request was posted successfully. A completion entry will be queued to the CQ when the work request is completed. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkReceive* posts a receive request on a queue pair (QP).

## See also

[NDKPI Work Request Posting Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-work-request-posting-requirements)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)

[NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result)

[NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_sge)