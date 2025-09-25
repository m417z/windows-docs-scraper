# CRYPT_RETRIEVE_AUX_INFO structure

## Description

The **CRYPT_RETRIEVE_AUX_INFO** structure contains optional information to pass to the [CryptRetrieveObjectByUrl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptretrieveobjectbyurla) function. All unused members of this structure must contain zero.

## Members

### `cbSize`

The size, in bytes, of the structure.

### `pLastSyncTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time of the last synchronization of the data retrieved.

### `dwMaxUrlRetrievalByteCount`

A value that specifies a limit to the number of bytes retrieved. A value of zero or less specifies no limit.

### `pPreFetchInfo`

A pointer to a [CRYPTNET_URL_CACHE_PRE_FETCH_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cryptnet_url_cache_pre_fetch_info) structure. To get prefetch information, set its **cbSize** upon input. For no prefetch information, except for **cbSize**, the data structure contains zero upon return.

### `pFlushInfo`

A pointer to a [CRYPTNET_URL_CACHE_FLUSH_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cryptnet_url_cache_flush_info) structure. To get flush information, set its **cbSize** upon input. For no flush information, except for **cbSize**, the data structure
contains zero upon return.

### `ppResponseInfo`

A pointer to a [PCRYPTNET_URL_CACHE_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cryptnet_url_cache_response_info) structure. To get response information, set the pointer to the address of a **CRYPTNET_URL_CACHE_RESPONSE_INFO** pointer updated with the allocated structure. For no response information, **ppResponseInfo** is set to **NULL**. If it is not **NULL**, it must be freed by using the [CryptMemFree](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemfree) function.

### `pwszCacheFileNamePrefix`

A pointer to a string that contains a prefix for a cached file name. If not **NULL**, the specified prefix string is concatenated to the front of the cached file name.

### `pftCacheResync`

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies a cache synchronization time. If not **NULL**, any information cached before this time is considered time invalid. For a **CRYPT_CACHE_ONLY_RETRIEVAL**, if there is a cached entry before this time, [CryptRetrieveObjectByUrl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptretrieveobjectbyurla) returns **ERROR_INVALID_TIME**. When used with an HTTP retrieval, this specifies the maximum age for a time-valid object.

### `fProxyCacheRetrieval`

A value that indicates whether [CryptRetrieveObjectByUrl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptretrieveobjectbyurla) was called with **CRYPT_PROXY_CACHE_RETRIEVAL** set in *dwRetrievalFlags* and a proxy cache was not explicitly bypassed for the retrieval. This flag is not explicitly cleared and only applies to HTTP URL retrievals.

### `dwHttpStatusCode`

A value that specifies a status code from an unsuccessful HTTP response header. If **CRYPT_NOT_MODIFIED_RETRIEVAL** was set in *dwRetrievalFlags*, and the HTTP retrieval returns **HTTP_STATUS_NOT_MODIFIED**, this contains the **HTTP_STATUS_NOT_MODIFIED** status code. This value is not explicitly cleared and is only updated for HTTP or HTTPS URL retrievals.

### `ppwszErrorResponseHeaders`

### `ppErrorContentBlob`