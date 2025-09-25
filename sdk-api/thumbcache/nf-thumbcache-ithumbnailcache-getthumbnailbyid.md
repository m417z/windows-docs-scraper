# IThumbnailCache::GetThumbnailByID

## Description

Gets a thumbnail from the thumbnail cache, given its ID.

## Parameters

### `thumbnailID` [in]

Type: **[WTS_THUMBNAILID](https://learn.microsoft.com/windows/desktop/api/thumbcache/ns-thumbcache-wts_thumbnailid)**

The ID of the thumbnail to retrieve. The ID is obtained by calling [GetThumbnail](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailcache-getthumbnail).

### `cxyRequestedThumbSize` [in]

Type: **UINT**

The requested thumbnail size in pixels. This value cannot be larger than 1024.

### `ppvThumb` [out, optional]

Type: **[ISharedBitmap](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-isharedbitmap)****

The address of a [ISharedBitmap](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-isharedbitmap) interface pointer that, when this method returns successfully, receives the object for accessing the requested thumbnail. This parameter can be **NULL**.

### `pOutFlags` [out, optional]

Type: **WTS_CACHEFLAGS***

A pointer to a value that, when this method returns successfully, receives a combination of the following flags. This value can be set to **NULL** if this information is not needed.

#### WTS_DEFAULT (0x00000000)

0x00000000.

#### WTS_LOWQUALITY (0x00000001)

0x00000001. Set when the returned bitmap dimensions are less than *cxyRequestedThumbSize*.

#### WTS_CACHED (0x00000002)

0x00000002. Set when the returned image is in the cache.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A parameter is invalid. |
| **WTS_E_FAILEDEXTRACTION** | The Shell item does not support thumbnail extraction. For example, .exe or .lnk items. |
| **WTS_E_EXTRACTIONTIMEDOUT** | The extraction took longer than the maximum allowable time. The extraction was not completed. |
| **WTS_E_SURROGATEUNAVAILABLE** | A surrogate process was not available to be used for the extraction process. |
| **WTS_E_FASTEXTRACTIONNOTSUPPORTED** | The WTS_FASTEXTRACT flag was set, but fast extraction is not available. |

## Remarks

This method is typically called after [GetThumbnail](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailcache-getthumbnail) has already been called to retrieve the thumbnail ID.