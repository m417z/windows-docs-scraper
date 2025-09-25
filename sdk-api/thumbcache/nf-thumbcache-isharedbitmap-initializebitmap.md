# ISharedBitmap::InitializeBitmap

## Description

Initializes a new [ISharedBitmap](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-isharedbitmap) object with a given bitmap.

## Parameters

### `hbm` [in]

Type: **HBITMAP**

A handle to the bitmap with which to initialize a new [ISharedBitmap](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-isharedbitmap) object. The bitmap must be a DIB.

### `wtsAT` [in]

Type: **WTS_ALPHATYPE**

The alpha type of the bitmap image. May be one of the following values.

#### WTSAT_UNKNOWN

Cannot determine whether the bitmap has an alpha channel.

#### WTSAT_RGB

The bitmap does not contain an alpha channel for transparency.

#### WTSAT_ARGB

The bitmap contains an alpha channel for transparency.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When an [ISharedBitmap](https://learn.microsoft.com/windows/desktop/api/thumbcache/nn-thumbcache-isharedbitmap) object is instantiated by the client (as opposed to being returned by the [IThumbnailCache::GetThumbnailByID](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailcache-getthumbnailbyid) or [IThumbnailCache::GetThumbnail](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailcache-getthumbnail) methods), the underlying bitmap will not reside in shared memory.