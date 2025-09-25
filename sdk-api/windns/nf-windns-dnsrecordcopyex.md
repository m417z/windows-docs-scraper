# DnsRecordCopyEx function

## Description

The
**DnsRecordCopyEx** function creates a copy of a specified [resource record](https://learn.microsoft.com/windows/desktop/DNS/r-gly) (RR). The
**DnsRecordCopyEx** function is also capable of converting the character encoding during the copy operation.

## Parameters

### `pRecord` [in]

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the RR to be copied.

### `CharSetIn` [in]

A [DNS_CHARSET](https://learn.microsoft.com/windows/desktop/api/windnsdef/ne-windnsdef-dns_charset) value that specifies the character encoding of the source RR.

### `CharSetOut` [in]

A [DNS_CHARSET](https://learn.microsoft.com/windows/desktop/api/windnsdef/ne-windnsdef-dns_charset) value that specifies the character encoding required of the destination record.

## Return value

Successful execution returns a pointer to the (newly created) destination record. Otherwise, returns null.

## Remarks

The *CharSetIn* parameter is used only if the character encoding of the source RR is not specified in *pRecord*.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsRecordSetCopyEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordsetcopyex)