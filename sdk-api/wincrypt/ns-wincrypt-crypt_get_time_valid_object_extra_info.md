# CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO structure

## Description

 The **CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO** structure contains optional extra information that can be passed to the [CryptGetTimeValidObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgettimevalidobject) function in the *pExtraInfo* parameter.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `iDeltaCrlIndicator`

A value used to compare to the base [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) number. If the base CRL number is less than this value, the caller should attempt to retrieve a newer base CRL.

If the **pDeltaCrlIndicator** member is non-**NULL** the value of this member must be 0x7fffffff.**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** Because the **pDeltaCrlIndicator** member does not exist, the **iDeltaCrlIndicator** value requirement does not apply.

### `pftCacheResync`

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that governs the use of cached information. Any information cached before this time is considered invalid and new information is retrieved.

### `pLastSyncTime`

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time of the last synchronization of the data retrieved for the object.

### `pMaxAgeTime`

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies an expiration time of the data retrieved based on the **dwMaxAge** member of the [CRYPTNET_URL_CACHE_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cryptnet_url_cache_response_info) structure.

### `pChainPara`

A pointer to a [CERT_REVOCATION_CHAIN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_chain_para) structure that contains the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) function parameters used by the caller. The data in this member enables independent [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) signer certificate chain verification.

### `pDeltaCrlIndicator`

A pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains a CRL with a length of more than 4 bytes. If this member is non-**NULL** and the **iDeltaCrlIndicator** member is equal to **MAXLONG**, then if the base CRL number is less than this value, the caller should attempt to retrieve a newer base CRL.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This member is not supported.

## Remarks

All members of the **CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO** structure that do not have a value must be set to zero.