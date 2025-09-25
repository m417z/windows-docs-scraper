# DnsRecordSetCopyEx function

## Description

The
**DnsRecordSetCopyEx** function creates a copy of a specified resource record set. The
**DnsRecordSetCopyEx** function is also capable of converting the character encoding during the copy operation.

## Parameters

### `pRecordSet` [in]

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the resource record set to be copied.

### `CharSetIn` [in]

A [DNS_CHARSET](https://learn.microsoft.com/windows/desktop/api/windnsdef/ne-windnsdef-dns_charset) value that specifies the character encoding of the source resource record set.

### `CharSetOut` [in]

A [DNS_CHARSET](https://learn.microsoft.com/windows/desktop/api/windnsdef/ne-windnsdef-dns_charset) value that specifies the character encoding required of the destination record set.

## Return value

Successful execution returns a pointer to the newly created destination record set. Otherwise, it returns null.

## Remarks

The *CharSetIn* parameter is used only if the character encoding of the source resource record set is not specified in *pRecordSet*.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsRecordCopyEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordcopyex)