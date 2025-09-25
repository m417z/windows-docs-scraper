# ID3D12GraphicsCommandList4::BuildRaytracingAccelerationStructure

## Description

Performs a raytracing acceleration structure build on the GPU and optionally outputs post-build information immediately after the build.

## Parameters

### `pDesc` [in]

Description of the acceleration structure to build.

### `NumPostbuildInfoDescs` [in]

Size of the *pPostbuildInfoDescs* array. Set to 0 if no post-build info is needed.

### `pPostbuildInfoDescs` [in]

Optional array of descriptions for post-build info to generate describing properties of the acceleration structure that was built.

## Remarks

This method can be called on graphics or compute command lists but not from bundles.

Post-build information can also be obtained separately from an already built acceleration structure by calling [EmitRaytracingAccelerationStructurePostbuildInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-emitraytracingaccelerationstructurepostbuildinfo). The advantage of generating post-build info along with a build is that a barrier isn’t needed in between the build completing and requesting post-build information, enabling scenarios where the app needs the post-build info right away.

## See also

[ID3D12GraphicsCommandList4](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist4)