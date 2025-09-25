# DNS_MESSAGE_BUFFER structure

## Description

The
**DNS_MESSAGE_BUFFER** structure stores message information for DNS queries.

## Members

### `MessageHead`

A [DNS_HEADER](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_header) structure that contains the header for the DNS message.

### `MessageBody`

An array of characters that comprises the DNS query or resource records (RR).

## Remarks

The
**DNS_MESSAGE_BUFFER** is used by the system to store DNS query information, and make that information available through various DNS function calls.

The [DnsWriteQuestionToBuffer](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnswritequestiontobuffer_utf8)
method should be used to write a DNS query into a **DNS_MESSAGE_BUFFER** structure and the [DnsExtractRecordsFromMessage](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsextractrecordsfrommessage_utf8) method should be used to read the DNS RRs from a **DNS_MESSAGE_BUFFER**.

## See also

[DnsExtractRecordsFromMessage](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsextractrecordsfrommessage_utf8)

[DnsWriteQuestionToBuffer](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnswritequestiontobuffer_utf8)