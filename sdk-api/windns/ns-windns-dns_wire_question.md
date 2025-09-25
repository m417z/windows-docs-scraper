# DNS_WIRE_QUESTION structure

## Description

The **DNS_WIRE_QUESTION** structure contains information about a DNS question transmitted across the network as specified in section 4.1.2 of [RFC 1035](https://www.ietf.org/rfc/rfc1035.txt)..

## Members

### `QuestionType`

A value that represents the question section's [DNS Question Type](https://learn.microsoft.com/windows/desktop/DNS/dns-constants).

### `QuestionClass`

A value that represents the question section's [DNS Question Class](https://learn.microsoft.com/windows/desktop/DNS/dns-constants).

## Remarks

When constructing a DNS message, the question name must precede the **DNS_WIRE_QUESTION** structure.

## See also

[DNS_WIRE_RECORD](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_wire_record)