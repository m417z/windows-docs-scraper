# CERT_AUTHORITY_KEY_ID2_INFO structure

## Description

The **CERT_AUTHORITY_KEY_ID2_INFO** structure identifies the key used to sign a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) or [CRL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). It differs from the
[CERT_AUTHORITY_KEY_ID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_authority_key_id_info) structure in that the certificate issuer is a
[CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info) instead of a [CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)). Otherwise, the structures are used in the same way.

The key can be identified by an explicit key identifier, by giving a certificate's issuer and serial number, or by both. If both are used, the certificate issuer must ensure that the explicit key identifier, the certificate issuer and the serial number are consistent.

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject) creates an instance of this structure when performed on a
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structure's **Value** member with its the structure's **pszObjId** member set to szOID_AUTHORITY_KEY_IDENTIFIER2.

An instance of this structure can be used as input to [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) to create an appropriate [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension).

## Members

### `KeyId`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains a unique identifier of a public key.

### `AuthorityCertIssuer`

[CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info) that includes the encoded name of the CA that issued the certificate. The **cAltEntry** member of the structure may be set to zero if the name is not to be used to identify the CA.

### `AuthorityCertSerialNumber`

A [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that includes the serial number of the certificate associated with the private key used to sign this certificate. For more information, see
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info).

## See also

[CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info)

[CERT_AUTHORITY_KEY_ID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_authority_key_id_info)