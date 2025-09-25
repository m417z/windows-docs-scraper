# DNS_KEY_DATA structure

## Description

The
**DNS_KEY_DATA** structure represents a DNS key (KEY) resource record (RR) as specified in [RFC 3445](https://www.ietf.org/rfc/rfc3445.txt).

## Members

### `wFlags`

A set of flags that specify whether this is a zone key as described in section 4 of [RFC 3445](https://www.ietf.org/rfc/rfc3445.txt).

### `chProtocol`

A value that specifies the protocol with which **Key** can be used. The possible values are shown in the following table.

| Value | Meaning |
| --- | --- |
| **3** | Domain Name System Security Extensions (DNSSEC) |

### `chAlgorithm`

A value that specifies the algorithm to use with **Key**. The possible values are shown in the following table.

| Value | Meaning |
| --- | --- |
| **1** | RSA/MD5 ([RFC 2537](https://www.ietf.org/rfc/rfc2537.txt)) |
| **2** | Diffie-Hellman ([RFC 2539](https://www.ietf.org/rfc/rfc2539.txt)) |
| **3** | DSA ([RFC 2536](https://www.ietf.org/rfc/rfc2536.txt)) |
| **4** | Elliptic curve cryptography |
| **5** | RSA/SHA-1 ([RFC 3110](https://www.ietf.org/rfc/rfc3110.txt)). [DNS_DNSKEY_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd392295(v=vs.85)) only. |

### `wKeyLength`

The length, in bytes, of **Key**. This value is determined by the algorithm type in **chAlgorithm**.

### `wPad`

Reserved. Do not use.

### `size_is`

### `size_is.wKeyLength`

### `Key`

A **BYTE** array that contains the public key for the algorithm in **chAlgorithm**, represented in base 64, as described in Appendix A of [RFC 2535](https://www.ietf.org/rfc/rfc2535.txt).

## Remarks

The
**DNS_KEY_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

The [DNS_DNSKEY_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd392295(v=vs.85)) structure represents a DNSKEY resource record as specified in section 2 of [RFC 4034](https://www.ietf.org/rfc/rfc4034.txt).

The
[DNS_DNSKEY_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd392295(v=vs.85)) structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

The value of the **wFlags** member for [DNS_DNSKEY_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd392295(v=vs.85)) is a set of flags that specify key properties as described in section 2.1.1 of [RFC 4034](https://www.ietf.org/rfc/rfc4034.txt).

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)