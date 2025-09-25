# DNS_DS_DATA structure

## Description

The **DNS_DS_DATA** structure represents a DS resource record (RR) as specified in section 2 of [RFC 4034](https://www.ietf.org/rfc/rfc4034.txt) and is used to verify the contents of [DNS_DNSKEY_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd392295(v=vs.85)).

## Members

### `wKeyTag`

A value that represents the method to choose which public key is used to verify **Signature** in [DNS_RRSIG_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_sig_dataw) as specified in Appendix B of [RFC 4034](https://www.ietf.org/rfc/rfc4034.txt). This value is identical to the **wKeyTag** field in **DNS_RRSIG_DATA**.

### `chAlgorithm`

A value that specifies the algorithm defined by [DNS_DNSKEY_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd392295(v=vs.85)). The possible values are shown in the following table.

| Value | Meaning |
| --- | --- |
| **1** | RSA/MD5 ([RFC 2537](https://www.ietf.org/rfc/rfc2537.txt)) |
| **2** | Diffie-Hellman ([RFC 2539](https://www.ietf.org/rfc/rfc2539.txt)) |
| **3** | DSA ([RFC 2536](https://www.ietf.org/rfc/rfc2536.txt)) |
| **4** | Elliptic curve cryptography |
| **5** | RSA/SHA-1 ([RFC 3110](https://www.ietf.org/rfc/rfc3110.txt)) |

### `chDigestType`

A value that specifies the cryptographic algorithm used to generate **Digest**. The possible values are shown in the following table.

| Value | Meaning |
| --- | --- |
| **1** | SHA-1 ([RFC 3174](https://www.ietf.org/rfc/rfc3174.txt)) |

### `wDigestLength`

The length, in bytes. of the message digest in **Digest**. This value is determined by the algorithm type in **chDigestType**.

### `wPad`

Reserved for padding. Do not use.

### `size_is`

### `size_is.wDigestLength`

### `Digest`

A **BYTE** array that contains a cryptographic digest of the DNSKEY RR and RDATA as specified in section 5.1.4 of [RFC 4034](https://www.ietf.org/rfc/rfc4034.txt). Its length is determined by **wDigestLength**.

## Remarks

The
**DNS_DS_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

## See also

[DNS Structures](https://learn.microsoft.com/windows/win32/DNS/dns-structures)

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)