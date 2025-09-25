# CERTENROLL_PROPERTYID enumeration

## Description

The **CERTENROLL_PROPERTYID** enumeration type contains predefined object identifiers for external properties that can be associated with a certificate in the certificate store. This enumeration is used by the [ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty) interface.

The descriptions for each of the supported values identify the property data type so that you know how to create the value before calling the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-initializedecode) method. The following interfaces, derived from [ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty), have been defined to simplify initialization and retrieval of the most common properties:

* [ICertPropertyArchived](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyarchived)
* [ICertPropertyArchivedKeyHash](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyarchivedkeyhash)
* [ICertPropertyAutoEnroll](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyautoenroll)
* [ICertPropertyBackedUp](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertybackedup)
* [ICertPropertyDescription](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertydescription)
* [ICertPropertyEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollment)
* [ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver)
* [ICertPropertyFriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyfriendlyname)
* [ICertPropertyKeyProvInfo](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertykeyprovinfo)
* [ICertPropertyRenewal](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrenewal)
* [ICertPropertyRequestOriginator](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrequestoriginator)
* [ICertPropertySHA1Hash](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertysha1hash)

## Constants

### `XCN_PROPERTYID_NONE:0`

No property is identified.

### `XCN_CERT_KEY_PROV_HANDLE_PROP_ID:1`

Data type: **HCRYPTPROV**

The handle of the private key associated with the certificate.

### `XCN_CERT_KEY_PROV_INFO_PROP_ID:2`

Data type: pointer to a [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure.

The structure contains information about a CSP key container or a Cryptography API: Next Generation (CNG) key. This is used to acquire a handle to the private key. We recommend that you use the [ICertPropertyKeyProvInfo](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertykeyprovinfo) interface to initialize and retrieve this property.

### `XCN_CERT_SHA1_HASH_PROP_ID:3`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains a SHA-1 hash value of the certificate. We recommend that you use the [ICertPropertySHA1Hash](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertysha1hash) interface to initialize and retrieve this property.

### `XCN_CERT_MD5_HASH_PROP_ID:4`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains an MD5 hash value of the certificate.

### `XCN_CERT_HASH_PROP_ID:3`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains a hash of the certificate created by using the default hashing algorithm. The default algorithm is currently SHA-1.

### `XCN_CERT_KEY_CONTEXT_PROP_ID:5`

Data type: pointer to a [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure.

The structure contains the information necessary to retrieve a key, including the CSP or key service provider (KSP) handle and a value that indicates whether the key is used for signing or encryption.

### `XCN_CERT_KEY_SPEC_PROP_ID:6`

Data type: pointer to a **DWORD**.

The **DWORD** contains a value that identifies whether the key is used for signing or for encryption and whether the key is associated with a CNG KSP. This is the same as the value specified in the *dwKeySpec* parameter of the [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure. This value can be a bitwise-**OR** combination of the following values:

* AT_KEYEXCHANGE
* AT_SIGNATURE
* CERT_NCRYPT_KEY_SPEC

### `XCN_CERT_IE30_RESERVED_PROP_ID:7`

Not supported.

### `XCN_CERT_PUBKEY_HASH_RESERVED_PROP_ID:8`

Not supported.

### `XCN_CERT_ENHKEY_USAGE_PROP_ID:9`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains a DER-encoded **EnhancedKeyUsage** extension in a **CERT_ENHKEY_USAGE** structure. You can encode the structure by using the CryptoAPI [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function and setting the *lpszStructType* parameter to **X509_ENHANCED_KEY_USAGE**.

``` syntax
typedef struct _CTL_USAGE
{
    DWORD               cUsageIdentifier;
    LPSTR               *rgpszUsageIdentifier;
}
CTL_USAGE, *PCTL_USAGE, CERT_ENHKEY_USAGE, *PCERT_ENHKEY_USAGE;
```

### `XCN_CERT_CTL_USAGE_PROP_ID:9`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains a DER-encoded certificate trust list (CTL) usage identifier in a **CTL_USAGE** structure. You can encode the structure by using the CryptoAPI [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function and setting the *lpszStructType* parameter to **X509_ENHANCED_KEY_USAGE**.

``` syntax
typedef struct _CTL_USAGE
{
    DWORD               cUsageIdentifier;
    LPSTR               *rgpszUsageIdentifier;
}
CTL_USAGE;
```

### `XCN_CERT_NEXT_UPDATE_LOCATION_PROP_ID:10`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains a DER-encoded **AlternativeNames** extension in a [CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info) structure. You can encode the structure by using the CryptoAPI [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function and setting the *lpszStructType* parameter to **X509_ALTERNATE_NAME**.

### `XCN_CERT_FRIENDLY_NAME_PROP_ID:11`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member contains a pointer to a null-terminated Unicode string that contains the display name for the certificate. We recommend that you use the [ICertPropertyFriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyfriendlyname) interface to initialize and retrieve this property.

### `XCN_CERT_PVK_FILE_PROP_ID:12`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member contains a pointer to a null-terminated Unicode string that contains the name of the private key file.

### `XCN_CERT_DESCRIPTION_PROP_ID:13`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member contains a pointer to a null-terminated Unicode string that contains a description of the certificate. We recommend that you use the [ICertPropertyDescription](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertydescription) interface to initialize and retrieve this property.

### `XCN_CERT_ACCESS_STATE_PROP_ID:14`

Data type: pointer to a **DWORD**.

The **DWORD** can contain a value that is a bitwise-**OR** combination of the following flags:

* CERT_ACCESS_STATE_WRITE_PERSIST_FLAG (0x1)
* CERT_ACCESS_STATE_SYSTEM_STORE_FLAG (0x2)
* CERT_ACCESS_STATE_LM_SYSTEM_STORE_FLAG (0x4)
* CERT_ACCESS_STATE_GP_SYSTEM_STORE_FLAG (0x8)

This is a read-only property and cannot be associated with an existing certificate by calling the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method. You can retrieve it by calling the [RawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-get_rawdata) property after initializing the property value by using the [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-initializefromcertificate) method.

### `XCN_CERT_SIGNATURE_HASH_PROP_ID:15`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains a hash of the certificate signature.

### `XCN_CERT_SMART_CARD_DATA_PROP_ID:16`

Not supported.

### `XCN_CERT_EFS_PROP_ID:17`

Not supported.

### `XCN_CERT_FORTEZZA_DATA_PROP_ID:18`

Not supported.

### `XCN_CERT_ARCHIVED_PROP_ID:19`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that identifies whether a certificate is archived. A certificate is typically archived when it has been replaced by a newer certificate. Subsequent enumeration of the certificate store usually skips the archived certificates. To indicate that the certificate is not archived, you can set *pbData* to **NULL** and *cbData* to zero (0). To indicate that the certificate is archived, you can set *pbData* to something other than **NULL** such as the address of the [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. We recommend, however, that you use the [ICertPropertyArchived](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyarchived) interface to set this property.

### `XCN_CERT_KEY_IDENTIFIER_PROP_ID:20`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains the hash of the certificate subject public key. Typically, this is a 20-byte SHA-1 hash. For more information, see the [IX509ExtensionSubjectKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsubjectkeyidentifier) interface.

### `XCN_CERT_AUTO_ENROLL_PROP_ID:21`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member contains a pointer to a null-terminated Unicode string that contains the name or object identifier used for auto-enrollment. We recommend that you use the [ICertPropertyAutoEnroll](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyautoenroll) interface to initialize and retrieve this property.

### `XCN_CERT_PUBKEY_ALG_PARA_PROP_ID:22`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to the DER-encoded public key algorithm parameters. For more information, see the [EncodedParameters](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-get_encodedparameters) property on the [IX509PublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509publickey) interface.

### `XCN_CERT_CROSS_CERT_DIST_POINTS_PROP_ID:23`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains a DER-encoded [CROSS_CERT_DIST_POINTS_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cross_cert_dist_points_info) structure. You can encode the structure by using the CryptoAPI [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function and setting the *lpszStructType* parameter to **X509_CROSS_CERT_DIST_POINTS**.

### `XCN_CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID:24`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains an MD5 hash of the public key associated with the private key used to sign the certificate.

### `XCN_CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID:25`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains an MD5 hash of the public key contained in the certificate.

### `XCN_CERT_ENROLLMENT_PROP_ID:26`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains the following information (in the order listed) about a pending request. Each Unicode string is null-terminated, and the length includes the terminating null character.

* Request ID length (4 bytes)
* Request ID string
* CA DNS name string length (4 bytes)
* CA DNS name string
* CA name string length (4 bytes)
* CA name string
* Display name length (4 bytes)
* Display name string

We recommend that you use the [ICertPropertyEnrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollment) interface to initialize and retrieve this property.

### `XCN_CERT_DATE_STAMP_PROP_ID:27`

Data type: pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

The structure contains the time that the certificate was added to the certificate store.

### `XCN_CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID:28`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains an MD5 hash of the CA signing certificate serial number.

### `XCN_CERT_SUBJECT_NAME_MD5_HASH_PROP_ID:29`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains an MD5 hash of the subject name.

### `XCN_CERT_EXTENDED_ERROR_INFO_PROP_ID:30`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a null-terminated Unicode string that contains information about an error.

### `XCN_CERT_RENEWAL_PROP_ID:64`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains a SHA-1 hash of the certificate that is being renewed. We recommend that you use the [ICertPropertyRenewal](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrenewal) interface to initialize and retrieve this property.

### `XCN_CERT_ARCHIVED_KEY_HASH_PROP_ID:65`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains a hash of the archived private key. We recommend that you use the [ICertPropertyArchivedKeyHash](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyarchivedkeyhash) interface to initialize and retrieve this property value.

### `XCN_CERT_AUTO_ENROLL_RETRY_PROP_ID:66`

Not supported.

### `XCN_CERT_AIA_URL_RETRIEVED_PROP_ID:67`

Not supported.

### `XCN_CERT_AUTHORITY_INFO_ACCESS_PROP_ID:68`

Not supported.

### `XCN_CERT_BACKED_UP_PROP_ID:69`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a byte array that contains a **VARIANT_BOOL** followed by a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure. To specify that the certificate is not backed up, set the first `sizeof(VARIANT_BOOL)` bytes in the array to zero (0). Otherwise, specify a value that is not zero. To specify the time at which the certificate was backed up, set the next `sizeof(FILETIME)` bytes to the date and time. We recommend that you use the [ICertPropertyBackedUp](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertybackedup) interface to set this property value. This property is not currently used.

### `XCN_CERT_OCSP_RESPONSE_PROP_ID:70`

Not supported.

### `XCN_CERT_REQUEST_ORIGINATOR_PROP_ID:71`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a null-terminated Unicode string that contains the name of the computer that originated an auto-enrollment certificate request. We recommend that you use the [ICertPropertyRequestOriginator](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyrequestoriginator) interface to initialize and retrieve this property.

### `XCN_CERT_SOURCE_LOCATION_PROP_ID:72`

Not supported.

### `XCN_CERT_SOURCE_URL_PROP_ID:73`

Not supported.

### `XCN_CERT_NEW_KEY_PROP_ID:74`

Not supported.

### `XCN_CERT_OCSP_CACHE_PREFIX_PROP_ID:75`

### `XCN_CERT_SMART_CARD_ROOT_INFO_PROP_ID:76`

### `XCN_CERT_NO_AUTO_EXPIRE_CHECK_PROP_ID:77`

### `XCN_CERT_NCRYPT_KEY_HANDLE_PROP_ID:78`

### `XCN_CERT_HCRYPTPROV_OR_NCRYPT_KEY_HANDLE_PROP_ID:79`

### `XCN_CERT_SUBJECT_INFO_ACCESS_PROP_ID:80`

### `XCN_CERT_CA_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID:81`

### `XCN_CERT_CA_DISABLE_CRL_PROP_ID:82`

### `XCN_CERT_ROOT_PROGRAM_CERT_POLICIES_PROP_ID:83`

### `XCN_CERT_ROOT_PROGRAM_NAME_CONSTRAINTS_PROP_ID:84`

### `XCN_CERT_SUBJECT_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID:85`

### `XCN_CERT_SUBJECT_DISABLE_CRL_PROP_ID:86`

### `XCN_CERT_CEP_PROP_ID:87`

Contains information about a certificate enrollment policy (CEP) server and a certificate enrollment server (CES). This includes:

* The CEP authentication method.
* The CES authentication method.
* The CEP URL.
* The CES URL
* The CEP ID.
* The request ID string.

For more information, see [ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver).

### `XCN_CERT_SIGN_HASH_CNG_ALG_PROP_ID:89`

### `XCN_CERT_SCARD_PIN_ID_PROP_ID:90`

### `XCN_CERT_SCARD_PIN_INFO_PROP_ID:91`

### `XCN_CERT_SUBJECT_PUB_KEY_BIT_LENGTH_PROP_ID:92`

### `XCN_CERT_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID:93`

### `XCN_CERT_ISSUER_PUB_KEY_BIT_LENGTH_PROP_ID:94`

### `XCN_CERT_ISSUER_CHAIN_SIGN_HASH_CNG_ALG_PROP_ID:95`

### `XCN_CERT_ISSUER_CHAIN_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID:96`

### `XCN_CERT_NO_EXPIRE_NOTIFICATION_PROP_ID:97`

### `XCN_CERT_AUTH_ROOT_SHA256_HASH_PROP_ID:98`

### `XCN_CERT_NCRYPT_KEY_HANDLE_TRANSFER_PROP_ID:99`

### `XCN_CERT_HCRYPTPROV_TRANSFER_PROP_ID:100`

### `XCN_CERT_SMART_CARD_READER_PROP_ID:101`

### `XCN_CERT_SEND_AS_TRUSTED_ISSUER_PROP_ID:102`

### `XCN_CERT_KEY_REPAIR_ATTEMPTED_PROP_ID:103`

### `XCN_CERT_DISALLOWED_FILETIME_PROP_ID:104`

### `XCN_CERT_ROOT_PROGRAM_CHAIN_POLICIES_PROP_ID:105`

### `XCN_CERT_SMART_CARD_READER_NON_REMOVABLE_PROP_ID:106`

### `XCN_CERT_SHA256_HASH_PROP_ID:107`

### `XCN_CERT_SCEP_SERVER_CERTS_PROP_ID:108`

### `XCN_CERT_SCEP_RA_SIGNATURE_CERT_PROP_ID:109`

### `XCN_CERT_SCEP_RA_ENCRYPTION_CERT_PROP_ID:110`

### `XCN_CERT_SCEP_CA_CERT_PROP_ID:111`

### `XCN_CERT_SCEP_SIGNER_CERT_PROP_ID:112`

### `XCN_CERT_SCEP_NONCE_PROP_ID:113`

### `XCN_CERT_SCEP_ENCRYPT_HASH_CNG_ALG_PROP_ID:114`

### `XCN_CERT_SCEP_FLAGS_PROP_ID:115`

### `XCN_CERT_SCEP_GUID_PROP_ID:116`

### `XCN_CERT_SERIALIZABLE_KEY_CONTEXT_PROP_ID:117`

### `XCN_CERT_ISOLATED_KEY_PROP_ID:118`

### `XCN_CERT_SERIAL_CHAIN_PROP_ID:119`

### `XCN_CERT_KEY_CLASSIFICATION_PROP_ID:120`

### `XCN_CERT_DISALLOWED_ENHKEY_USAGE_PROP_ID:122`

### `XCN_CERT_NONCOMPLIANT_ROOT_URL_PROP_ID:123`

### `XCN_CERT_PIN_SHA256_HASH_PROP_ID:124`

### `XCN_CERT_CLR_DELETE_KEY_PROP_ID:125`

### `XCN_CERT_NOT_BEFORE_FILETIME_PROP_ID:126`

### `XCN_CERT_CERT_NOT_BEFORE_ENHKEY_USAGE_PROP_ID:127`

### `XCN_CERT_FIRST_RESERVED_PROP_ID:128`

Not supported.

### `XCN_CERT_LAST_RESERVED_PROP_ID:0x7fff`

Not supported.

### `XCN_CERT_FIRST_USER_PROP_ID:0x8000`

The minimum number for a user-defined property ID.

### `XCN_CERT_LAST_USER_PROP_ID:0xffff`

The maximum number for a user-defined property ID.

### `XCN_CERT_STORE_LOCALIZED_NAME_PROP_ID:0x1000`

Data type: pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

The *pbData* structure member points to a null-terminated Unicode string that contains the localized name of the certificate store.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)