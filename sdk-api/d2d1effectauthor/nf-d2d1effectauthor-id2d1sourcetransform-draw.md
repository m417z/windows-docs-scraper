# ID2D1SourceTransform::Draw

## Description

Draws the transform to the graphics processing unit (GPU)–based Direct2D pipeline.

## Parameters

### `target` [in]

Type: **[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)***

The target to which the transform should be written.

### `drawRect` [in]

Type: **const [D2D1_RECT_L](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh847950(v=vs.85))***

The area within the source from which the image should be drawn.

### `targetOrigin`

Type: **[D2D1_POINT_2U](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2u)**

The origin within the target bitmap to which the source data should be drawn.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

The implementation of the rasterizer guarantees that adding the *renderRect* to the *targetOrigin* does not exceed the bounds of the bitmap.

When implementing this method you must update the bitmap in this way:

1. Call the [ID2D1Bitmap::Map](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1bitmap1-map) method with the D2D1_MAP_OPTIONS_DISCARD and D2D1_MAP_OPTIONS_WRITE
   flags.
2. Update the buffer this method returns.
3. Call the [ID2D1Bitmap::Unmap](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1bitmap1-unmap) method.

If you set the buffer precision manually on the associated [ID2D1RenderInfo](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1renderinfo) object, it must handle different pixel formats in this method by calling [ID2D1Bitmap::GetPixelFormat](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1bitmap-getpixelformat). If you set the buffer precision manually, then you can rely on that format always being the one you provided.

## See also

[ID2D1EffectImpl](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectimpl)

[ID2D1SourceTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1sourcetransform)