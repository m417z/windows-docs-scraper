# DNS_FREE_TYPE enumeration

## Description

The **DNS_FREE_TYPE** enumeration specifies the type of data to free.

## Constants

### `DnsFreeFlat:0`

The data freed is a flat structure.

### `DnsFreeRecordList`

The data freed is a Resource Record list, and includes subfields of the [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure. Resources freed include structures returned by the [DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a) and [DnsRecordSetCopyEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordsetcopyex) functions.

### `DnsFreeParsedMessageFields`

The data freed is a parsed message field.

## See also

[DNS Enumerations](https://learn.microsoft.com/windows/desktop/DNS/dns-enumerations)

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a)

[DnsQueryConfig](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryconfig)

[DnsRecordSetCopyEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordsetcopyex)