# FWPM_VSWITCH_EVENT_CALLBACK0 callback function

## Description

The **FWPM_VSWITCH_EVENT_CALLBACK0** function is used to add custom behavior to the vSwitch event subscription process.

## Parameters

### `context` [in, out]

Type: **void***

Optional context pointer. It contains the value of the *context* parameter of the [FwpmvSwitchEventSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmvswitcheventsubscribe0) function.

### `vSwitchEvent` [in]

Type: [FWPM_VSWITCH_EVENT0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_vswitch_event0)*

The vSwitch event information.

## Return value

This callback function does not return a value.

## Remarks

Call [FwpmvSwitchEventSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmvswitcheventsubscribe0) to register this callback function.

**FWPM_VSWITCH_EVENT_CALLBACK0** is a specific implementation of FWPM_VSWITCH_EVENT_CALLBACK. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_VSWITCH_EVENT0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_vswitch_event0)

[FwpmvSwitchEventSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmvswitcheventsubscribe0)