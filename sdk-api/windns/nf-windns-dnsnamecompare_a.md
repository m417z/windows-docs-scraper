# DnsNameCompare_A function

## Description

The
**DnsNameCompare** function compares two DNS names. Like many DNS functions, the
**DnsNameCompare** function type is implemented in multiple forms to facilitate different character encoding. Based on the character encoding involved, use one of the following functions:

* **DnsNameCompare_A** (_A for ANSI encoding)
* **DnsNameCompare_W** (_W for Unicode encoding)
* **DnsNameCompare_UTF8** (_UTF8 for Unicode encoding)

## Parameters

### `pName1` [in]

A pointer to a string that represents the first DNS name of the comparison pair.

### `pName2` [in]

A pointer to a string that represents the second DNS name of the comparison pair.

## Return value

Returns **TRUE** if the compared names are equivalent, **FALSE** if they are not.

## Remarks

Name comparisons are not case sensitive, and trailing dots are ignored.

As with other DNS comparison functions, the
**DnsNameCompare** function deems different encoding as an immediate indication of differing values, and as such, the same names with different characters encoding will not be reported identically.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a)

[DnsRecordCompare](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordcompare)

[DnsRecordSetCompare](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordsetcompare)