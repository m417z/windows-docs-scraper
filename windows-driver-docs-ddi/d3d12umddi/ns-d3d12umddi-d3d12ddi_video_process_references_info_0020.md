# D3D12DDI_VIDEO_PROCESS_REFERENCES_INFO_0020 structure

## Description

Contains the reference frames needed to perform video processing.

## Members

### `NumPastFrames`

The number of past reference frames.

### `hDrvPastFrames`

A pointer to an array of surfaces. The number of elements in the array is the value of the *NumPastFrames* parameter.

### `pPastSubresources`

An array of subresource indexes for the list of past frames textures. A value of null indicates subresource of zero (0) for each resource.

### `NumFutureFrames`

The number of future reference frames.

### `hDrvFutureFrames`

A pointer to an array of surfaces. The number of elements in the array is the value of *NumFutureFrames* parameter.

### `pFutureSubresources`

An array of subresource indices for the list of future frames textures. A value of null indicates subresource 0 for each resource.