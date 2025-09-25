# FWPM_NET_EVENT_CALLBACK2 callback function

## Description

The **FWPM_NET_EVENT_CALLBACK2** function is used to add custom behavior to the net event subscription process.

**Note** **FWPM_NET_EVENT_CALLBACK2** is the specific implementation of FWPM_NET_EVENT_CALLBACK used in Windows 10, version 1607 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 8, [FWPM_NET_EVENT_CALLBACK1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-fwpm_net_event_callback1) is available. For Windows 7, [FWPM_NET_EVENT_CALLBACK0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-fwpm_net_event_callback0) is available.

## Parameters

### `context` [in, out]

Optional context pointer. It contains the value of the *context* parameter of the [FwpmNetEventSubscribe2](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe2) function.

### `event` [in]

An [FWPM_NET_EVENT3](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event3) struct that contains the event information.

## Remarks

Call [FwpmNetEventSubscribe2](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe2) to register this callback function.

## See also

[FwpmNetEventSubscribe2](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe2)