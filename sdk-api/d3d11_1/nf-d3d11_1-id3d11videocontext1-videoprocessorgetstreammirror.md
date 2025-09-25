# ID3D11VideoContext1::VideoProcessorGetStreamMirror

## Description

Gets values that indicate whether the video processor input stream is being flipped vertically or horizontally.

## Parameters

### `pVideoProcessor` [in]

Type: **ID3D11VideoProcessor***

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface.

### `StreamIndex` [in]

Type: **UINT**

An index identifying the input stream.

### `pEnable` [out]

Type: **BOOL***

A pointer to a boolean value indicating whether mirroring is enabled. True if mirroring is enabled; otherwise, false.

### `pFlipHorizontal` [out]

Type: **BOOL***

A pointer to a boolean value indicating whether the stream is being flipped horizontally. True if the stream is being flipped horizontally; otherwise, false.

### `pFlipVertical` [out]

Type: **BOOL***

A pointer to a boolean value indicating whether the stream is being flipped vertically. True if the stream is being flipped vertically; otherwise, false.

## See also

[ID3D11VideoContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videocontext1)