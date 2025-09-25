# DnsRecordSetCompare function

## Description

The
**DnsRecordSetCompare** function compares two RR sets.

## Parameters

### `pRR1` [in, out]

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the first DNS RR set of the comparison pair.

### `pRR2` [in, out]

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the second DNS resource record set of the comparison pair.

### `ppDiff1` [out, optional]

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) pointer that contains the list of resource records built as a result of the arithmetic performed on them: **pRRSet1** minus **pRRSet2**.

### `ppDiff2` [out, optional]

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) pointer that contains the list of resource records built as a result of the arithmetic performed on them: **pRRSet2** minus **pRRSet1**.

## Return value

Returns **TRUE** if the compared record sets are equivalent, **FALSE** if they are not.

## Remarks

When comparing record sets, DNS resource records that are stored using different character encoding are treated by the
**DnsRecordSetCompare** function as equivalent. Contrast this to the
[DnsRecordCompare](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordcompare) function, in which equivalent records with different encoding are not returned as equivalent records.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsRecordCompare](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordcompare)