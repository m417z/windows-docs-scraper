# ID2D1DeviceContext::CreateBitmap(D2D1_SIZE_U,const void,UINT32,const D2D1_BITMAP_PROPERTIES1 &,ID2D1Bitmap1)

## Description

Creates a bitmap that can be used as a target surface, for reading back to the CPU, or as a source for the [DrawBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawbitmap(id2d1bitmap_constd2d1_rect_f__float_d2d1_interpolation_mode_constd2d1_rect_f_constd2d1_matrix_4x4_f)) and [ID2D1BitmapBrush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1bitmapbrush) APIs. In addition, color context information can be passed to the bitmap.

## Parameters

### `size`

Type: **[D2D1_SIZE_U](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-size-u)**

The pixel size of the bitmap to be created.

### `sourceData` [in, optional]

Type: **const void***

The initial data that will be loaded into the bitmap.

### `pitch`

Type: **UINT32**

The pitch of the source data, if specified.

### `bitmapProperties` [in]

Type: **const [D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_properties1)***

The properties of the bitmap to be created.

### `bitmap` [out]

Type: **[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)****

When this method returns, contains the address of a pointer to a new bitmap object.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |
| D3DERR_OUTOFVIDEOMEMORY | Direct3D does not have enough display memory to perform the operation. |

## Remarks

The new bitmap can be used as a target for [SetTarget](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-settarget) if it is created with [D2D1_BITMAP_OPTIONS_TARGET](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_bitmap_options).

## See also

[D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_properties1)

[D2D1_SIZE_U](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-size-u)

[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)