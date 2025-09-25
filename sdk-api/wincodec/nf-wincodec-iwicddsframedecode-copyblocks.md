# IWICDdsFrameDecode::CopyBlocks

## Description

Requests pixel data as it is natively stored within the DDS file.

## Parameters

### `prcBoundsInBlocks` [in]

Type: **const [WICRect](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicrect)***

The rectangle to copy from the source. A NULL value specifies the entire texture.

If the texture uses a block-compressed [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), all values of the rectangle are expressed in number of blocks, not pixels.

### `cbStride` [in]

Type: **UINT**

The stride, in bytes, of the destination buffer. This represents the number of bytes from the buffer pointer to the next row of data. If the texture uses a block-compressed [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), a "row of data" is defined as a row of blocks which contains multiple pixel scanlines.

### `cbBufferSize` [in]

Type: **UINT**

The size, in bytes, of the destination buffer.

### `pbBuffer` [out]

Type: **BYTE***

A pointer to the destination buffer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the texture does not use a block-compressed [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), this method behaves similarly to [IWICBitmapSource::CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels). However, it does not perform any pixel format conversion, and instead produces the raw data from the DDS file.

If the texture uses a block-compressed [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), this method copies the block data directly into the provided buffer. In this case, the *prcBoundsInBlocks* parameter is defined in blocks, not pixels. To determine if this is the case, call [GetFormatInfo](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicddsframedecode-getformatinfo) and read the **DxgiFormat** member of the returned [WICDdsFormatInfo](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicddsformatinfo) structure.

## See also

[IWICBitmapSource::CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels)

[IWICDdsFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicddsframedecode)