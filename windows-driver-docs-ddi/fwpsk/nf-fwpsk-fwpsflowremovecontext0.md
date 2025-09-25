# FwpsFlowRemoveContext0 function

## Description

The
**FwpsFlowRemoveContext0** function removes a previously associated context from a data flow.

**Note** **FwpsFlowRemoveContext0** is a specific version of **FwpsFlowRemoveContext**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `flowId` [in]

A run-time identifier that specifies the data flow from which to remove the context. The run-time
identifier for a data flow is provided to a callout driver through the FWPS_METADATA_FIELD_FLOW_HANDLE
metadata value that was passed to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function.

### `layerId` [in]

The run-time identifier for the filtering layer from which the context is being removed. For more
information, see
[Run-time Filtering Layer
Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-). A callout driver should specify the same identifier that it specified when it called
the
[FwpsFlowAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowassociatecontext0) function to associate the context with the data flow.

### `calloutId` [in]

The run-time identifier for the callout in the filter engine. This identifier was returned when
the callout driver called either the
[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0) or
[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1) functions to
register the callout with the filter engine.

## Return value

The
**FwpsFlowRemoveContext0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The context was successfully removed from the data flow. |
| **STATUS_UNSUCCESSFUL** | There is no context currently associated with the data flow. |
| **STATUS_PENDING** | An active callout classification is in progress. |
| **Other status codes** | An error occurred. |

## Remarks

If the
**FwpsFlowRemoveContext0** function returns STATUS_SUCCESS,
**FwpsFlowRemoveContext0** calls the
[flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0) callout function
synchronously. If
**FwpsFlowRemoveContext0** returns STATUS_PENDING,
**FwpsFlowRemoveContext0** calls
*flowDeleteFn* asynchronously because an active callout classification is in progress.

## See also

[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0)

[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1)

[FwpsFlowAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowassociatecontext0)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0)