# DNS_RRSET structure

## Description

The **DNS_RRSET** structure contains information about a DNS Resource Record (RR) set.

## Members

### `pFirstRR`

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the first DNS RR in the set.

### `pLastRR`

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the last DNS RR in the set.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)