# WTS_FLAGS enumeration

## Description

Values used by [IThumbnailCache::GetThumbnail](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailcache-getthumbnail) to specify options for the extraction and display of the thumbnail image.

## Constants

### `WTS_NONE:0`

0x00000000. **Introduced in Windows 8**. None of the following options are set.

### `WTS_EXTRACT:0`

Default. 0x00000000. Extract the thumbnail if it is not cached.

### `WTS_INCACHEONLY:0x1`

0x00000001. Only return the thumbnail if it is cached.

### `WTS_FASTEXTRACT:0x2`

0x00000002. If not cached, only extract the thumbnail if it is embedded in EXIF format, typically 96x96.

### `WTS_FORCEEXTRACTION:0x4`

0x00000004. Ignore cache and extract thumbnail from source file.

### `WTS_SLOWRECLAIM:0x8`

0x00000008. The thumbnail has an extended lifetime. Use for volumes that might go offline, like non-fixed disks.

### `WTS_EXTRACTDONOTCACHE:0x20`

0x00000020. Extract but do not add the thumbnail to the cache.

### `WTS_SCALETOREQUESTEDSIZE:0x40`

0x00000040. **Introduced in Windows 7**. If the specific thumbnail size requested in the *cxyRequestedThumbSize* parameter is not available, resize the thumbnail to the requested size. If possible, a larger bitmap is reduced in scale, preserving its aspect ratio, to the width and height required. If the only available cached thumbnail is smaller than the requested size, then it is scaled up using the nearest-neighbor algorithm.

### `WTS_SKIPFASTEXTRACT:0x80`

0x00000080. **Introduced in Windows 7**. Do not extract a thumbnail embedded in the metadata of an EXIF image.

### `WTS_EXTRACTINPROC:0x100`

0x00000100. **Introduced in Windows 7**. Ensures that the thumbnail handler is loaded in the same process as the caller. When this flag is not specified, the handler is loaded into a surrogate process to protect the caller from unexpected crashes caused by the processing of the target file. Use this value when debugging thumbnail extractors.

### `WTS_CROPTOSQUARE:0x200`

0x00000200. **Introduced in Windows 8**. If necessary, crop the bitmap's dimensions so that is square. The length of the shortest side becomes the length of all sides.

### `WTS_INSTANCESURROGATE:0x400`

0x00000400. **Introduced in Windows 8**. Create a surrogate for this instance of the cache rather than using the shared DLLHost surrogate.

### `WTS_REQUIRESURROGATE:0x800`

0x00000800. **Introduced in Windows 8**. Require extractions to take place in the surrogate.

### `WTS_APPSTYLE:0x2000`

0x00002000. **Windows 8 and later**. Pass the [WTSCF_APPSTYLE](https://learn.microsoft.com/windows/desktop/api/thumbcache/ne-thumbcache-wts_contextflags) flag to [IThumbnailSettings::SetContext](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailsettings-setcontext), if the provider supports it.

### `WTS_WIDETHUMBNAILS:0x4000`

0x00004000. **Windows 8 and later**. Stretch and crop the bitmap so that its height is 0.7 times its width.

### `WTS_IDEALCACHESIZEONLY:0x8000`

0x00008000. **Windows 8 and later**. Return from the ideal cache snap size only. The returned image might be larger, but it will be pulled from the correct cache entry.

### `WTS_SCALEUP:0x10000`

0x00010000. **Windows 8 and later**. If necessary, stretch the image so that the height and width fit the given size.

## Remarks

The following combinations are valid.

|  |
| --- |
| WTS_INCACHEONLY |
| WTS_FASTEXTRACT |
| WTS_EXTRACT |
| WTS_EXTRACT | WTS_SLOWRECLAIM |
| WTS_FORCEEXTRACTION |
| WTS_FORCEEXTRACTION | WTS_SLOWRECLAIM |
| WTS_EXTRACTDONOTCACHE |

## See also

[IThumbnailCache::GetThumbnail](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailcache-getthumbnail)

[IThumbnailSettings::SetContext](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailsettings-setcontext)