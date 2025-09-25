# FWPM_CALLOUT_SUBSCRIPTION0 structure

## Description

The **FWPM_CALLOUT_SUBSCRIPTION0** structure is used to subscribe for change notifications.

## Members

### `enumTemplate`

 A [FWPM_CALLOUT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_callout_enum_template0) structure that is used to limit the subscription.

### `flags`

The notification type(s) received by the subscription.

| Value | Meaning |
| --- | --- |
| **FWPM_SUBSCRIPTION_FLAG_NOTIFY_ON_ADD** | Subscribe to callout add notifications. |
| **FWPM_SUBSCRIPTION_FLAG_NOTIFY_ON_DELETE** | Subscribe to callout delete notifications. |

### `sessionKey`

Uniquely identifies this session.

## Remarks

Notifications are only dispatched for callouts that match the template.

If
the template is **NULL**, it matches all callouts.

**FWPM_CALLOUT_SUBSCRIPTION0** is a specific implementation of FWPM_CALLOUT_SUBSCRIPTION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_CALLOUT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_callout_enum_template0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)