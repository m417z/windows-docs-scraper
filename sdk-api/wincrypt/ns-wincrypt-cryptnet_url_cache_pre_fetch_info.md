# CRYPTNET_URL_CACHE_PRE_FETCH_INFO structure

## Description

The **CRYPTNET_URL_CACHE_PRE_FETCH_INFO** structure contains update information used by the Cryptnet URL Cache (CUC) service to maintain a URL cache entry. This structure composes the **pPreFetchInfo** member of the [CRYPT_RETRIEVE_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_retrieve_aux_info) structure that is passed to the [CryptRetrieveObjectByUrl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptretrieveobjectbyurla) function as the *pAuxInfo* parameter.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwObjectType`

A value that specifies the type of object represented by the URL.

| Value | Meaning |
| --- | --- |
| **CRYPTNET_URL_CACHE_PRE_FETCH_NONE**<br><br>0 | Prefetch information does not yet exist. |
| **CRYPTNET_URL_CACHE_PRE_FETCH_BLOB**<br><br>1 | The object is a memory [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly). |
| **CRYPTNET_URL_CACHE_PRE_FETCH_CRL**<br><br>2 | The object is a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL). |
| **CRYPTNET_URL_CACHE_PRE_FETCH_OCSP**<br><br>3 | The object is an [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) response. |
| **CRYPTNET_URL_CACHE_PRE_FETCH_AUTOROOT_CAB**<br><br>5 | The object is a CAB file. |

### `dwError`

A value that specifies the status of a prefetch attempt.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The prefetch is pending. |
| **ERROR_MEDIA_OFFLINE**<br><br>4304L | The CRL prefetch is disabled because the OCSP service is offline or unavailable. |
| **ERROR_FILE_OFFLINE**<br><br>4350L | The prefetch content is unchanged. |
| **ERROR_INVALID_DATA**<br><br>13L | The prefetch content is not valid. |
| **Other values** | The service is unable to retrieve prefetch content. |

### `dwReserved`

This parameter is not used. It must be zero.

### `ThisUpdateTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains a date and time whose meaning depends on **dwObjectType**. For a CRL, this indicates when the CRL was published. For an OCSP response, this indicates when the indicated status is known to be correct.

### `NextUpdateTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains a date and time whose meaning depends on **dwObjectType**. For a CRL, this indicates the next scheduled update for the CRL. For an OCSP response, this indicates when newer information will be available for the certificate status.

This is effectively an expiry date for the object. A value of zero indicates that the information has no expiration date.

### `PublishTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies the time interval before expiry that a new CRL will be published. This value can be zero.

This value is based on a nonstandard CRL extension with the following [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

| Value | Meaning |
| --- | --- |
| **szOID_CRL_NEXT_PUBLISH**<br><br>1.3.6.1.4.1.311.21.4 | NextPublishTime |