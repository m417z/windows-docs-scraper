## Description

Represents the DNS settings that can be configured on a given interface by calling the [**SetInterfaceDnsSettings**](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-setinterfacednssettings) function or retrieved for a given interface by calling the [**GetInterfaceDnsSettings**](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-getinterfacednssettings) function.

## Members

### `Version`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Must be set to **DNS_INTERFACE_SETTINGS_VERSION1**.

### `Flags`

Type: **[ULONG64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A bitmap of the following options.
**DNS_SETTING_IPV6** (0x0001). Configures the interface settings only for the IPv6 networking stack. If this option is set, then any IP addresses specified in the *NameServer* or *ProfileNameServer* members must be IPv6 addresses. By default, the DNS interface settings specified in this structure are applied only to the IPv4 networking stack.

**DNS_SETTING_NAMESERVER** (0x0002). Configures static adapter DNS servers on the specified interface via the *NameServer* member.

**DNS_SETTING_SEARCHLIST** (0x0004). Configures the connection-specific DNS suffix search list for the given adapter via the *SearchList* member.

**DNS_SETTING_REGISTRATION_ENABLED** (0x0008). Enables or disables the dynamic DNS registration for the given adapter. This is system-enabled by default.

**DNS_SETTING_DOMAIN** (0x0020). Configures the connection-specific DNS suffix for the given adapter via the *Domain* member.

**DNS_SETTINGS_ENABLE_LLMNR** (0x0080). Enables or disables name resolution using LLMNR and mDNS on the specified adapter. This is system-enabled by default.

**DNS_SETTINGS_QUERY_ADAPTER_NAME** (0x0100). Enables or disables the use of the adapter name as a suffix for DNS queries. This is system-enabled by default.

**DNS_SETTING_PROFILE_NAMESERVER** (0x0200). Configures static profile DNS servers on the specified interface via the *ProfileNameServer* member.

### `Domain`

Type: **[PWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A NULL-terminated wide string containing the adapter domain name.

### `NameServer`

Type: **[PWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A NULL-terminated wide string containing a series of comma- or space-separated DNS servers. For example, L"1.1.1.1 8.8.8.8", or L"1.1.1.1,8.8.8.8".
If the **DNS_SETTING_IPV6** flag is present, then the servers must be IPv6 addresses. For example, L"2606:4700:4700::1001,2606:4700:4700::1111".

### `SearchList`

Type: **[PWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A NULL-terminated wide string containing a series of comma- or space-separated search names. For example, L"contoso1.com contoso2.com", or L"contoso1.com, contoso2.com".

### `RegistrationEnabled`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

**TRUE** to enable adapter dynamic registration; **FALSE** to disable it.

### `RegisterAdapterName`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

**TRUE** to enable adapter name registration; **FALSE** to disable it.

### `EnableLLMNR`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

**TRUE** to enable mDNS and LLMNR on the given interface; **FALSE** to disable them.

### `QueryAdapterName`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

**TRUE** if the adapter name should be used as a search suffix; otherwise **FALSE**.

### `ProfileNameServer`

Type: **[PWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A NULL-terminated wide string containing a series of comma- or space-separated DNS servers. For example, L"1.1.1.1 8.8.8.8" or L"1.1.1.1,8.8.8.8".
If the **DNS_SETTING_IPV6** flag is present, then the servers must be IPv6 addresses. For example, L"2606:4700:4700::1001,2606:4700:4700::1111".

## Remarks

## See also

* [GetInterfaceDnsSettings](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-getinterfacednssettings)
* [SetInterfaceDnsSettings](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-setinterfacednssettings)