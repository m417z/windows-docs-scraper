# IThumbnailStreamCache::SetThumbnailStream

## Description

Sets the thumbnail stream. This method is for internal use only and can only be called by the photos application.

## Parameters

### `path` [in]

The path to the thumbnail.

### `cacheId` [in]

The identifier of the thumbnail.

### `thumbnailSize` [in]

The size of the thumbnail.

### `thumbnailStream` [in]

The pointer to the thumbnail stream.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IThumbnailStreamCache](https://learn.microsoft.com/windows/desktop/api/thumbnailstreamcache/nn-thumbnailstreamcache-ithumbnailstreamcache)