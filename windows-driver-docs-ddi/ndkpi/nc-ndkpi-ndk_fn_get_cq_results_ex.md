# NDK_FN_GET_CQ_RESULTS_EX callback function

## Description

The *NdkGetCqResultsEx* (*NDK_FN_GET_CQ_RESULTS_EX*) function removes completions from an NDK completion queue (CQ) object. This function is identical to the *NdkGetCqResults* ([NDK_FN_GET_CQ_RESULTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_cq_results)) function, except that it retrieves an array of [NDK_RESULT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result_ex) structures instead of an array of [NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result) structures.

## Parameters

### `pNdkCq` [in]

A pointer to an NDK completion queue (CQ) object ([NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)).

### `Results`

[]
An array of [NDK_RESULT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result_ex) structures that will be filled with completion results that were removed from the CQ.

### `nResults` [in]

The size, in elements, of the *Results* array. That is, the maximum number of completions to remove from the CQ.

## Return value

The *NDK_FN_GET_CQ_RESULTS_EX* function returns the number of completions that were removed from the CQ.

Zero means there were no completions in the CQ.

## See also

[NDKPI Completion Handling Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-completion-handling-requirements)

[NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)

[NDK_FN_GET_CQ_RESULTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_cq_results)

[NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result)

[NDK_RESULT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result_ex)