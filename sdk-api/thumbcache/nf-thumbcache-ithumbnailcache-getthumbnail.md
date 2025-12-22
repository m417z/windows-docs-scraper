# IThumbnailCache::GetThumbnail

## Description

Gets a cached thumbnail for a given Shell item.

## Parameters

### `pShellItem` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the Shell item for which to retrieve a thumbnail.

### `cxyRequestedThumbSize` [in]

Type: **UINT**

The requested thumbnail size in pixels. The maximum value is 1024.

### `flags` [in]

Type: **[WTS_FLAGS](https://learn.microsoft.com/windows/desktop/api/thumbcache/ne-thumbcache-wts_flags)**

A combination of values from the [WTS_FLAGS](https://learn.microsoft.com/windows/desktop/api/thumbcache/ne-thumbcache-wts_flags) enumeration. See the Remarks section for rules and a list of possible combinations.

### `ppvThumb` [out, optional]

Type: **[ISharedBitmap](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-isharedbitmap)****

The address of an [ISharedBitmap](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-isharedbitmap) pointer that, when this method returns successfully, receives the object used to access the thumbnail. This parameter may be **NULL**.

### `pOutFlags` [out, optional]

Type: **WTS_CACHEFLAGS***

A pointer to a value that, when this method returns successfully, receives a combination of the following flags from the WTS_CACHEFLAGS enumeration.

#### WTS_DEFAULT (0x00000000)

0x00000000.

#### WTS_LOWQUALITY (0x00000001)

0x00000001. Set when the returned bitmap dimensions are less than *cxyRequestedThumbSize*.

#### WTS_CACHED (0x00000002)

0x00000002. Set when the returned image is in the cache.

### `pThumbnailID` [out, optional]

Type: **[WTS_THUMBNAILID](https://learn.microsoft.com/windows/desktop/api/thumbcache/ns-thumbcache-wts_thumbnailid)***

A pointer to a value that, when this method returns successfully, receives a unique ID for the returned thumbnail. This parameter may be **NULL**, in which case the thumbnail ID is discarded.

## Return value

Type: **HRESULT**

Returns S_OK if successful or a standard COM error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A parameter is invalid. |
| **WTS_E_FAILEDEXTRACTION** | The Shell item does not support thumbnail extraction. For example, .exe or .lnk items. |
| **WTS_E_EXTRACTIONTIMEDOUT** | The extraction took longer than the maximum allowable time. The extraction was not completed. |
| **WTS_E_SURROGATEUNAVAILABLE** | A surrogate process was not available to be used for the extraction process. |
| **WTS_E_FASTEXTRACTIONNOTSUPPORTED** | The WTS_FASTEXTRACT flag was set, but fast extraction is not available. |

## Remarks

If a thumbnail is extracted, it will be cached unless WTS_EXTRACTDONOTCACHE is specified.

The following combinations are valid for the flags parameter.

|  |
| --- |
| WTS_INCACHEONLY |
| WTS_FASTEXTRACT |
| WTS_EXTRACT |
| WTS_EXTRACT \| WTS_SLOWRECLAIM |
| WTS_FORCEEXTRACTION |
| WTS_FORCEEXTRACTION \| WTS_SLOWRECLAIM |
| WTS_EXTRACTDONOTCACHE |

[GetImage](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitemimagefactory-getimage) also uses this cache and can provide an easier way to retrieve the thumbnail. However, **GetImage** is more general and will retrieve an icon as a fallback.

## See also

[IShellItemImageFactory::GetImage](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitemimagefactory-getimage)

[IThumbnailCache](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-ithumbnailcache)