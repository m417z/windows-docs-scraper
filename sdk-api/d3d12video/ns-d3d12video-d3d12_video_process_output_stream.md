# D3D12_VIDEO_PROCESS_OUTPUT_STREAM structure

## Description

Represents the output stream for video processing commands. Points to the target surface for the processing operation.

## Members

### `pTexture2D`

A pointer to a [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) representing the output surfaces for the video process command.

### `Subresource`

The subresource indices to use within the resource specified *pTexture2D* resource.

## Remarks

## See also