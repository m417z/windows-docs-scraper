# DNS_HEADER structure

## Description

The **DNS_HEADER** structure contains DNS header information used when sending DNS messages as specified in section 4.1.1 of [RFC 1035](https://www.ietf.org/rfc/rfc1035.txt).

## Members

### `Xid`

A value that specifies the unique DNS message identifier.

### `RecursionDesired`

A value that specifies whether recursive name query should be used by the DNS name server.

| Value | Meaning |
| --- | --- |
| 0x00 | Do not use recursive name query. |
| 0x01 | Use recursive name query. |

### `Truncation`

A value that specifies whether the DNS message has been truncated.

| Value | Meaning |
| --- | --- |
| 0x00 | The message is not truncated. |
| 0x01 | The message is truncated. |

### `Authoritative`

A value that specifies whether the DNS server from which the DNS message is being sent is authoritative for the domain name's zone.

| Value | Meaning |
| --- | --- |
| 0x00 | The DNS server is not authoritative in the zone. |
| 0x01 | The DNS server is authoritative in the zone. |

### `Opcode`

A value that specifies the operation code to be taken on the DNS message as defined in section 4.1.1 of [RFC 1035](https://www.ietf.org/rfc/rfc1035.txt) as the **OPCODE** field.

### `IsResponse`

A value that specifies whether the DNS message is a query or a response message.

| Value | Meaning |
| --- | --- |
| 0x00 | The DNS message is a query. |
| 0x01 | The DNS message is a response. |

### `ResponseCode`

The [DNS Response Code](https://learn.microsoft.com/windows/win32/DNS/dns-constants) of the message.

### `CheckingDisabled`

Windows 7 or later: A value that specifies whether checking is supported by the DNS resolver.

| Value | Meaning |
| --- | --- |
| 0x00 | Checking is enabled on the DNS resolver. |
| 0x01 | Checking is disabled on the DNS resolver. |

### `AuthenticatedData`

Windows 7 or later: A value that specifies whether the DNS data following the **DNS_HEADER** is authenticated by the DNS server.

| Value | Meaning |
| --- | --- |
| 0x00 | The DNS data is not authenticated. |
| 0x01 | The DNS data is authenticated. |

### `Reserved`

Reserved. Do not use.

### `RecursionAvailable`

A value that specifies whether recursive name query is supported by the DNS name server.

| Value | Meaning |
| --- | --- |
| 0x00 | Recursive name query is not supported. |
| 0x01 | Recursive name query is supported. |

### `QuestionCount`

The number of queries contained in the question section of the DNS message.

### `AnswerCount`

The number of resource records (RRs) contained in the answer section of the DNS message.

### `NameServerCount`

The number of DNS name server RRs contained in the authority section of the DNS message. This value is the number of DNS name servers the message has traversed in its search for resolution.

### `AdditionalCount`

Reserved. Do not use.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)