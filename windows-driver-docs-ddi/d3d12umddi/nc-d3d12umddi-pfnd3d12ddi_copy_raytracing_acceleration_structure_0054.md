# PFND3D12DDI_COPY_RAYTRACING_ACCELERATION_STRUCTURE_0054 callback function

## Description

Copies a ray tracing acceleration structure.

## Parameters

### `unnamedParam1`

A handle to a command list.

### `unnamedParam2`

Pointer to a [D3D12DDIARG_COPY_RAYTRACING_ACCELERATION_STRUCTURE_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_copy_raytracing_acceleration_structure_0054) structure.

## Prototype

```cpp
//Declaration

PFND3D12DDI_COPY_RAYTRACING_ACCELERATION_STRUCTURE_0054 Pfnd3d12ddiCopyRaytracingAccelerationStructure0054;

// Definition

VOID Pfnd3d12ddiCopyRaytracingAccelerationStructure0054
(
	D3D12DDI_HCOMMANDLIST Arg1
	CONST D3D12DDIARG_COPY_RAYTRACING_ACCELERATION_STRUCTURE_0054 *
)
{...}

```

## Remarks

Since ray tracing acceleration structures may contain internal pointers and have a device dependent opaque layout, copying them around or otherwise manipulating them requires a dedicated API so that drivers can handle the requested operation. The CopyRaytracingAccelerationStructure API takes a source acceleration structure and copies it to destination memory while applying the transformation requested by the Mode parameter.

Can be called on graphics or compute command lists but not from bundles.

## See also