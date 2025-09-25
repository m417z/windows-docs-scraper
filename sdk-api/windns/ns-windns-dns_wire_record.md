# DNS_WIRE_RECORD structure

## Description

The **DNS_WIRE_RECORD** structure contains information about a DNS wire record transmitted across the network as specified in section 4.1.3 of [RFC 1035](https://www.ietf.org/rfc/rfc1035.txt).

## Members

### `RecordType`

A value that represents the RR [DNS Response Type](https://learn.microsoft.com/windows/desktop/DNS/dns-constants). **RecordType** determines the format of record data that follows the **DNS_WIRE_RECORD** structure. For example, if the value of **RecordType** is **DNS_TYPE_A**, the data type of record data is [DNS_A_DATA](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsquery_a).

### `RecordClass`

A value that represents the RR [DNS Record Class](https://learn.microsoft.com/windows/desktop/DNS/dns-constants).

### `TimeToLive`

The DNS Resource Record's Time To Live value (TTL), in seconds.

### `DataLength`

The length, in bytes, of the DNS record data that follows the **DNS_WIRE_RECORD**.

## Remarks

When constructing a DNS message, the **DNS_WIRE_RECORD** structure is immediately followed by the record data and is preceded by the DNS RR's domain name.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DNS_WIRE_QUESTION](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_wire_question)