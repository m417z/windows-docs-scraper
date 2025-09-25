# DnsRecordCompare function

## Description

The
**DnsRecordCompare** function compares two DNS resource records (RR).

## Parameters

### `pRecord1` [in]

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the first DNS RR of the comparison pair.

### `pRecord2` [in]

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the second DNS RR of the comparison pair.

## Return value

Returns **TRUE** if the compared records are equivalent, **FALSE** if they are not.

## Remarks

When comparing records, DNS RRs that are stored using different character encoding are treated by the
**DnsRecordCompare** function as different, even if the records are otherwise equivalent.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsRecordSetCompare](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordsetcompare)