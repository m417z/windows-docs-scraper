# CryptRetrieveObjectByUrlA function

## Description

The **CryptRetrieveObjectByUrl** function retrieves the public key infrastructure (PKI) object from a location specified by a URL.

These remote objects are in encoded format and are retrieved in a "context" form.

## Parameters

### `pszUrl` [in]

The address of a PKI object to be retrieved. The following schemes are supported:

* ldap ([Lightweight Directory Access Protocol](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly))
* http
* https ([certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) or [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) retrievals only)
* file

### `pszObjectOid` [in]

The address of a null-terminated ANSI string that identifies the type of object to retrieve. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NULL**<br><br>BLOB | Retrieve one or more data [BLOBs](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly). The encoded bits are returned in an array of BLOBs. *ppvObject* is the address of a [CRYPT_BLOB_ARRAY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_blob_array) structure pointer that receives the BLOB array. When this structure is no longer needed, you must free it by passing the address of this structure to the [CryptMemFree](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemfree) function. |
| **CONTEXT_OID_CERTIFICATE**<br><br>certificate | Retrieve one or more certificates.<br><br>If a single object is being retrieved, *ppvObject* is the address of a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure pointer that receives the context. When this context is no longer needed, you must free it by passing the **CERT_CONTEXT** structure pointer to the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function.<br><br>If multiple objects are being retrieved, *ppvObject* is the address of an **HCERTSTORE** variable that receives the handle of a store that contains the certificates. When this store is no longer needed, you must close it by passing this handle to the [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) function. |
| **CONTEXT_OID_CRL**<br><br>CRL | Retrieve one or more [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs). <br><br>If a single object is being retrieved, *ppvObject* is the address of a [CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure pointer that receives the context. When this context is no longer needed, you must free it by passing the **CRL_CONTEXT** structure pointer to the [CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext) function.<br><br>If multiple objects are being retrieved, *ppvObject* is the address of an **HCERTSTORE** variable that receives the handle of a store that contains the CRLs. When this store is no longer needed, you must close it by passing this handle to the [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) function. |
| **CONTEXT_OID_CTL**<br><br>CTL | Retrieve one or more [certificate trust lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTLs). <br><br>If a single object is being retrieved, *ppvObject* is the address of a [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure pointer that receives the context. When this context is no longer needed, you must free it by passing the **CTL_CONTEXT** structure pointer to the [CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext) function.<br><br>If multiple objects are being retrieved, *ppvObject* is the address of an **HCERTSTORE** variable that receives the handle of a store that contains the CTLs. When this store is no longer needed, you must close it by passing this handle to the [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) function. |
| **CONTEXT_OID_PKCS7**<br><br>PKCS7 | *ppvObject* is the address of an **HCERTSTORE** variable that receives the handle of a store that contains the objects from the message. When this store is no longer needed, you must close it by passing this handle to the [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) function. |
| **CONTEXT_OID_CAPI2_ANY**<br><br>Function will determine appropriate item | *ppvObject* is the address of an **HCERTSTORE** variable that receives the handle of a store that contains the objects. When this store is no longer needed, you must close it by passing this handle to the [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) function. |
| **CONTEXT_OID_OCSP_RESP**<br><br>OCSP Response | *ppvObject* is the address of a pointer to a [CRYPT_BLOB_ARRAY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_blob_array) structure. |

### `dwRetrievalFlags` [in]

Determines whether to use the cached URL or a URL retrieved from the wire URL. The form in which objects are returned is determined by the value of *pszObjectOid*.

| Value | Meaning |
| --- | --- |
| **CRYPT_AIA_RETRIEVAL** | Validates the content retrieved by a wire URL before writing the URL to the cache.<br><br>The default provider does not support the HTTPS protocol for AIA retrievals. |
| **CRYPT_ASYNC_RETRIEVAL** | This value is not supported. |
| **CRYPT_CACHE_ONLY_RETRIEVAL** | Retrieves the encoded bits from the URL cache only. Do not use the wire to retrieve the URL. |
| **CRYPT_DONT_CACHE_RESULT** | Does not store the retrieved encoded bits to the URL cache. If this flag is not set, the retrieved URL is cached. |
| **CRYPT_HTTP_POST_RETRIEVAL** | Uses the POST method instead of the default GET method for HTTP retrievals.<br><br>In a POST URL, additional binary data and header strings are appended to the base URL in the following format:<br><br>*BaseURL***/***OptionalURLEscaped&Base64EncodedAdditionalData***?***OptionalAdditionalHTTPHeaders*<br><br>The following example shows the additional binary data delimited by the last slash mark (/) and a Content-Type header delimited by a question mark (?) appended to a base URL.<br><br>`http://ocsp.openvalidation.org/MEIwQDA%2BMDwwOjAJBgUrDgMCGgUABBQdKNEwjytjKBQADcgM61jfflNpyQQUv1NDgnjQnsOA5RtnygUA37lIg6UCAQI%3D?Content-Type: application/ocsp-request`<br><br>When this flag is set, the **CryptRetrieveObjectByUrl** function parses the URL by using the last slash mark (/) and question mark (?) delimiters. The string, which is delimited by a slash mark (/), contains an unescaped URL (that is, a plain text URL without escape characters or escape sequences) and Base64 data decoded into binary form before being passed to the [WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest) function as the *lpOptional* parameter. The string delimited by a question mark (?) is passed to the **WinHttpSendRequest** function as the *pwszHeaders* parameter. |
| **CRYPT_LDAP_AREC_EXCLUSIVE_RETRIEVAL** | Performs A-Record-only DNS lookup on the supplied host string, preventing the generation of false DNS queries when resolving host names. This flag should be used when passing a host name as opposed to a domain name. |
| **CRYPT_LDAP_INSERT_ENTRY_ATTRIBUTE** | Retrieves the entry index and attribute name for each LDAP object. The beginning of each returned BLOB contains the following ANSI string:<br><br>"*entry index in decimal*\0*attribute name*\0"<br><br>When this flag is set, *pszObjectOid* must be **NULL** so that a BLOB is returned. This flag only applies to the ldap scheme. |
| **CRYPT_LDAP_SCOPE_BASE_ONLY_RETRIEVAL** | Fails if the LDAP search scope is not set to base in the URL. Use with LDAP only. |
| **CRYPT_LDAP_SIGN_RETRIEVAL** | Digitally signs all of the LDAP traffic to and from a server by using the Kerberos authentication protocol. This feature provides integrity required by some applications. |
| **CRYPT_NO_AUTH_RETRIEVAL** | Inhibits automatic authentication handling. |
| **CRYPT_NOT_MODIFIED_RETRIEVAL** | Enables a conditional HTTP URL retrieval. When this flag is set, for a conditional retrieval that returns **HTTP_STATUS_NOT_MODIFIED**, **CryptRetrieveObjectByUrl** returns **TRUE** and *ppvObject* is set to **NULL**. If *pAuxInfo* is not **NULL**, **dwHttpStatusCode** is set to **HTTP_STATUS_NOT_MODIFIED**. Otherwise, *ppvObject* is updated for a successful retrieval. |
| **CRYPT_OFFLINE_CHECK_RETRIEVAL** | Keeps track of offline failures and delays before hitting the wire on subsequent retrievals. This value is for wire retrieval only. |
| **CRYPT_PROXY_CACHE_RETRIEVAL** | Enables proxy cache retrieval of an object. If a proxy cache was not explicitly bypassed, **fProxyCacheRetrieval** is set to **TRUE** in *pAuxInfo*. This value only applies to HTTP URL retrievals. |
| **CRYPT_RETRIEVE_MULTIPLE_OBJECTS** | Retrieves multiple objects if available. All objects must be of a homogeneous object type as determined by the value of *pszObjectOid*, unless the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) value is CONTEXT_OID_CAPI2_ANY. |
| **CRYPT_STICKY_CACHE_RETRIEVAL** | Tags the URL as exempt from being flushed from the cache. For more information, see STICKY_CACHE_ENTRY in INTERNET_CACHE_ENTRY_INFO. |
| **CRYPT_VERIFY_CONTEXT_SIGNATURE** | Acquires signature verification on the context created. In this case *pszObjectOid* must be non-**NULL** and *pvVerify* points to the signer certificate context. |
| **CRYPT_VERIFY_DATA_HASH** | This flag is not implemented. Do not use it. |
| **CRYPT_WIRE_ONLY_RETRIEVAL** | Retrieves the encoded bits from the wire only. Does not use the URL cache. |

### `dwTimeout` [in]

Specifies the maximum number of milliseconds to wait for retrieval. If a value of zero is specified, this function does not time out. This parameter is not used if the URL scheme is file:///.

### `ppvObject` [out]

The address of a pointer to the returned object. The return type can be one of the supported types shown in *pszObjectOid*.

### `hAsyncRetrieve` [in]

This parameter is reserved and must be set to **NULL**.

### `pCredentials` [in, optional]

This parameter is not used.

### `pvVerify` [in, optional]

A pointer to a verification object. This object is a function of the *dwRetrievalFlags* parameter. It can be **NULL** to indicate that the caller is not interested in getting the certificate context or index of the signer if *dwRetrievalFlags* is CRYPT_VERIFY_CONTEXT_SIGNATURE.

### `pAuxInfo` [in]

An optional pointer to a
[CRYPT_RETRIEVE_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_retrieve_aux_info) structure. If not **NULL** and if the **cbSize** member of the structure is set, this parameter returns the time of the last successful wire retrieval.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**).

## Remarks

The remote object retrieval manager exposes two provider models. One is the Scheme Provider model that allows for installable protocol providers as defined by the URL scheme, that is, ldap, http, ftp, or file. The scheme provider entry point is the same as the **CryptRetrieveObjectByUrl** function; however, the **ppvObject* returned is always a counted array of encoded bits (one per object retrieved).

The second provider model is the Context Provider model that allows for installable creators of the context handles (objects) based on the retrieved encoded bits. These are dispatched based on the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) specified in the call to **CryptRetrieveObjectByUrl**.

Individual PKI objects such as certificates, trusts lists, revocation lists, PKCS #7 messages, and multiple homogeneous objects can be retrieved. Starting with Windows Vista with Service Pack 1 (SP1) and Windows Server 2008, security of "http:" and "ldap:" retrievals have been hardened.
This function supports "http:" and "ldap:" URL schemes as well as newly defined schemes.

**Windows XP:** "ftp:" is not supported for network retrieval.

**Note** By default, "file:" is not supported for network retrieval.

> [!NOTE]
> The wincrypt.h header defines CryptRetrieveObjectByUrl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CryptGetObjectUrl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetobjecturl)