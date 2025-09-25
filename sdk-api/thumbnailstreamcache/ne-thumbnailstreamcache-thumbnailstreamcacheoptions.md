# ThumbnailStreamCacheOptions enumeration

## Description

Defines the cache options used by the [IThumbnailStreamCache](https://learn.microsoft.com/windows/desktop/api/thumbnailstreamcache/nn-thumbnailstreamcache-ithumbnailstreamcache) interface.

## Constants

### `ExtractIfNotCached:0`

Return the cached thumbnail if it is already cached, otherwise extract the thumbnail to the cache.

### `ReturnOnlyIfCached:0x1`

Return the thumbnail only if it is already cached.

### `ResizeThumbnail:0x2`

Resize the thumbnail to match the requested size.

### `AllowSmallerSize:0x4`

Can return a cached thumbnail that is smaller than the requested size.

## See also

[IThumbnailStreamCache](https://learn.microsoft.com/windows/desktop/api/thumbnailstreamcache/nn-thumbnailstreamcache-ithumbnailstreamcache)