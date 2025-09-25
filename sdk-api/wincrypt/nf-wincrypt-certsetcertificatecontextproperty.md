# CertSetCertificateContextProperty function

## Description

The **CertSetCertificateContextProperty** function sets an extended property for a specified [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `pCertContext` [in]

A pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure.

### `dwPropId` [in]

The property to be set. The value of *dwPropId* determines the type and content of the *pvData* parameter. Currently defined identifiers and their related *pvData* types are as follows.

**Note** [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) and [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) are described in the [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) topic.

#### CERT_ACCESS_STATE_PROP_ID

Data type of *pvData*: A pointer to a **DWORD** value.

Returns a **DWORD** value that indicates whether
write operations to the certificate are persisted.
The **DWORD** value is not set if the certificate
is in a memory store or in a registry-based store
that is opened as read-only.

#### CERT_AIA_URL_RETRIEVED_PROP_ID

This identifier is reserved.

#### CERT_ARCHIVED_KEY_HASH_PROP_ID

Data type of *pvData*:
A pointer to a [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property saves an encrypted key [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) for the certificate context.

#### CERT_ARCHIVED_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

Indicates that the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) is skipped during enumerations. A certificate with this property set is still found with explicit search operations, such as finding a certificate with a specific [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) or a specific serial number. This property can be set to the empty [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly), `{0,NULL}`.

#### CERT_AUTHORITY_INFO_ACCESS_PROP_ID

This identifier is reserved.

#### CERT_AUTO_ENROLL_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

A property that is set after a certificate has been enrolled by using Auto Enroll. The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure pointed to by *pvData* includes a null-terminated Unicode name of the certificate type for which the certificate has been auto enrolled. Any subsequent calls to Auto Enroll for the certificate checks for this property to determine whether the certificate has been enrolled.

#### CERT_AUTO_ENROLL_RETRY_PROP_ID

This identifier is reserved.

#### CERT_BACKED_UP_PROP_ID

This identifier is reserved.

#### CERT_CA_DISABLE_CRL_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

Disables [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) retrieval for certificates used by the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA). If the CA certificate contains this property, it must also include the **CERT_CA_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID** property.

#### CERT_CA_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

Contains the list of [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) URLs to use for certificates issued by the CA certificate. The array contents are the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1)-encoded bytes of an **X509_AUTHORITY_INFO_ACCESS** structure where **pszAccessMethod** is set to **szOID_PKIX_OCSP**.

#### CERT_CROSS_CERT_DIST_POINTS_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

Sets the location of the cross certificates. This value is only applicable to certificates and not to [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs) or [certificate trust lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTLs). The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure contains an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1)-encoded
[CROSS_CERT_DIST_POINTS_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cross_cert_dist_points_info) structure that is encoded by using
the [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function with a X509_CROSS_CERT_DIST_POINTS value for the *lpszStuctType* parameter.

#### CERT_CTL_USAGE_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure contains an ASN.1-encoded
[CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure. This structure is encoded by using the [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function with the X509_ENHANCED_KEY_USAGE value set.

#### CERT_DATE_STAMP_PROP_ID

Data type of *pvData*: A pointer to a **FILETIME** structure.

This property sets the time that the certificate was added to the store.

#### CERT_DESCRIPTION_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

A property that is set and displayed by the certificate UI. This property allows the user to describe the certificate's use.

#### CERT_EFS_PROP_ID

This identifier is reserved.

#### CERT_ENHKEY_USAGE_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

A property that indicates that the *pvData* parameter points to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains an ASN.1-encoded [CERT_ENHKEY_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure. This structure is encoded by using the [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function with the X509_ENHANCED_KEY_USAGE value set.

#### CERT_ENROLLMENT_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

Enrollment information of the pending request that contains
RequestID, CADNSName, CAName, and DisplayName. The data format
is defined as follows.

| Bytes | Contents |
| --- | --- |
| First 4 bytes | Pending request ID |
| Next 4 bytes | CADNSName size, in characters, including the terminating null character, followed by CADNSName string with terminating null character |
| Next 4 bytes | CAName size, in characters, including the terminating null character, followed by CAName string with terminating null character |
| Next 4 bytes | DisplayName size, in characters, including the terminating null character, followed by DisplayName string with terminating null character |

#### CERT_EXTENDED_ERROR_INFO_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property sets a string that contains extended error information for the certificate context.

#### CERT_FORTEZZA_DATA_PROP_ID

This identifier is reserved.

#### CERT_FRIENDLY_NAME_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure contains the display name of the certificate.

#### CERT_HASH_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property is implicitly set by a call to
the [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty) function.

#### CERT_HCRYPTPROV_OR_NCRYPT_KEY_HANDLE_PROP_ID

Data type of *pvData*: A pointer to an [HCRYPTPROV_OR_NCRYPT_KEY_HANDLE](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov-or-ncrypt-key-handle) data type.

This property calls [NCryptIsKeyHandle](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptiskeyhandle) to determine whether this is an **NCRYPT_KEY_HANDLE**. For an **NCRYPT_KEY_HANDLE**, sets **CERT_NCRYPT_KEY_HANDLE_PROP_ID**; otherwise, it sets **CERT_KEY_PROV_HANDLE_PROP_ID**.

#### CERT_HCRYPTPROV_TRANSFER_PROP_ID

Sets the handle of the CAPI key associated with the certificate.

#### CERT_IE30_RESERVED_PROP_ID

This identifier is reserved.

#### CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property sets the [MD5](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) associated with the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used to sign this certificate.

#### CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure contains the MD5 hash of the issuer name and serial number from this certificate.

#### CERT_KEY_CONTEXT_PROP_ID

Data type of *pvData*: A pointer to a [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure.

The structure specifies the certificate's private key. It contains both the [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) and key specification for the private key. For more information about the **hCryptProv** member and *dwFlags* settings, see CERT_KEY_PROV_HANDLE_PROP_ID, later in this topic.

**Note** More [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure members can be added for this property. If so, the **cbSize** member value will be adjusted accordingly. The **cbSize** member must be set to the size of the **CERT_KEY_CONTEXT** structure.

#### CERT_KEY_IDENTIFIER_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property is typically implicitly set by a call to
the [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty) function.

#### CERT_KEY_PROV_HANDLE_PROP_ID

Data type of *pvData*: A [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) value.

The [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) handle for the certificate's private key is set. The **hCryptProv** member of the [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure is updated if it exists. If it does not exist, it is created with **dwKeySpec** and initialized by CERT_KEY_PROV_INFO_PROP_ID. If CERT_STORE_NO_CRYPT_RELEASE_FLAG is not set, the **hCryptProv** value is implicitly released either when the property is set to **NULL** or on the final freeing of the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure.

#### CERT_KEY_PROV_INFO_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure.

The structure specifies the certificate's private key.

#### CERT_KEY_SPEC_PROP_ID

Data type of *pvData*: A pointer to a **DWORD** value.

The **DWORD** value that specifies the private key. The **dwKeySpec** member of the [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure is updated if it exists. If it does not, it is created with **hCryptProv** set to zero.

#### CERT_MD5_HASH_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property is implicitly set by a call to
the [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty) function.

#### CERT_NCRYPT_KEY_HANDLE_PROP_ID

Data type of *pvData*: A pointer to an **NCRYPT_KEY_HANDLE** data type.

This property sets the **NCRYPT_KEY_HANDLE** for the certificate private key and sets the *dwKeySpec* to **CERT_NCRYPT_KEY_SPEC**.

#### CERT_NCRYPT_KEY_HANDLE_TRANSFER_PROP_ID

Sets the handle of the CNG key associated with the certificate.

#### CERT_NEW_KEY_PROP_ID

This identifier is reserved.

#### CERT_NEXT_UPDATE_LOCATION_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure contains an ASN.1-encoded
[CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info) structure that is encoded by using the [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function with the X509_ALTERNATE_NAME value set.

CERT_NEXT_UPDATE_LOCATION_PROP_ID is currently used only with CTLs.

#### CERT_NO_AUTO_EXPIRE_CHECK_PROP_ID

This identifier is reserved.

#### CERT_OCSP_CACHE_PREFIX_PROP_ID

This identifier is reserved.

#### CERT_OCSP_RESPONSE_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property sets the encoded [online certificate status protocol](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_server_ocsp_response_context) (OCSP) response from a [CERT_SERVER_OCSP_RESPONSE_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_server_ocsp_response_context) for this certificate.

#### CERT_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID

Data type of *pvData*: Pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property is implicitly set by calling the [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty) function.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This identifier is not supported.

#### CERT_PUBKEY_ALG_PARA_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property is used with public keys that support algorithm parameter inheritance. The data BLOB contains the ASN.1-encoded PublicKey Algorithm parameters. For DSS, these are parameters encoded by using
the [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function. This is used only if CMS_PKCS7 is defined.

#### CERT_PUBKEY_HASH_RESERVED_PROP_ID

This identifier is reserved.

#### CERT_PVK_FILE_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure specifies the name of a file that contains the private key associated with the certificate's public key. Inside the **CRYPT_DATA_BLOB** structure, the **pbData** member is a pointer to a null-terminated Unicode wide-character string, and the **cbData** member indicates the length of the string.

#### CERT_RENEWAL_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property specifies the hash of the renewed certificate.

#### CERT_REQUEST_ORIGINATOR_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure contains a null-terminated Unicode string that contains the DNS computer name for the origination of the certificate context request.

#### CERT_ROOT_PROGRAM_CERT_POLICIES_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

Returns a pointer to an encoded [CERT_POLICIES_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_policies_info) structure that contains the application policies of the root certificate for the context. This property can be decoded by using the [CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject) function with the *lpszStructType* parameter set to **X509_CERT_POLICIES** and the *dwCertEncodingType* parameter set to a combination of **X509_ASN_ENCODING** bitwise **OR** **PKCS_7_ASN_ENCODING**.

#### CERT_ROOT_PROGRAM_NAME_CONSTRAINTS_PROP_ID

This identifier is reserved.

#### CERT_SIGN_HASH_CNG_ALG_PROP_ID

Data type of *pvData*: Pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property is implicitly set by calling the [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty) function.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This identifier is not supported.

#### CERT_SHA1_HASH_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property is implicitly set by a call to
the [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty) function.

#### CERT_SIGNATURE_HASH_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

If a signature hash does not exist, it is computed by using the [CryptHashToBeSigned](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashtobesigned) function. *pvData* points to an existing or computed hash. Usually, the length of the hash is 20 bytes for SHA and 16 for MD5.

#### CERT_SMART_CARD_DATA_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property sets the smart card data property of a smart card certificate context.

#### CERT_SMART_CARD_ROOT_INFO_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property sets the information property of a smart card root certificate context.

#### CERT_SOURCE_LOCATION_PROP_ID

This identifier is reserved.

#### CERT_SOURCE_URL_PROP_ID

This identifier is reserved.

#### CERT_SUBJECT_DISABLE_CRL_PROP_ID

This identifier is reserved.

#### CERT_SUBJECT_INFO_ACCESS_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property sets the subject information access extension of the certificate context as an encoded [CERT_SUBJECT_INFO_ACCESS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_authority_info_access) structure.

#### CERT_SUBJECT_NAME_MD5_HASH_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

Returns an MD5 hash of the encoded subject name of the certificate context.

#### CERT_SUBJECT_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID

This identifier is reserved.

#### CERT_SUBJECT_PUB_KEY_BIT_LENGTH_PROP_ID

Data type of *pvData*: Pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property is implicitly set by calling the [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty) function.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This identifier is not supported.

#### CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID

Data type of *pvData*: A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

This property sets the MD5 hash of this certificate's public key.

*pvData* is a pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The user can define additional *dwPropId* types by using **DWORD** values from **CERT_FIRST_USER_PROP_ID** to **CERT_LAST_USER_PROP_ID**. For all user-defined *dwPropId* types, *pvData* points to an encoded [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

### `dwFlags` [in]

CERT_STORE_NO_CRYPT_RELEASE_FLAG can be set for the CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_CONTEXT_PROP_ID *dwPropId* properties.

If the CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG value is set, any provider-write errors are ignored and the cached context's properties are always set.

If CERT_SET_PROPERTY_INHIBIT_PERSIST_FLAG is set, any context property set is not persisted.

### `pvData` [in]

A pointer to a data type determined by the value of *dwPropId*.

**Note** For any *dwPropId*, setting *pvData* to **NULL** deletes the property.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, the function returns **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). One possible error code is the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property is not valid. The identifier specified was greater than 0x0000FFFF, or, for the CERT_KEY_CONTEXT_PROP_ID property, a **cbSize** member that is not valid was specified in the [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure. |

## Remarks

If a property already exists, its old value is replaced.

###

Your code can use a macro to evaluate the class of hash for a certificate context. The Wincrypt.h header defines the following macros for this purpose. These macros are used internally by the **CertSetCertificateContextProperty** function.

**IS_CERT_HASH_PROP_ID(X)**
**IS_PUBKEY_HASH_PROP_ID(X)**
**IS_CHAIN_HASH_PROP_ID(X)**
Each macro takes the *dwPropId* (X) value as input and evaluates to a Boolean value. The following table shows the *dwPropId* values that evaluate to **TRUE** for each macro.

| Macro | Evaluates to **TRUE** if *dwPropId* is |
| --- | --- |
| **IS_CERT_HASH_PROP_ID**(*dwPropId*) | **CERT_SHA1_HASH_PROP_ID**,<br><br>**CERT_MD5_HASH_PROP_ID**, or<br><br>**CERT_SIGNATURE_HASH_PROP_ID** |
| **IS_PUBKEY_HASH_PROP_ID**(*dwPropId*) | **CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID** or<br><br>**CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID** |
| **IS_CHAIN_HASH_PROP_ID**(*dwPropId*) | **CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID**,<br><br>**CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID**,<br><br>**CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID**, or<br><br>**CERT_SUBJECT_NAME_MD5_HASH_PROP_ID** |

The **IS_STRONG_SIGN_PROP_ID(x)** macro evaluates to **TRUE** if the **CERT_SIGN_HASH_CNG_ALG_PROP_ID**,
**CERT_SUBJECT_PUB_KEY_BIT_LENGTH_PROP_ID**, or **CERT_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID** properties are set
in the *dwPropId* parameter.

#### Examples

For an example that uses this function, see
[Example C Program: Getting and Setting Certificate Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-getting-and-setting-certificate-properties).

## See also

[CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info)

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CERT_ENHKEY_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage)

[CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context)

[CROSS_CERT_DIST_POINTS_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cross_cert_dist_points_info)

[CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info)

[CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage)

[CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty)

[CertSetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcrlcontextproperty)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)

[CryptHashToBeSigned](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashtobesigned)

[Extended Property Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)