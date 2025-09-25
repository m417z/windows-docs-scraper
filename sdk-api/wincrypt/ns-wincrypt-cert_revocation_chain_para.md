# CERT_REVOCATION_CHAIN_PARA structure

## Description

The **CERT_REVOCATION_CHAIN_PARA** structure contains parameters used for building a chain for an independent [online certificate status protocol](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_get_time_valid_object_extra_info) (OCSP) response signer certificate. The [CERT_REVOCATION_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_para) and [CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_get_time_valid_object_extra_info) structure definitions include optional pointers to this structure.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `hChainEngine`

A handle to the chain engine used by the caller.

### `hAdditionalStore`

A handle to a store that contains the certificates used to build the original chain. The handle can be **NULL**.

### `dwChainFlags`

A value for the *dwFlags* parameter passed to the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) function.

| Value | Meaning |
| --- | --- |
| **CERT_CHAIN_REVOCATION_CHECK_OCSP_CERT**<br><br>0x04000000 | This flag will be set by the [CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation) provider when it calls [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) with an independent OCSP signer certificate. When set, **CertGetCertificateChain** will call **CertVerifyRevocation** without setting the pointer to the above **CERT_REVOCATION_CHAIN_PARA** data structure; this helps to prevent circular revocation checking. |

### `dwUrlRetrievalTimeout`

A value that contains the time-out limit, in milliseconds. If zero, the revocation handler's default time-out is used.

### `pftCurrentTime`

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure used in the freshness time check. If this pointer is **NULL**, the revocation handler uses the current time.

### `pftCacheResync`

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that governs the use of cached information. Any information cached before this time is considered invalid and new information is retrieved. When set, this value overrides
the registry configuration CacheResync time.

### `cbMaxUrlRetrievalByteCount`

A **DWORD** value that specifies the maximum number of bytes to download from the URL object. A value of 0 specifies no limit.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This member is not supported.