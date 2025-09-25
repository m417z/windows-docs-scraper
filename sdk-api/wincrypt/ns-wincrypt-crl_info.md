# CRL_INFO structure

## Description

The **CRL_INFO** structure contains the information of a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL).

## Members

### `dwVersion`

Version number of the CRL. Currently defined version numbers are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CRL_V1** | version 1 |
| **CRL_V2** | version 2 |

### `SignatureAlgorithm`

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of a signature algorithm and any associated additional parameters.

### `Issuer`

A [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) structure that contains an encoded certificate issuer's name.

### `ThisUpdate`

Indication of the date and time of the CRL's published. If the time is after 1950 and before 2050, it is UTC-time encoded as an 8-byte date/time precise to seconds with a 2-digit year (that is, YYMMDDHHMMSS plus 2 bytes). Otherwise, it is generalized-time encoded as an 8-byte year precise to milliseconds with a 4-byte year.

### `NextUpdate`

Indication of the date and time for the CRL's next available scheduled update. If the time is after 1950 and before 2050, it is UTC-time encoded as an 8-byte date/time precise to seconds with a 2-digit year (that is, YYMMDDHHMMSS plus 2 bytes). Otherwise, it is generalized-time encoded as an 8-byte date time precise to milliseconds with a 4-byte year.

### `cCRLEntry`

Number of elements in the **rgCRLEntry** array.

### `rgCRLEntry`

Array of pointers to
[CRL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_entry) structures. Each of these structures represents a revoked certificate.

### `cExtension`

Number of elements in the **rgExtension** array.

### `rgExtension`

Array of pointers to
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures, each holding information about the CRL.

## See also

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)

[CRL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_entry)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CertVerifyCRLRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycrlrevocation)

[CryptSignAndEncodeCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignandencodecertificate)