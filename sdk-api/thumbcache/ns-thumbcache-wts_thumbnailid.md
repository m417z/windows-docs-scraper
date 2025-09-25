# WTS_THUMBNAILID structure

## Description

Contains a unique identifier for a thumbnail in the system thumbnail cache.

## Members

### `rgbKey`

Type: **BYTE[16]**

An array of 16 bytes that make up a unique identifier for a thumbnail in the system thumbnail cache.

## Remarks

A **WTS_THUMBNAILID** may be retrieved from [IThumbnailCache::GetThumbnail](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailcache-getthumbnail) when a new thumbnail is cached. To access the cached thumbnail by its ID, the **WTS_THUMBNAILID** may then be passed to [IThumbnailCache::GetThumbnailByID](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailcache-getthumbnailbyid).

## See also

[IThumbnailCache::GetThumbnail](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailcache-getthumbnail)

[IThumbnailCache::GetThumbnailByID](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailcache-getthumbnailbyid)