# FWPM_PROVIDER0 structure

## Description

The **FWPM_PROVIDER0** structure stores the state associated with a policy provider.

## Members

### `providerKey`

Uniquely identifies the provider.

If the GUID is zero-initialized in the
call to Add, Base Filtering Engine (BFE) will generate one.

### `displayData`

Allows providers to be annotated in a human-readable form. The [FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwpm_display_data0) structure is required.

### `flags`

Bit flags that indicate information about the persistence of the provider.

| Provider flag | Meaning |
| --- | --- |
| **FWPM_PROVIDER_FLAG_PERSISTENT** | Provider is persistent. |
| **FWPM_PROVIDER_FLAG_DISABLED** | Provider's filters were disabled when the BFE started because the provider has no associated Windows service name, or because the associated service was not set to auto-start. <br><br>**Note** This flag cannot be set when adding new providers. It can only be returned by BFE when getting or enumerating providers. |

### `providerData`

An [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure that contains optional provider-specific data that allows providers to store additional context info with the object.

### `serviceName`

Optional name of the Windows service hosting the provider. This allows
BFE to detect that a provider has been disabled.

## Remarks

**FWPM_PROVIDER0** is a specific implementation of FWPM_PROVIDER. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwpm_display_data0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)