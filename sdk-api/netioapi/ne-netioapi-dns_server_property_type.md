## Description

Defines constants that specify the validity of the property held in the [DNS_SERVER_PROPERTY::Property](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_server_property) member.

## Constants

### `DnsServerInvalidProperty:0`

Specifies that the [DNS_SERVER_PROPERTY::Property](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_server_property) member doesn't contain a valid DNS server property.

### `DnsServerDohProperty`

Specifies that the *DohSettings* union member contained in the [DNS_SERVER_PROPERTY::Property](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_server_property) member points to a valid DNS-over-HTTPS server property.

## Remarks

## See also

* [DNS_SERVER_PROPERTY](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_server_property)