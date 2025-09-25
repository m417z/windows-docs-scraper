# DNS_SIG_DATAA structure

## Description

The **DNS_RRSIG_DATA** structure represents a DNS
Security Extensions (DNSSEC) cryptographic signature (SIG) resource record (RR) as specified in [RFC 4034](https://www.ietf.org/rfc/rfc4034.txt).

## Members

### `wTypeCovered`

The [DNS Record Type](https://learn.microsoft.com/windows/win32/DNS/dns-constants) of the signed RRs.

### `chAlgorithm`

A value that specifies the algorithm used to generate **Signature**. The possible values are shown in the following table.

| Value | Meaning |
| --- | --- |
| **1** | RSA/MD5 ([RFC 2537](https://www.ietf.org/rfc/rfc2537.txt)) |
| **2** | Diffie-Hellman ([RFC 2539](https://www.ietf.org/rfc/rfc2539.txt)) |
| **3** | DSA ([RFC 2536](https://www.ietf.org/rfc/rfc2536.txt)) |
| **4** | Elliptic curve cryptography |
| **5** | RSA/SHA-1 ([RFC 3110](https://www.ietf.org/rfc/rfc3110.txt)) |

### `chLabelCount`

The number of labels in the original signature RR owner name as specified in section 3.1.3 of [RFC 4034](https://www.ietf.org/rfc/rfc4034.txt).

### `dwOriginalTtl`

The Time-to-Live (TTL) value of the RR set signed by **Signature**.

### `dwExpiration`

The expiration date of **Signature**, expressed in seconds since the beginning of January 1, 1970, Greenwich Mean Time (GMT), excluding leap seconds.

### `dwTimeSigned`

The date and time at which **Signature** becomes valid, expressed in seconds since the beginning of January 1, 1970, Greenwich Mean Time (GMT), excluding leap seconds.

### `wKeyTag`

A value that represents the method to choose which public key is used to verify **Signature** as specified Appendix B of [RFC 4034](https://www.ietf.org/rfc/rfc4034.txt).

### `wSignatureLength`

### `pNameSigner`

A pointer to a string that represents the name of the **Signature** generator.

### `size_is`

### `size_is.wSignatureLength`

### `Signature`

A **BYTE** array that contains the RR set signature as specified in section 3.1.8 of [RFC 4034](https://www.ietf.org/rfc/rfc4034.txt).

#### - Pad

Reserved for padding. Do not use.

## Remarks

The
**DNS_RRSIG_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

> [!NOTE]
> The windns.h header defines DNS_SIG_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DNS Structures](https://learn.microsoft.com/windows/win32/DNS/dns-structures)

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)