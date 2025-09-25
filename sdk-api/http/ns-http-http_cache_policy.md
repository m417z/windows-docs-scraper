# HTTP_CACHE_POLICY structure

## Description

The
**HTTP_CACHE_POLICY** structure is used to define a cache policy associated with a cached response fragment.

## Members

### `Policy`

This parameter is one of the following values from the [HTTP_CACHE_POLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_cache_policy_type) to control how an associated response or response fragment is cached.

| Value | Meaning |
| --- | --- |
| **HttpCachePolicyNocache** | Do not cache the data at all. |
| **HttpCachePolicyUserInvalidates** | Cache the data until the application explicitly releases it. |
| **HttpCachePolicyTimeToLive** | Cache the data for a number of seconds specified by the **SecondsToLive** member. |

### `SecondsToLive`

When the **Policy** member is equal to HttpCachePolicyTimeToLive, data is cached for **SecondsToLive** seconds before it is released. For other values of **Policy**, **SecondsToLive** is ignored.

## See also

[HttpAddFragmentToCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddfragmenttocache)