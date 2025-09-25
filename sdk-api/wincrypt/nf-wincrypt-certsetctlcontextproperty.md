# CertSetCTLContextProperty function

## Description

The **CertSetCTLContextProperty** function sets an extended property for the specified [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) context.

## Parameters

### `pCtlContext` [in]

A pointer to the
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure.

### `dwPropId` [in]

Identifies the property to be set. The value of *dwPropId* determines the type and content of the *pvData* parameter. Currently defined identifiers and their related *pvData* types are as follows.

| Value | Meaning |
| --- | --- |
| **CERT_ARCHIVED_PROP_ID** | Data type of *pvData*: **NULL**<br><br>Indicates the certificate is skipped during enumerations. A certificate with this property set is still found with explicit search operations—such as finding a certificate with a specific [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) or a specific serial number. |
| **CERT_AUTO_ENROLL_PROP_ID** | Data type of *pvData*: pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))<br><br>Property set after a certificate has been enrolled using Auto Enroll. The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure pointed to by *pvData* includes a **null**-terminated, Unicode name of the certificate type for which the certificates has been auto enrolled. Any subsequent calls to Auto Enroll for the certificate checks for this property to determine whether the certificate has been enrolled. |
| **CERT_CTL_USAGE_PROP_ID** | Data type of *pvData*: pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))<br><br>*pvData* points to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure containing an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoded [CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure. This structure was encoded using [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) with X509_ENHANCED_KEY_USAGE value set. |
| **CERT_DESCRIPTION_PROP_ID** | Data type of *pvData*: pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))<br><br>Property set and displayed by the certificate UI. This property allows the user to describe the certificate's use. |
| **CERT_ENHKEY_USAGE_PROP_ID** | Data type of *pvData*: pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))<br><br>The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure containing an ASN.1 encoded [CERT_ENHKEY_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure. This structure was encoded using [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) with X509_ENHANCED_KEY_USAGE value set. |
| **CERT_FRIENDLY_NAME_PROP_ID** | Data type of *pvData*: pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))<br><br>The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure specifies the display name of the certificate. |
| **CERT_HASH_PROP_ID** | Data type of *pvData*: pointer to a [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))<br><br>This property is implicitly set by a call to [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty). |
| **CERT_KEY_CONTEXT_PROP_ID** | Data type of *pvData*: pointer to a [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context)<br><br>The [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure contains both the [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) value and the key specification for the private key. For more information about the **hCryptProv** member and *dwFlags* settings, see CERT_KEY_PROV_HANDLE_PROP_ID, following. Note that more **CERT_KEY_CONTEXT** structure members can be added for this property. If so, the **cbSize** member value will be adjusted accordingly. The **cbSize** member must be set to the size of the **CERT_KEY_CONTEXT** structure |
| **CERT_KEY_IDENTIFIER_PROP_ID** | Data type of *pvData*: pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))<br><br>This property is typically implicitly set by a call to [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty). |
| **CERT_KEY_PROV_HANDLE_PROP_ID** | Data type of *pvData*: pointer to a [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov)<br><br>An [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) handle for the certificate's private key is passed. The **hCryptProv** member of the [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure is updated if it exists. If it does not exist, it is created with **dwKeySpec** initialized by CERT_KEY_PROV_INFO_PROP_ID. If CERT_STORE_NO_CRYPT_RELEASE_FLAG is not set, the **hCryptProv** value is implicitly released either when the property is set to **NULL** or on the final freeing of the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure. |
| **CERT_KEY_PROV_INFO_PROP_ID** | Data type of *pvData*: pointer to a [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info)<br><br>The [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure specifies the certificate's private key. |
| **CERT_KEY_SPEC_PROP_ID** | Data type of *pvData*: pointer to a **DWORD**<br><br>The **DWORD** value specifies the private key. The **dwKeySpec** member of the [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure is updated if it exists. If it does not, it is created with **hCryptProv** set to zero. |
| **CERT_MD5_HASH_PROP_ID** | Data type of *pvData*: pointer to a [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))<br><br>This property is implicitly set by a call to [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty). |
| **CERT_NEXT_UPDATE_LOCATION_PROP_ID** | Data type of *pvData*: pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))<br><br>The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure contains an ASN.1 encoded [CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info) structure encoded using [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) with the X509_ALTERNATE_NAME value set. CERT_NEXT_UPDATE_LOCATION_PROP_ID is currently used only with CTLs. |
| **CERT_PVK_FILE_PROP_ID** | Data type of *pvData*: pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))<br><br>The [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure specifies the name of a file containing the private key associated with the certificate's public key. Inside the **CRYPT_DATA_BLOB** structure, the **pbData** member is a pointer to a **null**-terminated Unicode, wide-character string, and the **cbData** member indicates the length of the string. |
| **CERT_SHA1_HASH_PROP_ID** | Data type of *pvData*: pointer to a [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))<br><br>This property is implicitly set by a call to [CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty). |
| **CERT_SIGNATURE_HASH_PROP_ID**<br><br>[CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) | Data type of *pvData*: pointer to a [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))<br><br>If a signature hash does not exist, it is computed with [CryptHashToBeSigned](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashtobesigned). *pvData* points to an existing or computed hash. Usually, the length of the hash is 20 bytes for SHA and 16 for MD5. |

Typically, only the CERT_NEXT_UPDATE_LOCATION_PROP_ID property is set.

Additional *dwPropId* types can be defined by the user using **DWORD** values from CERT_FIRST_USER_PROP_ID to CERT_LAST_USER_PROP_ID. For all user-defined *dwPropId* types, *pvData* points to an encoded [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.

### `dwFlags` [in]

CERT_STORE_NO_CRYPT_RELEASE_FLAG can be set for the CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_CONTEXT_PROP_ID *dwPropId* properties.

If the CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG value is set, any provider-write errors are ignored and the cached context's properties are always set.

If CERT_SET_PROPERTY_INHIBIT_PERSIST_FLAG is set, any property set is not persisted.

### `pvData` [in]

A pointer to a data type that is determined by the value passed in *dwPropId*.

**Note** For any *dwPropId*, setting *pvData* to **NULL** deletes the property.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). One possible error code is the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid property identifier. For details, see [CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty). |

## Remarks

If a property already exists, its old value is replaced.

#### Examples

See
[Example C Program: Getting and Setting Certificate Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-getting-and-setting-certificate-properties).

## See also

[CertGetCTLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetctlcontextproperty)

[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)

[Extended Property Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)