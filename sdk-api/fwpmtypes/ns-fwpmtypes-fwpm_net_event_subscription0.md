# FWPM_NET_EVENT_SUBSCRIPTION0 structure

## Description

The **FWPM_NET_EVENT_SUBSCRIPTION0** structure stores information used to subscribe to notifications about a network event.

## Members

### `enumTemplate`

Address of an [FWPM_NET_EVENT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_enum_template0) structure. Notifications are only dispatched for objects that match the template. If
**enumTemplate** is **NULL**, it matches all objects.

### `flags`

Unused.

### `sessionKey`

Identifies the session which created the subscription.

## Remarks

**FWPM_NET_EVENT_SUBSCRIPTION0** is a specific implementation of FWPM_NET_EVENT_SUBSCRIPTION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.