# CRYPT_PROVIDER_DEFUSAGE structure

## Description

The **CRYPT_PROVIDER_DEFUSAGE** structure is used by the [WintrustGetDefaultForUsage](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustgetdefaultforusage) function to retrieve callback information for a provider's default usage.

## Members

### `cbStruct`

Size, in bytes, of the structure.

### `gActionID`

GUID that specifies the provider's default action.

### `pDefPolicyCallbackData`

Pointer to a data buffer used to pass policy-specific data to a policy provider.

### `pDefSIPClientData`

Pointer to a data buffer used to pass subject interface package (SIP) specific data to an SIP provider.

## See also

[CRYPT_PROVIDER_REGDEFUSAGE](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_regdefusage)

[WintrustGetDefaultForUsage](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustgetdefaultforusage)