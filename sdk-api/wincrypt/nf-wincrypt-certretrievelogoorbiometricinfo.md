# CertRetrieveLogoOrBiometricInfo function

## Description

The **CertRetrieveLogoOrBiometricInfo** function performs a URL retrieval of logo or biometric information specified in either the **szOID_LOGOTYPE_EXT** or **szOID_BIOMETRIC_EXT** certificate extension. The **szOID_BIOMETRIC_EXT** extension (IETF RFC 3739) supports the addition of a signature or a pictorial representation of the human holder of the certificate. The **szOID_LOGOTYPE_EXT** extension (IETF RFC 3709) supports the addition of organizational pictorial representations in certificates.

## Parameters

### `pCertContext` [in]

The address of a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the certificate.

### `lpszLogoOrBiometricType` [in]

The address of a null-terminated ANSI string that contains an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) string that identifies the type of information to retrieve.

This parameter may also contain one of the following predefined values.

| Value | Meaning |
| --- | --- |
| **CERT_RETRIEVE_ISSUER_LOGO** | Retrieve the certificate issuer logotype. |
| **CERT_RETRIEVE_SUBJECT_LOGO** | Retrieve the certificate subject logotype. |
| **CERT_RETRIEVE_COMMUNITY_LOGO** | Retrieve the certificate community logotype. |
| **CERT_RETRIEVE_BIOMETRIC_PICTURE_TYPE** | Retrieve the picture associated with the certificate. |
| **CERT_RETRIEVE_BIOMETRIC_SIGNATURE_TYPE** | Retrieve the signature associated with the certificate. |

### `dwRetrievalFlags` [in]

A set of flags that specify how the information should be retrieved. This parameter is passed as the *dwRetrievalFlags* in the [CryptRetrieveObjectByUrl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptretrieveobjectbyurla) function.

### `dwTimeout` [in]

The maximum amount of time, in milliseconds, to wait for the retrieval.

### `dwFlags` [in]

This parameter is not used and must be zero.

### `pvReserved`

This parameter is not used and must be **NULL**.

### `ppbData` [out]

The address of a **BYTE** pointer that receives the logotype or biometric data. This memory must be freed when it is no longer needed by passing this pointer to the [CryptMemFree](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemfree) function.

### `pcbData` [out]

The address of a **DWORD** variable that receives the number of bytes in the *ppbData* buffer.

### `ppwszMimeType` [out]

The address of a pointer to a null-terminated Unicode string that receives the Multipurpose Internet Mail Extensions (MIME) type of the data. This parameter can be **NULL** if this information is not needed. This memory must be freed when it is no longer needed by passing this pointer to the [CryptMemFree](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemfree) function.

This address always receives **NULL** for biometric types. You must always ensure that this parameter contains a valid memory address before attempting to access the memory.

## Return value

Returns nonzero if successful or zero otherwise.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error codes returned by the
**GetLastError** function include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **CRYPT_E_HASH_VALUE** | The computed hash value does not match the hash value in the certificate. |
| **CRYPT_E_NOT_FOUND** | The certificate does not contain the **szOID_LOGOTYPE_EXT** or **szOID_BIOMETRIC_EXT** extension, or the specified *lpszLogoOrBiometricType* was not found. |
| **E_INVALIDARG** | One or more parameters are not valid. |
| **ERROR_INVALID_DATA** | No data could be retrieved from the URL specified by the certificate extension. |
| **ERROR_NOT_SUPPORTED** | The certificate does not support the required extension. |
| **NTE_BAD_ALGID** | The hash algorithm OID is unknown. |

## See also

[CryptMemFree](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemfree)