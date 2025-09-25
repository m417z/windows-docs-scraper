## Description

Contains a pointer to a DNS server property. The type of the property depends on the value of [DNS_SERVER_PROPERTY::Type](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_server_property).

## Members

### `DohSettings`

If [DNS_SERVER_PROPERTY::Type](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_server_property) is set to *DnsServerDohProperty*, then *DohSettings* points to a valid DNS-over-HTTPS server property.

## Remarks

## See also

* [DNS_SERVER_PROPERTY](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-dns_server_property)