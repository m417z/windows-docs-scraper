# CryptGetTimeValidObject function

## Description

The **CryptGetTimeValidObject** function retrieves a CRL, an OCSP response, or CTL object that is valid within a given context and time.

## Parameters

### `pszTimeValidOid` [in]

A pointer to an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that identifies the object being requested. If the [HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85)) of the *pszTimeValidOid* parameter is zero, the [LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85)) specifies the integer identifier for the type of the specified structure.

This parameter can be one of the following values. For information about how these values affect the pvPara parameter, see the heading "For the pvPara parameter" in the Meaning column.

| Value | Meaning |
| --- | --- |
| **TIME_VALID_OID_GET_CTL**<br><br>((LPCSTR)1) | Provides a certificate trust list (CTL) based on a URL obtained from the **NextUpdateLocation** property or extension of the current CTL context.<br><br>For the pvPara parameter: A pointer to a [PCCTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) that represents the current certificate trust list. |
| **TIME_VALID_OID_GET_CRL** | This value is reserved for future use. |
| **TIME_VALID_OID_GET_CRL_FROM_CERT**<br><br>((LPCSTR)3) | Provides a CRL based on information obtained from the CRL distribution points extension of the current certificate context.<br><br>For the pvPara parameter: A pointer to a [PCCERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) that represents the subject certificate. |
| **TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CERT**<br><br>((LPCSTR)4) | Provides a delta CRL based on information obtained from the freshest CRL extension of the current certificate context.<br><br>For the pvPara parameter: A pointer to a [PCCERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) that represents the subject certificate. |
| **TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CRL**<br><br>((LPCSTR)5) | Provides a delta CRL based on information obtained from the freshest CRL extension of the current CRL context.<br><br>For the pvPara parameter: A pointer to a [PCCERT_CRL_CONTEXT_PAIR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_crl_context_pair) that represents the subject certificate and its base CRL. |

### `pvPara` [in]

A structure determined by the value of *pszTimeValidOid*. For details, see the description for the *pszTimeValidOid* parameter.

### `pIssuer` [in]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) containing the issuer's certificate.

### `pftValidFor` [in, optional]

A pointer to an optional [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure version of the current system time or a freshness time from the current context.

### `dwFlags` [in]

A value that determines various retrieval factors such as time-out, source, and validity checks.

The following table lists possible values for the *dwFlags* parameter.

| Value | Meaning |
| --- | --- |
| **CRYPT_ACCUMULATIVE_TIMEOUT**<br><br>0x00000800 | Use the cumulative time-out registry setting of the client computer for revocation URL retrievals. |
| **CRYPT_CACHE_ONLY_RETRIEVAL**<br><br>0x00000002 | Retrieve the encoded bits from the client URL cache only. Do not use the wire to retrieve the URL. |
| **CRYPT_CHECK_FRESHNESS_TIME_VALIDITY**<br><br>0x00000400 | Check if the ThisUpdate property or extension of the current context is greater than or equal to the *ftValidFor* parameter. |
| **CRYPT_DONT_CHECK_TIME_VALIDITY**<br><br>0x00000200 | Do not perform time validity check. Use this to retrieve a more recent base CRL over the wire or to bypass time validity check during a cache retrieval. When this flag is set, *pftValidFor* can be **NULL**. |
| **CRYPT_DONT_VERIFY_SIGNATURE**<br><br>0x00000100 | Do not perform signature verification. Use this when verification of the retrieved object will be performed outside of this function or to force a replacement of a retrieved cache entry with a new cache entry for the object. |
| **CRYPT_KEEP_TIME_VALID**<br><br>0x00000080 | This value is reserved for future use. |
| **CRYPT_OCSP_ONLY_RETRIEVAL**<br><br>0x01000000 | Retrieves the time valid object from an OCSP responder service only based on Authority Information Access URLs in the current context. The [CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation) function sets this flag when it is called with the *dwFlags* parameter set to CERT_VERIFY_REV_SERVER_OCSP_FLAG. |
| **CRYPT_WIRE_ONLY_RETRIEVAL**<br><br>0x00000004 | Retrieves the encoded bits from the wire only. Does not use the URL cache. |

### `dwTimeout` [in]

A value, in milliseconds, that specifies when to terminate an URL retrieval attempt that has not returned a result.

### `ppvObject` [out, optional]

A pointer to an address for the returned object. The return type can be one of the supported types shown in the *pszObjectOid* parameter of the [CryptRetrieveObjectByUrl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptretrieveobjectbyurla) function.

### `pCredentials` [in, optional]

A pointer to an optional [CRYPT_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_credentials) structure used to access the URL. The only type of credentials currently supported are user name and password credentials.

### `pExtraInfo` [in, out, optional]

A pointer to an optional [CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_get_time_valid_object_extra_info) structure that contains extra information about the cache entry for an object.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

 Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_NOT_FOUND** | The caller specified **TIME_VALID_OID_GET_CRL** for the *pszTimeValidOid* parameter. This OID is not supported. |
| **CRYPT_E_NOT_IN_REVOCATION_DATABASE** | The caller set the CRYPT_OCSP_ONLY_RETRIEVAL flag and the context includes a non-OCSP URL. |
| **E_INVALIDARG** | The function failed to retrieve a CRL from a certificate context or retrieve a CTL, and it failed to copy any URLs from a cache entry. |
| **E_OUTOFMEMORY** | The function could not allocate memory for an internal array operation. |
| **ERROR_NOT_CONNECTED** | The caller did not set the **CRYPT_CACHE_ONLY_RETRIEVAL** flag and is not connected to the Internet. |

## Remarks

The Cryptnet dynamic link library implements a time valid object (TVO) cache that is used to support the **CryptGetTimeValidObject** function. The cache is used by a process-global TVO agent where each cache entry consists of the following information.

* Origin Identifier
* Context OID
* Context
* Retrieval URL
* Expire Time
* Offline URL Time Information

The TVO agent supports retrieval of TVO objects on-demand or by auto-update.