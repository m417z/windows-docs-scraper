# ID2D1DeviceContext::IsDxgiFormatSupported

## Description

 Indicates whether the format is supported by the device context. The formats supported are usually determined by the underlying hardware.

## Parameters

### `format`

Type: **format**

The DXGI format to check.

## Return value

Type: **BOOL**

Returns TRUE if the format is supported. Returns FALSE if the format is not supported.

## Remarks

You can use supported formats in the [D2D1_PIXEL_FORMAT](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d1_pixel_format) structure to create bitmaps and render targets.

Direct2D doesn't support all DXGI formats, even though they may have some level of Direct3D support by the hardware.

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)