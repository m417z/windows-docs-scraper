# CRYPTNET_URL_CACHE_FLUSH_INFO structure

## Description

The **CRYPTNET_URL_CACHE_FLUSH_INFO** structure contains expiry information used by the Cryptnet URL Cache (CUC) service to maintain a URL cache entry. This structure composes the **pFlushInfo** member of the [CRYPT_RETRIEVE_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_retrieve_aux_info) structure that is passed to the [CryptRetrieveObjectByUrl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptretrieveobjectbyurla) method as the *pAuxInfo* parameter.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwExemptSeconds`

A value that specifies how long to extend the **ExpireTime** member. If prefetch is enabled, the CUC service ignores this value.

The following values have special meaning.

| Value | Meaning |
| --- | --- |
| **CRYPTNET_URL_CACHE_DEFAULT_FLUSH**<br><br>0 | Use the default flush exempt seconds for a retrieved URL. The following **REG_DWORD** constants define the default value of dwExemptSeconds for a computer.<br><br>CRYPTNET_URL_CACHE_DEFAULT_FLUSH_EXEMPT_SECONDS_VALUE_NAME L"CryptnetDefaultFlushExemptSeconds"<br><br>CRYPTNET_URL_CACHE_DEFAULT_FLUSH_EXEMPT_SECONDS_DEFAULT (28 * 24 * 60 * 60) |
| **CRYPTNET_URL_CACHE_DISABLE_FLUSH**<br><br>0xFFFFFFFF | Disable cache flushing for a retrieved URL. |

### `ExpireTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time the object expires.

## Remarks

The **dwExemptSeconds** member is added to the **ExpireTime** member to determine the flush time. If the **pLastSyncTime** member of the [CRYPT_RETRIEVE_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_retrieve_aux_info) structure is after the **ExpireTime** member, the **pLastSyncTime** member determines the flush time.