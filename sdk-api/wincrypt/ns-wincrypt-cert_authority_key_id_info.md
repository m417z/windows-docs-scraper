# CERT_AUTHORITY_KEY_ID_INFO structure

## Description

The **CERT_AUTHORITY_KEY_ID_INFO** structure identifies the key used to sign a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) or [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL). This structure differentiates among distinct keys used by the same [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) as, for example, keys changed when an update occurs.

The key can be identified by an explicit key identifier, by giving a certificate's issuer and serial number, or by both. If both are used, the certificate issuer must ensure that the explicit key identifier, the certificate issuer and the serial number are consistent.

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject) creates an instance of this structure when performed on a
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structure's **Value** member with its structure's **pszObjId** member set to szOID_AUTHORITY_KEY_IDENTIFIER.

An instance of this structure can be used as input to [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) to create an appropriate [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension).

## Members

### `KeyId`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains a unique identifier of a public key.

### `CertIssuer`

A [CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the encoded distinguished name of the certification authority that issued the certificate.

### `CertSerialNumber`

A [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the serial number of the certificate associated with the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used to sign this certificate. For more information, see
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info).

## See also

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))