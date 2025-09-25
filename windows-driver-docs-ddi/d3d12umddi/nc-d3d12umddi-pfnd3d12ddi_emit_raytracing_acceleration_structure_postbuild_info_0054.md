# PFND3D12DDI_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_0054 callback function

## Description

Emits post-build properties for a set of acceleration structures.

## Parameters

### `unnamedParam1`

A handle to the command list.

### `unnamedParam2`

Pointer to a [D3D12DDIARG_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_emit_raytracing_acceleration_structure_postbuild_info_0054) structure.

## Prototype

```cpp
//Declaration

PFND3D12DDI_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_0054 Pfnd3d12ddiEmitRaytracingAccelerationStructurePostbuildInfo0054;

// Definition

VOID Pfnd3d12ddiEmitRaytracingAccelerationStructurePostbuildInfo0054
(
	D3D12DDI_HCOMMANDLIST Arg1
	CONST D3D12DDIARG_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_0054 *
)
{...}

```

## Remarks

Can be called on graphics or compute command lists but not from bundles.

## See also