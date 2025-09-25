# PFND3D12DDI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_0054 callback function

## Description

Queries the driver for resource requirements to build an acceleration structure.

## Parameters

### `unnamedParam1` [in]

A handle to the device.

### `unnamedParam2` [in]

Pointer to a [D3D12DDI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_build_raytracing_acceleration_structure_inputs_0054) structure that contains the inputs.

### `unnamedParam3` [out]

Pointer to a [D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_raytracing_acceleration_structure_prebuild_info_0054) structure that contains prebuild info.

## Prototype

```cpp
//Declaration

PFND3D12DDI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_0054 Pfnd3d12ddiGetRaytracingAccelerationStructurePrebuildInfo0054;

// Definition

void Pfnd3d12ddiGetRaytracingAccelerationStructurePrebuildInfo0054
(
    D3D12DDI_HDEVICE Arg1
    CONST D3D12DDI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_0054 *
    D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_0054 *
)
{...}

```

## Remarks

The result of this callback function lets the application provide the correct amount of output storage and scratch storage to [BuildRaytracingAccelerationStructure](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-buildraytracingaccelerationstructure) given the same geometry.

This method is on the device as opposed to command list on the assumption that drivers must be able to calculate resource requirements for an acceleration structure build from only looking at the CPU visible portions of the call, without having to dereference any pointers to GPU memory containing actual vertex data, index data, etc.

## See also

[D3D12DDI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_build_raytracing_acceleration_structure_inputs_0054)

[D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_raytracing_acceleration_structure_prebuild_info_0054)