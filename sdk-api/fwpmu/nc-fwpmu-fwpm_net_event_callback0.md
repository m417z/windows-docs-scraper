# FWPM_NET_EVENT_CALLBACK0 callback function

## Description

The **FWPM_NET_EVENT_CALLBACK0** function is used to add custom behavior to the net event subscription process.

**Note** **FWPM_NET_EVENT_CALLBACK0** is the specific implementation of FWPM_NET_EVENT_CALLBACK used in Windows 7. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 8, [FWPM_NET_EVENT_CALLBACK1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nc-fwpmu-fwpm_net_event_callback1) is available.

## Parameters

### `context` [in, out]

Type: **void***

Optional context pointer. It contains the value of the *context* parameter of the [FwpmNetEventSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe0) function.

### `event` [in]

Type: [FWPM_NET_EVENT1](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event1)*

The net event information.

## Remarks

Call [FwpmNetEventSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe0) to register this callback function.

## See also

[FWPM_NET_EVENT1](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event1)

[FwpmNetEventSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe0)