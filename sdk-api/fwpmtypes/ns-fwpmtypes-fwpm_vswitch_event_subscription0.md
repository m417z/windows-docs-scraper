# FWPM_VSWITCH_EVENT_SUBSCRIPTION0 structure

## Description

The **FWPM_VSWITCH_EVENT_SUBSCRIPTION0** structure stores information used to subscribe to notifications about a vSwitch event.

## Members

### `flags`

Type: **UINT32**

This member is reserved for future use.

### `sessionKey`

Type: **GUID**

Identifies the session which created the subscription.

## Remarks

**FWPM_VSWITCH_EVENT_SUBSCRIPTION0** is a specific implementation of FWPM_VSWITCH_EVENT_SUBSCRIPTION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FwpmvSwitchEventSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmvswitcheventsubscribe0)