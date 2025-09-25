# FWPM_PROVIDER_CONTEXT_SUBSCRIPTION0 structure

## Description

The **FWPM_PROVIDER_CONTEXT_SUBSCRIPTION0** structure is used to subscribe for change notifications.

## Members

### `enumTemplate`

Notifications are only dispatched for objects that match the template. If the template is **NULL**, it matches all objects.

See [FWPM_PROVIDER_CONTEXT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context_enum_template0) for more information

### `flags`

The notifications to subscribe to, as one of the following values.

| Subscription flag | Meaning |
| --- | --- |
| **FWPM_SUBSCRIPTION_FLAG_NOTIFY_ON_ADD** | Subscribe to provider add notifications. |
| **FWPM_SUBSCRIPTION_FLAG_NOTIFY_ON_DELETE** | Subscribe to provider delete notifications. |

### `sessionKey`

Uniquely identifies this session.

## Remarks

**FWPM_PROVIDER_CONTEXT_SUBSCRIPTION0** is a specific implementation of FWPM_PROVIDER_CONTEXT_SUBSCRIPTION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_PROVIDER_CONTEXT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context_enum_template0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)