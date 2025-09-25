# ID3D12GraphicsCommandList4::DispatchRays

## Description

Launch the threads of a ray generation shader.

## Parameters

### `pDesc` [in]

A description of the ray dispatch

## Remarks

This method can be called from graphics or compute command lists and bundles.

A raytracing pipeline state must be set on the command list. Otherwise, the behavior of this call is undefined.

There are 3 dimensions passed in to set the grid size: width/height/depth. These dimensions are constrained such that width * height * depth <= 2^30. Exceeding this produces undefined behavior.
If any grid dimension is 0, no threads are launched.

## See also

[ID3D12GraphicsCommandList4](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist4)