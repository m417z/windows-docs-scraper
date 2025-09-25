# IThumbnailStreamCache::GetThumbnailStream

## Description

Gets the thumbnail stream. This method is for internal use only and can only be called by the photos application.

## Parameters

### `path` [in]

The path to the thumbnail.

### `cacheId` [in]

The identifier of the thumbnail.

### `options` [in]

The cache options for the thumbnail stream.

### `requestedThumbnailSize` [in]

The requested size of the thumbnail.

### `thumbnailSize` [out]

The actual size of the returned thumbnail.

### `thumbnailStream` [out]

The requested thumbnail.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IThumbnailStreamCache](https://learn.microsoft.com/windows/desktop/api/thumbnailstreamcache/nn-thumbnailstreamcache-ithumbnailstreamcache)