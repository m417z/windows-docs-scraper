# CRYPTNET_URL_CACHE_RESPONSE_INFO structure

## Description

The **CRYPTNET_URL_CACHE_RESPONSE_INFO** structure contains response information used by the Cryptnet URL Cache (CUC) service to maintain a URL cache entry. This structure composes the **pResponseInfo** member of the [CRYPT_RETRIEVE_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_retrieve_aux_info) structure, which is passed to [CryptRetrieveObjectByUrl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptretrieveobjectbyurla) as the *pAuxInfo* parameter.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `wResponseType`

A value that indicates whether the cache entry contains HTTP response information.

| Value | Meaning |
| --- | --- |
| **CRYPTNET_URL_CACHE_RESPONSE_NONE**<br><br>0 | The cache entry contains no response information. |
| **CRYPTNET_URL_CACHE_RESPONSE_HTTP**<br><br>1 | The cache entry contains response information derived from HTTP response headers. |

### `wResponseFlags`

A value that specifies a collection of flags that control server-based certificate validation response options.

### `LastModifiedTime`

A **FILETIME** structure that specifies the **Last-Modified** entity-header field value of the cached HTTP response for the URL.

### `dwMaxAge`

A value that specifies the number of seconds in the **max-age** directive of the **Cache-Control** header of the cached HTTP response for the URL.

### `pwszETag`

A pointer to a string that contains the **ETag** response-header field value of the cached HTTP response for the URL.

### `dwProxyId`

A value that contains the MD5 hash of the HTTP response header values **Via**, **ETag**, and **Last-Modified**, if they exist.

## Remarks

If not specified in the HTTP response headers, the cache service sets the values of the **LastModifiedTime**, **dwMaxAge**, **pwszETag**, and **dwProxyId** members to zero.

The cache service only allows a strong **ETag** in the **pwszETag** member.

To determine whether a response is valid, the cache service performs a bitwise **AND** of the **wResponseFlags** member with the following constant defined in Wincrypt.h. If the result is **TRUE**, the response is valid.

| Name | Value |
| --- | --- |
| CRYPTNET_URL_CACHE_RESPONSE_VALIDATED | 0x8000 |