## Description

Represents the DNS settings that can be configured on a given interface by calling the [**SetInterfaceDnsSettings**](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-setinterfacednssettings) function or retrieved for a given interface by calling the [**GetInterfaceDnsSettings**](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-getinterfacednssettings) function.

## Members

### `SettingsV1`

Type: **[DNS_INTERFACE_SETTINGS](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings)**

**SettingsV1.Version** must be set to **DNS_INTERFACE_SETTINGS_VERSION2**.

**SettingsV1.Flags** is configured in the same way as **[DNS_INTERFACE_SETTINGS::Flags](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings)**, with the additional following bitmap option:

**DNS_SETTING_SUPPLEMENTAL_SEARCH_LIST** (0x0800). Configures the connection-specific DNS supplemental suffix search list for the given adapter via the *SupplementalSearchList* member.

### `DisableUnconstrainedQueries`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Reserved.

### `SupplementalSearchList`

Type: **[PWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A NULL-terminated wide string containing a series of comma- or space-separated search names. For example, L"contoso1.com contoso2.com", or L"contoso1.com, contoso2.com".

## Remarks

## See also

* [GetInterfaceDnsSettings](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-getinterfacednssettings)
* [SetInterfaceDnsSettings](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-setinterfacednssettings)