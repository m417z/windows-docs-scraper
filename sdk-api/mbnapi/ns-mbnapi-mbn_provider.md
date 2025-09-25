# MBN_PROVIDER structure

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_PROVIDER** structure represents a network service provider. It is used by many of the provider-specific methods of [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface).

## Members

### `providerID`

Contains the provider ID. For GSM networks, this string is a concatenation of a 3-digit mobile country code (MCC) and a 2- or 3-digit mobile network code (MNC). For CDMA networks, this string is a 5-digit SID. The maximum length of this string is defined by **MBN_PROVIDERID_LEN** from [MBN_PROVIDER_CONSTANTS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_provider_constants). The caller must free this string by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

### `providerState`

Contains a bitwise OR combination of [MBN_PROVIDER_STATE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_provider_state) values that represent the provider state.

### `providerName`

Contains the provider name. The contents of this member should be ignored when setting the preferred provider list. The maximum length of this string is defined by **MBN_PROVIDERNAME_LEN** from [MBN_PROVIDER_CONSTANTS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_provider_constants). The string can be empty. The caller must free this string by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

### `dataClass`

Contains a bitwise OR combination of [MBN_DATA_CLASS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_data_class) values that indicate which data services are applicable or available for transfer. This member should be ignored when queried for the home provider.

## See also

[MBN_PROVIDER2](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_provider2)