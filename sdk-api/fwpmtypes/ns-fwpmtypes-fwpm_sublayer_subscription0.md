# FWPM_SUBLAYER_SUBSCRIPTION0 structure

## Description

The **FWPM_SUBLAYER_SUBSCRIPTION0** structure is used to subscribe for change notifications.

## Members

### `enumTemplate`

 Enumeration template for limiting the subscription.

See [FWPM_SUBLAYER_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_sublayer_enum_template0) for more information.

### `flags`

A combination of the following values.

| Subscription flag | Meaning |
| --- | --- |
| **FWPM_SUBSCRIPTION_FLAG_NOTIFY_ON_ADD** | Subscribe to sublayer add notifications. |
| **FWPM_SUBSCRIPTION_FLAG_NOTIFY_ON_DELETE** | Subscribe to sublayer delete notifications. |

### `sessionKey`

Uniquely identifies this session.

## Remarks

Notifications are only dispatched for sublayers that match the template.

If
the template is **NULL**, it matches all sublayers.

**FWPM_SUBLAYER_SUBSCRIPTION0** is a specific implementation of FWPM_SUBLAYER_SUBSCRIPTION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_SUBLAYER_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_sublayer_enum_template0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)