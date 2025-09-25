# ID3D11VideoContext1::VideoProcessorSetStreamMirror

## Description

Specifies whether the video processor input stream should be flipped vertically or horizontally.

## Parameters

### `pVideoProcessor` [in]

Type: **ID3D11VideoProcessor***

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface.

### `StreamIndex` [in]

Type: **UINT**

An index identifying the input stream.

### `Enable` [in]

Type: **BOOL**

True if mirroring should be enabled; otherwise, false.

### `FlipHorizontal` [in]

Type: **BOOL**

True if the stream should be flipped horizontally; otherwise, false.

### `FlipVertical` [in]

Type: **BOOL**

True if the stream should be flipped vertically; otherwise, false.

## Remarks

When used in combination, transformations on the processor input stream should be applied in the following order:

* Rotation
* Mirroring
* Source clipping

## See also

[ID3D11VideoContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videocontext1)