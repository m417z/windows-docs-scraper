# FWPM_PROVIDER_SUBSCRIPTION0 structure

## Description

The **FWPM_PROVIDER_SUBSCRIPTION0** structure is used to subscribe for change notifications.

## Members

### `enumTemplate`

[unique]

 Enumeration template for limiting the subscription.

See [FWPM_PROVIDER_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_enum_template0) for more information.

### `flags`

Possible values:

| Value | Meaning |
| --- | --- |
| **FWPM_SUBSCRIPTION_FLAG_NOTIFY_ON_ADD** | Subscribe to provider add notifications. |
| **FWPM_SUBSCRIPTION_FLAG_NOTIFY_ON_DELETE** | Subscribe to provider delete notifications. |

### `sessionKey`

Uniquely identifies the session.

## Remarks

Notifications are only dispatched for providers that match the template.

If
the template is **NULL**, it matches all providers.

**FWPM_PROVIDER_SUBSCRIPTION0** is a specific implementation of FWPM_PROVIDER_SUBSCRIPTION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_PROVIDER_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_enum_template0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)