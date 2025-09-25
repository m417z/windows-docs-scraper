# IWICDdsFrameDecode::GetSizeInBlocks

## Description

Gets the width and height, in blocks, of the DDS image.

## Parameters

### `pWidthInBlocks` [out]

Type: **UINT***

The width of the DDS image in blocks.

### `pHeightInBlocks` [out]

Type: **UINT***

The height of the DDS image in blocks.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For block compressed textures, the returned width and height values do not completely define the texture size because the image is padded to fit the closest whole block size. For example, three BC1 textures with pixel dimensions of 1x1, 2x2 and 4x4 will all report *pWidthInBlocks* = 1 and *pHeightInBlocks* = 1.

If the texture does not use a block-compressed [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), this method returns the texture size in pixels; for these formats the block size returned by [IWICDdsFrameDecoder::GetFormatInfo](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicddsframedecode-getformatinfo) is 1x1.

## See also

[IWICDdsFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicddsframedecode)