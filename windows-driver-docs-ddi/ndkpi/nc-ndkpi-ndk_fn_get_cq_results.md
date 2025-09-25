# NDK_FN_GET_CQ_RESULTS callback function

## Description

The *NdkGetCqResults* (*NDK_FN_GET_CQ_RESULTS*) function removes completions from an NDK completion queue (CQ) object.

## Parameters

### `pNdkCq` [in]

A pointer to an NDK completion queue (CQ) object ([NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)).

### `Results`

[]
An array of [NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result) structures that will be filled with completion results that were removed from the CQ.

### `nResults` [in]

The size, in elements, of the *Results* array. That is, the maximum number of completions to remove from the CQ.

## Return value

The *NDK_FN_GET_CQ_RESULTS* function returns the number of completions that were removed from the CQ.

Zero means there were no completions in the CQ.

## Remarks

*NdkGetCqResults* removes completions from a completion queue (CQ).

## See also

[NDKPI Completion Handling Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-completion-handling-requirements)

[NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)

[NDK_CQ_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq_dispatch)

[NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result)