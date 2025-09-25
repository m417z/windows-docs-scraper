# D2D1_IMAGE_SOURCE_LOADING_OPTIONS enumeration

## Description

Controls option flags for a new ID2D1ImageSource when it is created.

## Constants

### `D2D1_IMAGE_SOURCE_LOADING_OPTIONS_NONE:0`

No options are used.

### `D2D1_IMAGE_SOURCE_LOADING_OPTIONS_RELEASE_SOURCE:1`

Indicates the image source should release its reference to the WIC bitmap source after it has initialized.
By default, the image source retains a reference to the WIC bitmap source for the lifetime of the object to enable quality and speed optimizations for printing.
This option disables that optimization.

### `D2D1_IMAGE_SOURCE_LOADING_OPTIONS_CACHE_ON_DEMAND:2`

Indicates the image source should only populate subregions of the image cache on-demand. You can control this behavior using
the [EnsureCached](https://learn.microsoft.com/windows/win32/api/d2d1_3/nf-d2d1_3-id2d1imagesourcefromwic-ensurecached(constd2d1_rect_u))
and [TrimCache](https://learn.microsoft.com/windows/win32/api/d2d1_3/nf-d2d1_3-id2d1imagesourcefromwic-trimcache(constd2d1_rect_u)) methods.
This options provides the ability to improve memory usage by only keeping needed portions of the image in memory.
This option requires that the image source has a reference to the WIC bitmap source, and is incompatible with D2D1_IMAGE_SOURCE_LOADING_OPTIONS_RELEASE_SOURCE.

### `D2D1_IMAGE_SOURCE_LOADING_OPTIONS_FORCE_DWORD:0xffffffff`

## Remarks

D2D1_IMAGE_SOURCE_CREATION_OPTIONS_RELEASE_SOURCE causes the image source to not retain a reference to the source object used to create it.
It can decrease the quality and efficiency of printing.