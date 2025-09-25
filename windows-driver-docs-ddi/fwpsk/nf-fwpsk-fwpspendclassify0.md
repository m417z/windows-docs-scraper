# FwpsPendClassify0 function

## Description

A callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function calls
**FwpsPendClassify0** to pend the current classify request. After the request is pended, the callout driver must complete
the processing of the classify request asynchronously by calling
[FwpsCompleteClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscompleteclassify0).

**Note** **FwpsPendClassify0** is a specific version of **FwpsPendClassify**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `classifyHandle` [in]

The classification handle that identifies the callout driver's processing at the current layer.
This handle is obtained by calling
[FwpsAcquireClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquireclassifyhandle0).

### `filterId` [in]

The value of the
**FilterId** member of the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function's
*filter* parameter. For more information about the
**FilterId** member, see
[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1).

### `flags` [in]

Reserved for future use. Set to zero.

### `classifyOut` [in, out]

Set to the
*classifyOut* parameter of the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function. The
*classifyOut* parameter of
*classifyFn* is listed as an output parameter in the header, but it contains enough information on
input to be useful to the engine when passed to
**FwpsPendClassify**.

## Return value

The
**FwpsPendClassify0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The classify request was successfully pended. |
| **STATUS_FWP_CANNOT_PEND** | The engine does not allow asynchronous classification at the layer from which the call was made. |
| **Other status codes** | An error occurred. |

## Remarks

**FwpsPendClassify0** puts the classification of the indicated event in a pended state. A callout
driver typically pends classification so that more processing can be done outside the scope of the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function. The callout driver can
then pass the classification handle and any other pertinent data about the indication to a function with
less impact on performance than the driver callout functions. When processing is complete, the callout
must call
[FwpsCompleteClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscompleteclassify0) to remove
the pended state. At the time of the call to FwpsCompleteClassify, the callout driver must return a
filled-out
[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0) structure just as it
would in an inline classification.

FwpsPendClassify0 increments the reference count for the classification handle passed in the
*classifyHandle* parameter. After the callout driver calls this function, it can call
[FwpsReleaseClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreleaseclassifyhandle0) to release the local instance. When [FwpsCompleteClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscompleteclassify0) is called, the
reference to the handle will be decremented automatically.

## See also

[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0)

[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1)

[FwpsAcquireClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquireclassifyhandle0)

[FwpsCompleteClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscompleteclassify0)

[FwpsReleaseClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreleaseclassifyhandle0)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)