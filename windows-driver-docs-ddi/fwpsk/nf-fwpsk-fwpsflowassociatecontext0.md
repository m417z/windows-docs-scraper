# FwpsFlowAssociateContext0 function

## Description

The
**FwpsFlowAssociateContext0** function associates a callout driver-defined context with a data
flow.

**Note** **FwpsFlowAssociateContext0** is a specific version of **FwpsFlowAssociateContext**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `flowId` [in]

A run-time identifier that specifies the data flow with which to associate the context. The
run-time identifier for a data flow is provided to a callout driver through the
FWPS_METADATA_FIELD_FLOW_HANDLE metadata value that was passed to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function.

### `layerId` [in]

The run-time identifier for the filtering layer with which the context is being associated. The context will be associated only with the specified filtering layer. For
more information, see
[Run-time Filtering Layer
Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

### `calloutId` [in]

The run-time identifier for the callout in the filter engine. This identifier was returned when
the callout driver called the
[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0),
[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1), or [FwpsCalloutRegister2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister2) function to
register the callout with the filter engine.

### `flowContext` [in]

The callout driver-defined context to be associated with the data flow. This parameter must not be
zero. This context is opaque to the filter engine.

## Return value

The
**FwpsFlowAssociateContext0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The context was successfully associated with the data flow. |
| **STATUS_INVALID PARAMETER** | Either the *flowContext* parameter is **NULL** or the callout specified by the *calloutID* parameter does not have a [flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0) registered. |
| **STATUS_OBJECT_NAME_EXISTS** | A context is already associated with the data flow. In this case, a callout driver should first call the [FwpsFlowRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowremovecontext0) function to remove the existing context and then call the [FwpsFlowAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowassociatecontext0) function again to associate the new context with the data flow. |
| **Other status codes** | An error occurred. |

## Remarks

When filtering a data flow, a callout driver can call the
**FwpsFlowAssociateContext0** function to associate a context with the data flow. It can then use this
context to preserve any driver-specific data or state information between calls by the filter engine to a
callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function for that data
flow.

There must be a callout in the filter engine at the layer identified by the
*layerId* parameter that has registered a
[flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0) callout function. Otherwise,
the call to the
**FwpsFlowAssociateContext0** function will return STATUS_INVALID_PARAMETER. The filter engine calls that
*flowDeleteFn* callout function when the flow is terminated so that the callout driver can clean up
the context associated with the flow.

You can call **FwpsFlowAssociateContext0** multiple times for the same flow. In each call, you must specify a different callout and a different context—one context per added callout.

The **FwpsFlowAssociateContext0** function associates a single context with a single added callout.

You can associate multiple contexts with a flow. However, each context must be associated with a different callout. The new callout can be at the same layer as the previous one or at a different layer.

For more information and sample code, see [Associating Context with a Data Flow](https://learn.microsoft.com/windows-hardware/drivers/network/associating-context-with-a-data-flow)
and the [Windows Filtering Platform Sample](https://go.microsoft.com/fwlink/p/?LinkId=618934).

## See also

[Associating Context with a Data Flow](https://learn.microsoft.com/windows-hardware/drivers/network/associating-context-with-a-data-flow)

[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0)

[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1)

[FwpsCalloutRegister2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister2)

[FwpsFlowRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowremovecontext0)

[Windows Filtering Platform Sample](https://go.microsoft.com/fwlink/p/?LinkId=618934)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0)