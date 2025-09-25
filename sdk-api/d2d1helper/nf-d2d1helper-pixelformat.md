# PixelFormat function

## Description

Creates a [D2D1_PIXEL_FORMAT](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d1_pixel_format) structure.

## Parameters

### `dxgiFormat` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A value that specifies the size and arrangement of channels in each pixel. The default value is [DXGI_FORMAT_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format).

### `alphaMode` [in]

Type: **[ALPHA_MODE](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-d2d1_alpha_mode)**

A value that specifies whether the alpha channel is using premultiplied alpha or straight alpha, or whether it should be ignored and considered opaque. The default value is [D2D1_ALPHA_MODE_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-d2d1_alpha_mode).

## Return value

Type: **[D2D1_PIXEL_FORMAT](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d1_pixel_format)**

A structure that contains the data format and alpha mode for a bitmap or render target.

## See also

[Supported Pixel Formats and Alpha Modes](https://learn.microsoft.com/windows/desktop/Direct2D/supported-pixel-formats-and-alpha-modes)