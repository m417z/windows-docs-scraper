# WICDdsFormatInfo structure

## Description

Specifies the [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) and block information of a DDS format.

## Members

### `DxgiFormat`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)

### `BytesPerBlock`

Type: **UINT**

The size of a single block in bytes. For [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) values that are not block-based, the value is equal to the size of a single pixel in bytes.

### `BlockWidth`

Type: **UINT**

The width of a single block in pixels. For [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) values that are not block-based, the value is 1.

### `BlockHeight`

Type: **UINT**

The height of a single block in pixels. For [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) values that are not block-based, the value is 1.

## See also

[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)