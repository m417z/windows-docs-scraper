# ID3D11VideoContext1::VideoProcessorGetStreamColorSpace1

## Description

Gets the color space information for the video processor input stream.

## Parameters

### `pVideoProcessor` [in]

Type: **ID3D11VideoProcessor***

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface.

### `StreamIndex` [in]

Type: **UINT**

An index identifying the input stream.

### `pColorSpace` [out]

Type: **DXGI_COLOR_SPACE_TYPE***

A pointer to a [DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type) value that specifies the colorspace for the video processor input stream.

## See also

[ID3D11VideoContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videocontext1)