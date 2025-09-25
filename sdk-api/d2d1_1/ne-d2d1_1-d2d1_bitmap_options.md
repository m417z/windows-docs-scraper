# D2D1_BITMAP_OPTIONS enumeration

## Description

Specifies how a bitmap can be used.

## Constants

### `D2D1_BITMAP_OPTIONS_NONE:0x00000000`

The bitmap is created with default properties.

### `D2D1_BITMAP_OPTIONS_TARGET:0x00000001`

The bitmap can be used as a device context target.

### `D2D1_BITMAP_OPTIONS_CANNOT_DRAW:0x00000002`

The bitmap cannot be used as an input.

### `D2D1_BITMAP_OPTIONS_CPU_READ:0x00000004`

The bitmap can be read from the CPU.

### `D2D1_BITMAP_OPTIONS_GDI_COMPATIBLE:0x00000008`

The bitmap works with [ID2D1GdiInteropRenderTarget::GetDC](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1gdiinteroprendertarget-getdc).

**Note** This flag is not available in Windows Store apps.

### `D2D1_BITMAP_OPTIONS_FORCE_DWORD:0xffffffff`

## Remarks

**D2D1_BITMAP_OPTIONS_NONE** implies that none of the flags are set. This means that the bitmap can be used for drawing from, cannot be set as a target and cannot be read from by the CPU.

**D2D1_BITMAP_OPTIONS_TARGET** means that the bitmap can be specified as a target in [ID2D1DeviceContext::SetTarget](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-settarget). If you also specify the **D2D1_BITMAP_OPTIONS_CANNOT_DRAW** flag the bitmap can be used a target but, it cannot be drawn from. Attempting to draw with a bitmap that has both flags set will result in the device context being put into an error state with **D2DERR_BITMAP_CANNOT_DRAW**.

**D2D1_BITMAP_OPTIONS_CPU_READ** means that the bitmap can be mapped by using [ID2D1Bitmap1::Map](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1bitmap1-map). This flag requires **D2D1_BITMAP_OPTIONS_CANNOT_DRAW** and cannot be combined with any other flags. The bitmap must be updated with the [CopyFromBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1bitmap-copyfrombitmap) or [CopyFromRenderTarget](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1bitmap-copyfromrendertarget) methods.

**Note** You should only use **D2D1_BITMAP_OPTIONS_CANNOT_DRAW** is when the purpose of the bitmap is to be a target only or when the bitmap will be mapped .

**D2D1_BITMAP_OPTIONS_GDI_COMPATIBLE** means that it is possible to get a DC associated with this bitmap. This must be used in conjunction with **D2D1_BITMAP_OPTIONS_TARGET**. The [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) must be either **DXGI_FORMAT_B8G8R8A8_UNORM** or **DXGI_FORMAT_B8G8R8A8_UNORM_SRGB**.

## See also

[ID2D1DeviceContext::CreateBitmap](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createbitmap(d2d1_size_u_constvoid_uint32_constd2d1_bitmap_properties1_id2d1bitmap1))