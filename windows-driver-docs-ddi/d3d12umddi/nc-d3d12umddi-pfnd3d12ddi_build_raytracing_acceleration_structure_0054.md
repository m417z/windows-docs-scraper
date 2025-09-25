# PFND3D12DDI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_0054 callback function

## Description

BuildRaytracingAccelerationStructure performs a ray tracing acceleration structure build on the GPU.

## Parameters

### `unnamedParam1`

A handle to the command list.

### `unnamedParam2`

*_In_* [D3D12DDIARG_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_build_raytracing_acceleration_structure_0054)

Description of the acceleration structure to build.

## Prototype

```cpp
//Declaration

PFND3D12DDI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_0054 Pfnd3d12ddiBuildRaytracingAccelerationStructure0054;

// Definition

VOID Pfnd3d12ddiBuildRaytracingAccelerationStructure0054
(
	D3D12DDI_HCOMMANDLIST Arg1
	CONST D3D12DDIARG_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_0054 *
)
{...}

```

## Remarks

Can be called on graphics or compute command lists but not from bundles.

## See also