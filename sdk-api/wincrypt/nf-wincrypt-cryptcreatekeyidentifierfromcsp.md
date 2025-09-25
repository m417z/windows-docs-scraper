# CryptCreateKeyIdentifierFromCSP function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptCreateKeyIdentifierFromCSP** function creates a key identifier from a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)).

This function converts a [PUBLICKEYSTRUC](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-publickeystruc) of a CSP
into an [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly)
[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure and encodes it. The encoded structure is then [hashed](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) with the SHA1 algorithm to obtain the key identifier.

## Parameters

### `dwCertEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pszPubKeyOID` [in]

A pointer to the public key [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). A value that is not **NULL** overrides the default OID obtained from the **aiKeyAlg** member of the structure pointed to by *pPubKeyStruc*. To use the default OID, set *pszPubKeyOID* to **NULL**.

### `pPubKeyStruc` [in]

A pointer to a
[PUBLICKEYSTRUC](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-publickeystruc) structure. In the default case, the **aiKeyAlg** member of the structure pointed to by *pPubKeyStruc* is used to find the public key OID. When the value of *pszPubKeyOID* is not **NULL**, it overrides the default.

### `cbPubKeyStruc` [in]

The size, in bytes, of the [PUBLICKEYSTRUC](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-publickeystruc).

### `dwFlags` [in]

Reserved for future use and must be zero.

### `pvReserved` [in]

Reserved for future use and must be **NULL**.

### `pbHash` [out]

A pointer to a buffer to receive the [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the public key and the key identifier.

To get the size of this information for memory allocation purposes, set this parameter to **NULL**. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbHash` [in, out]

A pointer to a **DWORD** that specifies the size, in bytes, of the buffer pointed to by the *pbHash* parameter. When the function returns, the **DWORD** contains the number of bytes stored in the buffer. Using SHA1 hashing, the length of the required buffer is twenty.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**).
For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CryptEnumKeyIdentifierProperties](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumkeyidentifierproperties)

[CryptGetKeyIdentifierProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyidentifierproperty)

[CryptSetKeyIdentifierProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyidentifierproperty)

[Key Identifier Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)