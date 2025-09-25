# CryptGetObjectUrl function

## Description

The **CryptGetObjectUrl** function acquires the URL of the remote object from a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL), or [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL).

The function takes the object, decodes it, and provides a pointer to an array of URLs from the object. For example, from a certificate, a CRL distribution list of URLs would be in the array.

## Parameters

### `pszUrlOid` [in]

A pointer to an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that identifies the URL being requested. If the [HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85)) of the *pszUrlOid* parameter is zero, the [LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85)) specifies the integer identifier for the type of the specified structure.

This parameter can be one of the following values. For information about how these values affect the *pvPara* parameter, see the heading "For the *pvPara* parameter" in the **Meaning** column.

| Value | Meaning |
| --- | --- |
| **URL_OID_CERTIFICATE_ISSUER** | Provides the URL of the certificate issuer retrieved from the authority information access extension or property of a certificate.<br><br>For the *pvPara* parameter: A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that was issued by the issuer whose URL is being requested. |
| **URL_OID_CERTIFICATE_CRL_DIST_POINT** | Provides a list of URLs of the CRL distribution points retrieved from the CRL distribution point extension or property of a certificate.<br><br>For the *pvPara* parameter: A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure whose CRL distribution point is requested. |
| **URL_OID_CERTIFICATE_CRL_DIST_POINT_AND_OCSP** | Provides a list of OCSP and CRL distribution point URLs from the authority information access (AIA) and CRL distribution point extensions or properties of a certificate. The function returns any CRL distribution point URLs first. Before using any OCSP URLs, you must remove the L"ocsp:" prefix.<br><br>For the *pvPara* parameter: A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure whose OCSP and CRL distribution point URLs are requested. |
| **URL_OID_CERTIFICATE_OCSP** | Provides an OCSP URL from the authority information access (AIA) extension or property of a certificate.<br><br>For the *pvPara* parameter: A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure whose OCSP URL is requested. |
| **URL_OID_CERTIFICATE_OCSP_AND_CRL_DIST_POINT** | Provides a list of OCSP and CRL distribution point URLs from the authority information access (AIA) and CRL distribution point extensions or properties of a certificate. The function returns any OCSP URLs first. Before using any OCSP URLs, you must remove the L"ocsp:" prefix.<br><br>For the *pvPara* parameter: A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure whose OCSP and CRL distribution point URLs are requested. |
| **URL_OID_CERTIFICATE_ONLY_OCSP** | Provides a list of OCSP URLs from the authority information access (AIA) extension or property of a certificate. Before using any OCSP URLs, you must remove the L"ocsp:" prefix.<br><br>For the *pvPara* parameter: A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure whose OCSP URLs are requested. |
| **URL_OID_CTL_ISSUER** | Provides the URL of the CTL issuer retrieved from an authority information access attribute method encoded in each signer information in the PKCS #7 CTL.<br><br>For the *pvPara* parameter: A pointer to a Signer Index [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure that was issued by the issuer whose URL, identified by the signer index, is requested. |
| **URL_OID_CTL_NEXT_UPDATE** | Provides the URL of the next update of that CTL retrieved from an authority information access CTL extension, property, or signer information attribute method.<br><br>For the *pvPara* parameter: A pointer to a Signer Index [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure whose next update URL is requested, and an optional signer index, in case it is needed to check the signer information attributes. |
| **URL_OID_CRL_ISSUER** | Provides the URL of the CRL issuer retrieved from a property on a CRL that was inherited from the subject certificate (either from the subject certificate issuer or the subject certificate distribution point extension). It is encoded as an authority information access extension method.<br><br>For the *pvPara* parameter: A pointer to a [CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure that was issued by the issuer whose URL is requested. |
| **URL_OID_CERTIFICATE_FRESHEST_CRL** | Retrieves the most recent CRL extension or property of the certificate.<br><br>For the *pvPara* parameter: The PCCERT_CONTEXT of a certificate whose most recent CRL distribution point is being requested. |
| **URL_OID_CRL_FRESHEST_CRL** | Retrieves the most recent CRL extension or property of the CRL.<br><br>For the *pvPara* parameter: A pointer to a [CERT_CRL_CONTEXT_PAIR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_crl_context_pair) structure that contains the base CRL of a certificate whose most recent CRL distribution point is being requested. |
| **URL_OID_CROSS_CERT_DIST_POINT** | Retrieves the cross certificate distribution point extension or property of the certificate.<br><br>For the *pvPara* parameter: The PCCERT_CONTEXT of a certificate whose cross certificate distribution point is being requested. |
| **URL_OID_CROSS_CERT_SUBJECT_INFO_ACCESS** | Retrieves the cross certificate Subject Information Access extension or property of the certificate.<br><br>For the *pvPara* parameter: The PCCERT_CONTEXT of a certificate whose cross certificate Subject Information Access is being requested. |

### `pvPara` [in]

A structure determined by the value of *pszUrlOid*. For details, see the description for the *pszUrlOid* parameter.

### `dwFlags` [in]

A set of flags used to get the URL locator for an object. This can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_GET_URL_FROM_PROPERTY** | Locates the URL from the property of the object (the location of the data). |
| **CRYPT_GET_URL_FROM_EXTENSION** | Locates the URL from the extension of the object. |
| **CRYPT_GET_URL_FROM_UNAUTH_ATTRIBUTE** | Locates the URL from an unauthenticated attribute from the signer information data. |
| **CRYPT_GET_URL_FROM_AUTH_ATTRIBUTE** | Locates the URL from an authenticated attribute from the signer information data. |

### `pUrlArray` [out]

A pointer to a buffer to receive the data for the value entry. This parameter can be **NULL** to find the length of the buffer required to hold the data.

For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbUrlArray` [in, out]

A pointer to a **DWORD** that specifies the size, in bytes, of the buffer pointed to by the *pUrlArray* parameter. When the function returns, the **DWORD** contains the number of bytes stored in the buffer. This parameter can be **NULL** only if *pUrlArray* is **NULL**.

### `pUrlInfo` [out]

An optional pointer to a
[CRYPT_URL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_url_info) structure that receives the data for the value entry.

### `pcbUrlInfo` [in, out]

A pointer to a **DWORD** that specifies the size, in bytes, of the buffer pointed to by the *pUrlArray* parameter. When the function returns, the **DWORD** contains the number of bytes stored in the buffer.

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer. On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

### `pvReserved`

Reserved for future use and must be **NULL**.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Remote Object Retrieval Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)