# D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_0054 structure

## Description

Contains memory requirements for a ray tracing acceleration structure build.

## Members

### `ResultDataMaxSizeInBytes`

Size required to hold the result of an acceleration structure build based on the specified inputs.

### `ScratchDataSizeInBytes`

Scratch storage on the GPU that is required during acceleration structure build, based on the specified inputs.

### `UpdateScratchDataSizeInBytes`

Scratch storage on the GPU that is required during an acceleration structure update, based on the specified inputs. This only needs to be called for the original acceleration structure build, and defines the scratch storage requirement for every acceleration structure update other than the initial build.

If the D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE flag is not specified in [D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_acceleration_structure_build_flags), this parameter returns 0.

## Remarks

## See also