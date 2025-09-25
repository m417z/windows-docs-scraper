# CertGetCTLContextProperty function

## Description

The **CertGetCTLContextProperty** function retrieves an extended property of a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) context.

## Parameters

### `pCtlContext` [in]

A pointer to the
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure.

### `dwPropId` [in]

Identifies the property to be retrieved. Currently defined identifiers and the data type to be returned in *pvData* are listed in the following table.

| Value | Meaning |
| --- | --- |
| **CERT_ACCESS_STATE_PROP_ID** | Data type for *pvData*: pointer to a **DWORD**<br><br>Returns a **DWORD** value indicating whether write operations to the certificate are persisted. The **DWORD** value is not set if the certificate is in a memory store or in a registry-based store that is opened as read-only. |
| **CERT_ARCHIVED_PROP_ID** | Data type for *pvData*: **NULL**<br><br>Indicates the certificate is skipped during enumerations. A certificate with this property set is found with explicit search operations, such as those used to find a certificate with a specific hash or a serial number. No data in *pvData* is associated with this property. |
| **CERT_AUTO_ENROLL_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Returns a **null**-terminated Unicode string naming the certificate type for which the certificate has been auto enrolled. |
| **CERT_CTL_USAGE_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Returns an array of bytes containing an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoded [CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure. |
| **CERT_DESCRIPTION_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Returns the property displayed by the certificate UI. This property allows the user to describe the certificate's use. |
| **CERT_ENHKEY_USAGE_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Returns an array of bytes containing an ASN.1 encoded [CERT_ENHKEY_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure. |
| **CERT_FRIENDLY_NAME_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Returns a **null**-terminated Unicode character string that contains the display name for the CTL. |
| **CERT_HASH_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Returns the SHA1 hash. If the hash does not exist, it is computed using [CryptHashCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashcertificate). |
| **CERT_KEY_CONTEXT_PROP_ID** | Data type for *pvData*: pointer to a [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context)<br><br>Returns a [CERT_KEY_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_context) structure. |
| **CERT_KEY_IDENTIFIER_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>If nonexistent, searches for the szOID_SUBJECT_KEY_IDENTIFIER extension. If that fails, a SHA1 hash is done on the certificate's **SubjectPublicKeyInfo** member to produce the identifier values. |
| **CERT_KEY_PROV_HANDLE_PROP_ID** | Data type for *pvData*: pointer to an [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov)<br><br>Returns the provider handle obtained from the CERT_KEY_CONTEXT_PROP_ID. |
| **CERT_KEY_PROV_INFO_PROP_ID** | Data type for *pvData*: pointer to a [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure<br><br>Returns a pointer to a [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info). |
| **CERT_KEY_SPEC_PROP_ID** | Data type for *pvData*: pointer to a **DWORD**<br><br>Returns a **DWORD** value specifying the private key obtained from CERT_KEY_CONTEXT_PROP_ID property if it exists. Otherwise, if CERT_KEY_PROV_INFO_PROP_ID exists, it is the source of the *dwKeySpec*. |
| **CERT_MD5_HASH_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Returns the MD5 hash. If the hash does not exist, it is computed using [CryptHashCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashcertificate). |
| **CERT_NEXT_UPDATE_LOCATION_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Returns the ASN.1 encoded [CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info) structure. <br><br>CERT_NEXT_UPDATE_LOCATION_PROP_ID is currently used only with CTLs. |
| **CERT_PVK_FILE_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Returns a **null**-terminated Unicode, wide character string specifying the file name containing the private key associated with the certificate's public key. |
| **CERT_SHA1_HASH_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Returns the SHA1 hash. If the hash does not exist, it is computed using [CryptHashCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashcertificate). |
| **CERT_SIGNATURE_HASH_PROP_ID** | Data type for *pvData*: pointer to a **BYTE** array<br><br>Returns the signature hash. If the hash does not exist, it is computed with [CryptHashToBeSigned](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashtobesigned). The length of the hash is 20 bytes for SHA and 16 for MD5. |

For all other property identifiers, *pvData* points to an array of bytes and not a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) as pointed to by the *pvData* parameter in [CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty).

For more information about each property identifier, see the documentation on the *dwPropId* parameter in
[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty). CERT_SHA1_HASH_PROP_ID and CERT_NEXT_UPDATE_LOCATION_PROP_ID are the predefined properties of most interest.

### `pvData` [out]

A pointer to a buffer to receive the data as determined by *dwPropId*. Structures pointed to by members of a structure returned are also returned following the base structure. Therefore, the size contained in *pcbData* often exceed the size of the base structure.

This parameter can be **NULL** to set the size of the information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbData` [in, out]

A pointer to a **DWORD** value specifying the size, in bytes, of the buffer pointed to by the *pvData* parameter. When the function returns, the **DWORD** value contains the number of bytes to be stored in the buffer.

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data fits in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

Errors from the called function, [CryptHashCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashcertificate), can be propagated to this function. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_NOT_FOUND** | The CTL does not have the specified property. |
| **ERROR_MORE_DATA** | If the buffer specified by the *pvData* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by *pcbData*. |

## See also

[CertEnumCTLContextProperties](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumctlcontextproperties)

[CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty)

[CertSetCTLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetctlcontextproperty)

[CryptHashCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashcertificate)

[Extended Property Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)