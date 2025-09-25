# ID2D1DeviceContext::GetImageLocalBounds

## Description

Gets the bounds of an image without the world transform of the context applied.

## Parameters

### `image` [in]

Type: **[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)***

The image whose bounds will be calculated.

### `localBounds` [out]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)[1]**

When this method returns, contains a pointer to the bounds of the image in device independent pixels (DIPs) and in local space.

## Return value

This method does not return a value.

## Remarks

The image bounds don't include multiplication by the world transform. They do reflect the current DPI, unit mode, and interpolation mode of the context.
To get the bounds that include the world transform, use [ID2D1DeviceContext::GetImageWorldBounds](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-getimageworldbounds).

The returned bounds reflect which pixels would be impacted by calling [DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandsink-drawimage) with a
target offset of (0,0) and an identity world transform matrix. They do not reflect the current clip rectangle set on the device context or the extent of the context's current target image.

## See also

[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1DeviceContext::CreateBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmap(d2d1_size_u_constvoid_uint32_constd2d1_bitmap_properties1_id2d1bitmap1))

[ID2D1DeviceContext::GetImageWorldBounds](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-getimageworldbounds)

[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)