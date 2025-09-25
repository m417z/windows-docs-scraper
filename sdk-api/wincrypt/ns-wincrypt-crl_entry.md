# CRL_ENTRY structure

## Description

The **CRL_ENTRY** structure contains information about a single revoked certificate. It is a member of a [CRL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_info) structure.

## Members

### `SerialNumber`

A [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that contains the serial number of a [revoked certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

Leading 0x00 or 0xFF bytes are removed. For more information, see
[CertCompareIntegerBlob](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcompareintegerblob).

### `RevocationDate`

Date that the certificate was revoked. Time is UTC-time encoded as an eight-byte date/time precise to seconds with a two digit year (that is, YYMMDDHHMMSS plus 2 bytes). The date is interpreted as a date between the years 1968 and 2067.

### `cExtension`

Number of elements in the **rgExtension** member array of extensions.

### `rgExtension`

Array of pointers to
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures, each providing information about the revoked certificate.

## See also

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)

[CRL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_info)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))