# DNS_WKS_DATA structure

## Description

The
**DNS_WKS_DATA** structure represents a DNS well-known services (WKS) record as specified in section 3.4.2 of [RFC 1035](https://www.ietf.org/rfc/rfc1035.txt).

## Members

### `IpAddress`

An [IP4_ADDRESS](https://learn.microsoft.com/windows/win32/DNS/dns-data-types) data type that contains the IPv4 address for this resource record (RR).

### `chProtocol`

A value that represents the IP protocol for this RR as defined in [RFC 1010](https://www.ietf.org/rfc/rfc1010.txt).

#### Transmission Control Protocol (TCP) (6)

#### User Datagram Protocol (UDP) (17)

### `BitMask`

A variable-length bitmask whose bits correspond to the port number of well known services offered by the protocol specified in **chProtocol**. The bitmask has one bit for every port of the supported protocol, but must be a multiple of a **BYTE**. Bit 0 corresponds to port 1, bit 1 corresponds to port 2, and so forth for a maximum of 1024 bits.

## Remarks

The
**DNS_WKS_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)