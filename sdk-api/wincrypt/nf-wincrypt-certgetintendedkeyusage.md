# CertGetIntendedKeyUsage function

## Description

The **CertGetIntendedKeyUsage** function acquires the intended key usage bytes from a certificate. The intended key usage can be in either the szOID_KEY_USAGE ("2.5.29.15") or szOID_KEY_ATTRIBUTES ("2.5.29.2") extension.

## Parameters

### `dwCertEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pCertInfo` [in]

A pointer to
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure of the specified certificate.

### `pbKeyUsage` [out]

A pointer to a buffer to receive the intended key usage. The following list shows currently defined values. These can be combined by using bitwise-**OR** operations.

* CERT_DATA_ENCIPHERMENT_KEY_USAGE
* CERT_DIGITAL_SIGNATURE_KEY_USAGE
* CERT_KEY_AGREEMENT_KEY_USAGE
* CERT_KEY_CERT_SIGN_KEY_USAGE
* CERT_KEY_ENCIPHERMENT_KEY_USAGE
* CERT_NON_REPUDIATION_KEY_USAGE
* CERT_OFFLINE_CRL_SIGN_KEY_USAGE

### `cbKeyUsage` [in]

The size, in bytes, of the buffer pointed to by *pbKeyUsage*. Currently, the intended key usage occupies 1 or 2 bytes of data.

## Return value

If the certificate does not have any intended key usage bytes, **FALSE** is returned and *pbKeyUsage* is zeroed. Otherwise, **TRUE** is returned and up to *cbKeyUsage* number of bytes are copied into *pbKeyUsage*. Any remaining bytes not copied are zeroed.

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns zero if none of the required extensions is found.

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)