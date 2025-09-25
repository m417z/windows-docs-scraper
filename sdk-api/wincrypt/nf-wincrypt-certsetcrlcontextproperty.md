# CertSetCRLContextProperty function

## Description

The **CertSetCRLContextProperty** function sets an extended property for the specified [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) context.

## Parameters

### `pCrlContext` [in]

A pointer to the
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure.

### `dwPropId` [in]

Identifies the property to be set. The value of *dwPropId* determines the type and content of the *pvData* parameter. Currently defined identifiers and the data type to be returned in *pvData* are listed in the following table.

Usually, only the following properties are set:

* CERT_HASH_PROP_ID
* CERT_SHA1_HASH_PROP_ID
* CERT_MD5_HASH_PROP_ID
* CERT_SIGNATURE_HASH_PROP_ID

| Value | Meaning |
| --- | --- |
| **CERT_ACCESS_STATE_PROP_ID** | Data type for *pvData*: pointer to a **DWORD**<br><br>Sets a **DWORD** value indicating whether write operations to the certificate are persisted. The **DWORD** value is not set if the certificate is in a memory store or in a registry-based store that is opened as read-only. |
| **CERT_ARCHIVED_PROP_ID** | Data type for *pvData*: **NULL**<br><br>Indicates the certificate is skipped during enumerations. A certificate with this property set is found with explicit search operations, such as those used to find a certificate with a specific hash or a serial number. No data in *pvData* is associated with this property. |
| **CERT_AUTO_ENROLL_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Sets a **null**-terminated Unicode string naming the certificate type for which the certificate has been auto enrolled. |
| **CERT_CTL_USAGE_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Sets an array of bytes containing an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoded [CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure. |
| **CERT_DESCRIPTION_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Sets the property displayed by the certificate UI. This property allows the user to describe the certificate's use. |
| **CERT_ENHKEY_USAGE_PROP_ID** | Data type for *pvData*: <br><br>Sets an array of bytes containing an ASN.1 encoded [CERT_ENHKEY_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure. |
| **CERT_FRIENDLY_NAME_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Sets a **null**-terminated Unicode character string that contains the display name for the CRL. |
| **CERT_ISSUER_CHAIN_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID** | Data type for *pvData*: Pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structure.<br><br>Sets a string containing a set of L"*<PUBKEY>*/*<BITLENGTH>*" public key algorithm and bit length pairs. The semicolon, L";", is used as the delimiter.<br><br>The *<PUBKEY>* value identifies the CNG public key algorithm. The following algorithms are supported:<br><br>* L"RSA" (BCRYPT_RSA_ALGORITHM)<br>* L"DSA" (BCRYPT_DSA_ALGORITHM)<br>* L"ECDSA" (SSL_ECDSA_ALGORITHM)<br><br>A *<PUBKEY>*/*<BITLENGTH>* pair is set for each certificate in the CRL issuer chain excluding the leaf. This property can be set when an OCSP response with an independent signer chain is converted to a CRL.<br><br>**Note** This property should not be set for a delegated OCSP signer certificate. A delegated signer certificate is signed with the same key used to sign the subject certificate and is checked there.<br><br>The following is an example:<br><br>: L"RSA/2048;RSA/4096" |
| **CERT_ISSUER_CHAIN_SIGN_HASH_CNG_ALG_PROP_ID** | Data type for *pvData*: Pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structure.<br><br>Sets a string that contains a set of L"*<SIGNATURE>*/*<HASH>*" algorithm pairs. The semicolon, L";", is used as the delimiter between pairs.<br><br>This property is set only when an OCSP response is converted to a CRL. For a delegated OCSP signer certificate, only the algorithm pair for the signer certificate is returned. For an independent OCSP signer certificate chain, an algorithm pair is returned for each certificate in the chain excluding the root.<br><br>The *<SIGNATURE>* value identifies the CNG public key algorithm. The following algorithms are supported:<br><br>* L"RSA" (BCRYPT_RSA_ALGORITHM)<br>* L"DSA" (BCRYPT_DSA_ALGORITHM)<br>* L"ECDSA" (SSL_ECDSA_ALGORITHM)<br><br>The *<HASH>* value identifies the CNG hash algorithm. The following algorithms are supported:<br><br>* L"MD5" (BCRYPT_MD5_ALGORITHM)<br>* L"SHA1" (BCRYPT_SHA1_ALGORITHM)<br>* L"SHA256" (BCRYPT_SHA256_ALGORITHM)<br>* L"SHA384" (BCRYPT_SHA384_ALGORITHM)<br>* L"SHA512" (BCRYPT_SHA512_ALGORITHM)<br><br>The following is an example:<br><br>* L"RSA/SHA256;RSA/SHA256"<br><br>This property is explicitly set by the verify revocation functions. |
| **CERT_ISSUER_PUB_KEY_BIT_LENGTH_PROP_ID** | Data type for *pvData*: Pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structure.<br><br>Sets the length, in bits, of the public key in the CRL issuer certificate. This property is also applicable to an OCSP that has been converted to a CRL.<br><br>This property is explicitly set by the verify revocation functions.<br><br>**Windows 8 and Windows Server 2012:** Support for this property begins. |
| **CERT_KEY_CONTEXT_PROP_ID** | Data type for *pvData*: pointer to a [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context)<br><br>Sets a [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure. |
| **CERT_KEY_IDENTIFIER_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array |
| **CERT_KEY_PROV_HANDLE_PROP_ID** | Data type for *pvData*: pointer to an [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov)<br><br>Sets the provider handle obtained from the CERT_KEY_CONTEXT_PROP_ID. |
| **CERT_KEY_PROV_INFO_PROP_ID** | Data type for *pvData*: pointer to a [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info)<br><br>Sets a pointer to a [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure. |
| **CERT_KEY_SPEC_PROP_ID** | Data type for *pvData*: pointer to a **DWORD**<br><br>Sets a **DWORD** value specifying the private key obtained from CERT_KEY_CONTEXT_PROP_ID property if it exists. Otherwise, if CERT_KEY_PROV_INFO_PROP_ID exists, it is the source of the *dwKeySpec*. |
| **CERT_MD5_HASH_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Sets the MD5 hash. You can compute the hash by using the [CryptHashCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashcertificate) function. |
| **CERT_NEXT_UPDATE_LOCATION_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Sets the ASN.1 encoded [CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info) structure on a CTL. |
| **CERT_PVK_FILE_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Sets a **null**-terminated Unicode, wide character string specifying the name of the file that contains the private key associated with the certificate's public key. |
| **CERT_SHA1_HASH_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Sets the SHA1 hash. You can compute the hash by using [CryptHashCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashcertificate). |
| **CERT_SIGN_HASH_CNG_ALG_PROP_ID** | Data type of *pvData*: Pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structure.<br><br>Sets the L”*<SIGNATURE>*/*<HASH>*” string representing the certificate signature. The *<SIGNATURE>* value identifies the CNG public key algorithm. The following algorithms are supported:<br><br>* L"RSA" (BCRYPT_RSA_ALGORITHM)<br>* L"DSA" (BCRYPT_DSA_ALGORITHM)<br>* L"ECDSA" (SSL_ECDSA_ALGORITHM)<br><br>The *<HASH>* value identifies the CNG hash algorithm. The following algorithms are supported:<br><br>* L"MD5" (BCRYPT_MD5_ALGORITHM)<br>* L"SHA1" (BCRYPT_SHA1_ALGORITHM)<br>* L"SHA256" (BCRYPT_SHA256_ALGORITHM)<br>* L"SHA384" (BCRYPT_SHA384_ALGORITHM)<br>* L"SHA512" (BCRYPT_SHA512_ALGORITHM)<br><br>The following are common examples:<br><br>* L”RSA/SHA1”<br>* L”RSA/SHA256”<br>* L”ECDSA/SHA256”<br><br>This property is also applicable to an OCSP response that has been converted to a CRL.<br><br>This property is explicitly set by the verify revocation functions.<br><br>**Windows 8 and Windows Server 2012:** Support for this property begins. |
| **CERT_SIGNATURE_HASH_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Sets the signature hash. If the hash does not exist, it is computed with [CryptHashToBeSigned](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashtobesigned). The length of the hash is 20 bytes for SHA and 16 for MD5. |

The user can define additional *dwPropId* types by using **DWORD** values from CERT_FIRST_USER_PROP_ID to CERT_LAST_USER_PROP_ID. For all user-defined *dwPropId* types, *pvData* points to an encoded [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)).

For all the other property identifiers, *pvData* points to an encoded [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

### `dwFlags` [in]

CERT_STORE_NO_CRYPT_RELEASE_FLAG can be set for the CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_CONTEXT_PROP_ID *dwPropId* properties.

If the CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG value is set, any provider-write errors are ignored and the cached context's properties are always set.

If the CERT_SET_PROPERTY_INHIBIT_PERSIST_FLAG is set, any property set is not persisted.

### `pvData` [in]

A pointer to a data type that is determined by the value passed in *dwPropId*.

**Note** For any *dwPropId*, setting *pvData* to **NULL** deletes the property.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). One possible error code is the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property is not valid. The identifier specified was greater than 0x0000FFFF, or, for the CERT_KEY_CONTEXT_PROP_ID property, a **cbSize** member that is not valid was specified in the [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure. |

## Remarks

If a property already exists, its old value is replaced.

#### Examples

For an example that uses this function, see
[Example C Program: Getting and Setting Certificate Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-getting-and-setting-certificate-properties).

## See also

[CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info)

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CERT_ENHKEY_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage)

[CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context)

[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context)

[CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info)

[CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage)

[CertGetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcrlcontextproperty)

[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)

[CryptHashToBeSigned](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashtobesigned)

[Extended Property Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)