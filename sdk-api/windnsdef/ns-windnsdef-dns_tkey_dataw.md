# DNS_TKEY_DATAW structure

## Description

The
**DNS_TKEY_DATA** structure represents a DNS TKEY resource record, used to establish and delete an algorithm's shared-secret keys between a DNS resolver and server as specified in [RFC 2930](https://www.ietf.org/rfc/rfc2930.txt).

## Members

### `pNameAlgorithm`

A pointer to a string that represents the name of the key as defined in section 2.1 of [RFC 2930](https://www.ietf.org/rfc/rfc2930.txt).

### `pAlgorithmPacket`

A pointer to a string representing the name of the algorithm as defined in section 2.3 of [RFC 2930](https://www.ietf.org/rfc/rfc2930.txt). **pKey** is used to derive the algorithm specific keys.

### `pKey`

A pointer to the variable-length shared-secret key.

### `pOtherData`

Reserved. Do not use.

### `dwCreateTime`

The date and time at which the key was created, expressed in seconds since the beginning of January 1, 1970, Greenwich Mean Time (GMT), excluding leap seconds.

### `dwExpireTime`

The expiration date of the key, expressed in seconds since the beginning of January 1, 1970, Greenwich Mean Time (GMT), excluding leap seconds.

### `wMode`

A scheme used for key agreement or the purpose of the TKEY DNS Message. Possible values for **wMode** are listed below:

| Value | Meaning |
| --- | --- |
| **DNS_TKEY_MODE_SERVER_ASSIGN** | The key is assigned by the DNS server and is not negotiated. |
| **DNS_TKEY_MODE_DIFFIE_HELLMAN** | The Diffie-Hellman key exchange algorithm is used to negotiate the key. |
| **DNS_TKEY_MODE_GSS** | The key is exchanged through Generic Security Services-Application Program Interface (GSS-API) negotiation. |
| **DNS_TKEY_MODE_RESOLVER_ASSIGN** | The key is assigned by the DNS resolver and is not negotiated. |

### `wError`

An error, expressed in expanded RCODE format that covers TSIG and TKEY RR processing.

| Value | Meaning |
| --- | --- |
| **DNS_RCODE_BADSIG** | The **pSignature** of the [DNS_TSIG_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_tsig_dataw) RR is bad. |
| **DNS_RCODE_BADKEY** | The **pKey** field is bad. |
| **DNS_RCODE_BADTIME** | A timestamp is bad. |

### `wKeyLength`

Length, in bytes, of the **pKey** member.

### `wOtherLength`

The length, in bytes, of the **pOtherData** member.

### `cAlgNameLength`

The length, in bytes, of the **pNameAlgorithm** member.

### `bPacketPointers`

Reserved. Do not use.

## Remarks

The
**DNS_TKEY_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

> [!NOTE]
> The windns.h header defines DNS_TKEY_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DNS_TSIG_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_tsig_dataw)