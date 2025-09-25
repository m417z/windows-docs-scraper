## Description

Describes a DNS server property, which is set in the [**DNS_INTERFACE_SETTINGS3**](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings3) structure, and configured through the [**SetInterfaceDnsSettings**](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-setinterfacednssettings) function.

## Members

### `Version`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Must be set to **DNS_INTERFACE_SETTINGS_VERSION1**.

### `ServerIndex`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Must be the index of the corresponding server present in the [**DNS_INTERFACE_SETTINGS3::NameServer**](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings3) or **::ProfileNameServer** member. For proper usage, see the *ServerProperties* and *ProfileServerProperties* members in the topic for the [**DNS_INTERFACE_SETTINGS3**](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_interface_settings3) structure.

### `Type`

Type: **[DNS_SERVER_PROPERTY_TYPE](https://learn.microsoft.com/windows/win32/api/netioapi/ne-netioapi-dns_server_property_type)**

Must be set to **DnsServerDohProperty**. Describes a DNS-over-HTTPS server property.

### `Property`

Type: **[DNS_SERVER_PROPERTY_TYPES](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_server_property_types)**

If the *Type* member is set to **DnsServerDohProperty**, then the **DNS_SERVER_PROPERTY_TYPES::DohSettings** field must point to a valid **DNS_DOH_SERVER_SETTINGS** object.

## Remarks

## See also