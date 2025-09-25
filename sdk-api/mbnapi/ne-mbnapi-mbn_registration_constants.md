# MBN_REGISTRATION_CONSTANTS enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_REGISTRATION_CONSTANTS** enumerated type contains specific values used by [IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration) interface operations.

## Constants

### `MBN_ROAMTEXT_LEN:64`

The maximum string size of the *roamingText* parameter in the [GetRoamingText](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistration-getroamingtext) method of the [IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration) interface.

### `MBN_CDMA_DEFAULT_PROVIDER_ID:0`

Indicates an unknown provider ID in the *providerID* parameter in the [GetProviderID](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistration-getproviderid) method of the [IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration) interface.