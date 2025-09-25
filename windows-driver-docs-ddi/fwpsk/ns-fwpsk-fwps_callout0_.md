# FWPS_CALLOUT0_ structure

## Description

The **FWPS_CALLOUT0** structure defines the data that is required for a callout driver to register a
callout with the filter engine.

**Note** **FWPS_CALLOUT0** is the specific version of **FWPS_CALLOUT** used in Windows Vista and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 8, [FWPS_CALLOUT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout2_) is available. For Windows 7, [FWPS_CALLOUT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout1_) is available.

## Members

### `calloutKey`

A callout driver-defined **GUID** that uniquely identifies the callout.

### `flags`

Flags that specify callout-specific parameters. Possible flags are:

#### FWP_CALLOUT_FLAG_CONDITIONAL_ON_FLOW

A callout driver can specify this flag when registering a callout that will be added at a layer
that supports data flows. If this flag is specified, the filter engine calls the callout driver's
[classifyFn0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function only if there
is a context associated with the data flow. A callout driver associates a context with a data flow by
calling the
[FwpsFlowAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowassociatecontext0) function.

#### FWP_CALLOUT_FLAG_ALLOW_OFFLOAD

A callout driver specifies this flag to indicate that the callout driver's
[classifyFn0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function is unaffected
by offloading network data processing to offload-capable network interface cards (NICs). If this flag
is not specified, then offloading of network data processing is disabled for all traffic that is
processed by any filters that specify the callout for the filter's action.

### `classifyFn`

A pointer to the callout driver's
[classifyFn0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function. The filter
engine calls this function whenever there is network data to be processed by the callout.

### `notifyFn`

A pointer to the callout driver's
[notifyFn0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_notify_fn0) function. The filter engine calls
this function to notify the callout driver about events that are associated with the callout.

### `flowDeleteFn`

A pointer to the callout driver's
[flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0) callout function. The filter
engine calls this function whenever a data flow that is being processed by the callout is terminated.

If a callout driver does not associate a context with the data flows that the callout processes, then
this member should be set to **NULL**.

## Remarks

A callout driver passes a pointer to an initialized **FWPS_CALLOUT0** structure to the
[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0) function when it
registers a callout with the filter engine.

A callout can set the **FWP_CALLOUT_FLAG_CONDITIONAL_ON_FLOW** flag only for connections on which
the driver is interested in performing stream inspections. This callout will be ignored on all other
connections. Performance will be improved and the driver will not have to maintain unnecessary state
data.

## See also

[FWPS_CALLOUT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout1_)

[FWPS_CALLOUT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout2_)

[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0)

[classifyFn0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn0)

[flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0)

[notifyFn0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_notify_fn0)