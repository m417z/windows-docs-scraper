# FwpsAcquireClassifyHandle0 function

## Description

The
**FwpsAcquireClassifyHandle0** function generates a classification handle that is used to identify
asynchronous classification operations and requests for writable layer data.

**Note** **FwpsAcquireClassifyHandle0** is a specific version of **FwpsAcquireClassifyHandle**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `classifyContext` [in]

The
*classifyContext* parameter from
[classifyFn1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn1). The WFP engine passes this
value to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

### `flags` [in]

Reserved for future use. Set to 0.

### `classifyHandle` [out]

A pointer to a variable that receives a classification handle. This handle is needed by subsequent
function calls as noted in Remarks.

## Return value

The
**FwpsAcquireClassifyHandle0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | A handle to the classify request was successfully returned. The variable that the *classifyHandle* parameter points to contains the handle for the classify request. |
| **Other status codes** | An error occurred. |

## Remarks

**FwpsAcquireClassifyHandle0** is a support function for asynchronous classification and data
modification. The handle returned by this function is required as a parameter for the following
functions:

* [FwpsPendClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpspendclassify0)
* [FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0)
* [FwpsApplyModifiedLayerData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsapplymodifiedlayerdata0)
* [FwpsCompleteClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscompleteclassify0)
* [FwpsReleaseClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreleaseclassifyhandle0)

For each call to this function, the callout driver must call
[FwpsReleaseClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreleaseclassifyhandle0) to
free the system resources associated with the handle.

## See also

[FwpsCompleteClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscompleteclassify0)

[FwpsPendClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpspendclassify0)

[FwpsReleaseClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreleaseclassifyhandle0)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[classifyFn1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn1)