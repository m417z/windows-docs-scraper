# FWPM_NET_EVENT_CALLBACK1 callback function

## Description

The **FWPM_NET_EVENT_CALLBACK1** function is used to add custom behavior to the net event subscription process.

**Note** **FWPM_NET_EVENT_CALLBACK1** is the specific implementation of FWPM_NET_EVENT_CALLBACK used in Windows 8 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7, [FWPM_NET_EVENT_CALLBACK0](https://learn.microsoft.com/windows/win32/api/fwpmu/nc-fwpmu-fwpm_net_event_callback0) is available.

## Parameters

### `context` [in, out]

Type: **void***

Optional context pointer. It contains the value of the *context* parameter of the [FwpmNetEventSubscribe1](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe1) function.

### `event` [in]

Type: **const [FWPM_NET_EVENT2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event2)***

The net event information.

## Remarks

Call [FwpmNetEventSubscribe1](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe1) to register this callback function.