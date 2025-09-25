# HTTP_CACHE_POLICY_TYPE enumeration

## Description

The
**HTTP_CACHE_POLICY_TYPE** enumeration type defines available cache policies. It is used to restrict the values of the **Policy** member of the
[HTTP_CACHE_POLICY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_cache_policy) structure, which in turn is used in the *pCachePolicy* parameter of the
[HttpAddFragmentToCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddfragmenttocache) function to specify how a response fragment is cached.

## Constants

### `HttpCachePolicyNocache`

Do not cache this value at all.

### `HttpCachePolicyUserInvalidates`

Cache this value until the user provides a different one.

### `HttpCachePolicyTimeToLive`

Cache this value for a specified time and then remove it from the cache.

### `HttpCachePolicyMaximum`

Terminates the enumeration; not used to determine policy.

## See also

[HTTP_CACHE_POLICY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_cache_policy)

[HttpAddFragmentToCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddfragmenttocache)