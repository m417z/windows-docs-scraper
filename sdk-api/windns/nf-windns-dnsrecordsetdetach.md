# DnsRecordSetDetach function

## Description

The **DnsRecordSetDetach** function detaches the first record set from a specified list of DNS records.

## Parameters

### `pRecordList` [in, out]

A pointer, on input, to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the list prior to the detachment of the first DNS record in the list of DNS records. A pointer, on output to a **DNS_RECORD** structure that contains the list subsequent to the detachment of the DNS record.

## Return value

On return, the **DnsRecordSetDetach** function points to the detached DNS record set.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a)

[DnsRecordCompare](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordcompare)

[DnsRecordSetCompare](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordsetcompare)