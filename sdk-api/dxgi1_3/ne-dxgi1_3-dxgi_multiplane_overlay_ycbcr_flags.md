# DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS enumeration

## Description

Options for swap-chain color space.

## Constants

### `DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_NOMINAL_RANGE:0x1`

Specifies nominal range YCbCr, which isn't an absolute color space, but a way of encoding RGB info.

### `DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_BT709:0x2`

Specifies BT.709, which standardizes the format of high-definition television and has 16:9 (widescreen) aspect ratio.

### `DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_xvYCC:0x4`

Specifies xvYCC or extended-gamut YCC (also x.v.Color) color space that can be used in the video electronics of television sets to support a gamut 1.8 times as large as that of the sRGB color space.

## Remarks

This enum is used by [**SetColorSpace**](https://learn.microsoft.com/windows/win32/api/dxgi1_3/nf-dxgi1_3-idxgidecodeswapchain-setcolorspace).

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)