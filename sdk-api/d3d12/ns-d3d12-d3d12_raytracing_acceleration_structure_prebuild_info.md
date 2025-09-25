# D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO structure

## Description

Represents prebuild information about a raytracing acceleration structure. Get an instance of this structure by calling [GetRaytracingAccelerationStructurePrebuildInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device5-getraytracingaccelerationstructureprebuildinfo).

## Members

### `ResultDataMaxSizeInBytes`

Size required to hold the result of an acceleration structure build based on the specified inputs.

### `ScratchDataSizeInBytes`

Scratch storage on the GPU required during acceleration structure build based on the specified inputs.

#### UpdateScratchDataSizeInBytes

Scratch storage on GPU required during an acceleration structure update based on the specified inputs. This only needs to be called for the original acceleration structure build, and defines the scratch storage requirement for every acceleration structure update, other than the initial build.

If the [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_acceleration_structure_build_flags) flag is not specified when calling [GetRaytracingAccelerationStructurePrebuildInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device5-getraytracingaccelerationstructureprebuildinfo), the returned value of this field is 0.

### `UpdateScratchDataSizeInBytes`