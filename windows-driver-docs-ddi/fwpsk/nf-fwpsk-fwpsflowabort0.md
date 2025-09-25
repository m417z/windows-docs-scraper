# FwpsFlowAbort0 function

## Description

The **FwpsFlowAbort0** function aborts a data flow.

**Note** **FwpsFlowAbort0** is a specific version of **FwpsFlowAbort**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `flowId` [in]

A run-time identifier that specifies the data flow that is being aborted. The run-time identifier for a data flow is provided to a callout driver through the FWPS_METADATA_FIELD_FLOW_HANDLE metadata value that the filter engine provided to the callout driver's [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function.

## Return value

The
**FwpsFlowAbort0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The flow was aborted. |
| **Other status codes** | An error occurred. |

## Remarks

 A callout driver can call the **FwpsFlowAbort0** function to abort a data flow.
The filter engine calls the
[flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0) callout function when the flow is terminated so that the callout driver can clean up
the context associated with the flow.

## See also

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0)