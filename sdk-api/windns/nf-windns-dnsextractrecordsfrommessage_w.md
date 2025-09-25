# DnsExtractRecordsFromMessage_W function

## Description

The
**DnsExtractRecordsFromMessage** function type extracts resource records (RR) from a DNS message, and stores those records in a
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure. Like many DNS functions, the
**DnsExtractRecordsFromMessage** function type is implemented in multiple forms to facilitate different character encoding. Based on the character encoding involved, use one of the following functions:

* **DnsExtractRecordsFromMessage_W** (_W for Unicode encoding)
* **DnsExtractRecordsFromMessage_UTF8** (_UTF8 for UTF-8 encoding)

If the
**DnsExtractRecordsFromMessage** function type is used without its suffix (either _W or _UTF8), a compiler error will occur.

## Parameters

### `pDnsBuffer` [in]

A pointer to a [DNS_MESSAGE_BUFFER](https://learn.microsoft.com/windows/desktop/api/windnsdef/ns-windnsdef-dns_message_buffer) structure that contains the DNS response message.

### `wMessageLength` [in]

The size, in bytes, of the message in
*pDnsBuffer*.

### `ppRecord` [out]

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the list of extracted RRs. To free these records, use the
[DnsRecordListFree](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordlistfree) function.

## Return value

Returns success confirmation upon successful completion. Otherwise, returns the appropriate DNS-specific error code as defined in Winerror.h.

## Remarks

The **DnsExtractRecordsFromMessage** function is designed to operate on messages in host byte order. As such, received messages should be converted from network byte order to host byte order before extraction, or before retransmission onto the network. Use the DNS_BYTE_FLIP_HEADER_COUNTS macro to change byte ordering.

The following declaration for **DnsExtractRecordsFromMessage_UTF8** can be found in Windns.h.

``` syntax
DNS_STATUS
WINAPI
DnsExtractRecordsFromMessage_UTF8(
    __in            PDNS_MESSAGE_BUFFER pDnsBuffer,
    __in            WORD                wMessageLength,
    __deref_out     PDNS_RECORD *       ppRecord
    );

```

## See also

[DNS_MESSAGE_BUFFER](https://learn.microsoft.com/windows/desktop/api/windnsdef/ns-windnsdef-dns_message_buffer)

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a)

[DnsRecordListFree](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordlistfree)

[DnsWriteQuestionToBuffer](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnswritequestiontobuffer_utf8)