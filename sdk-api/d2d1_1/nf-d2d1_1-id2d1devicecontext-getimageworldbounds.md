# ID2D1DeviceContext::GetImageWorldBounds

## Description

Gets the bounds of an image with the world transform of the context applied.

## Parameters

### `image` [in]

Type: **[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)***

The image whose bounds will be calculated.

### `worldBounds` [out]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)[1]**

When this method returns, contains a pointer to the bounds of the image in device independent pixels (DIPs).

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## Remarks

The image bounds reflect the current DPI, unit mode, and world transform of the context. To get bounds which don't include the world transform, use [ID2D1DeviceContext::GetImageLocalBounds](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-getimagelocalbounds).

The returned bounds reflect which pixels would be impacted by calling [DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawimage(id2d1effect_constd2d1_point_2f_constd2d1_rect_f_d2d1_interpolation_mode_d2d1_composite_mode)) with the same image and a target offset of (0,0). They do not reflect the current clip rectangle set on the device context or the extent of the context’s current target image.

## See also

[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1DeviceContext::CreateBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmap(d2d1_size_u_constvoid_uint32_constd2d1_bitmap_properties1_id2d1bitmap1))

[ID2D1DeviceContext::GetImageLocalBounds](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-getimagelocalbounds)

[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)