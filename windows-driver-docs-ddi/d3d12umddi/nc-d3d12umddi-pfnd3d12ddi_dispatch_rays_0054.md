# PFND3D12DDI_DISPATCH_RAYS_0054 callback function

## Description

Launch threads of a ray generation shader.

## Parameters

### `unnamedParam1`

A handle to the command list.

### `unnamedParam2`

Pointer to the [D3D12DDIARG_DISPATCH_RAYS_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_dispatch_rays_0054) structure.

## Prototype

```cpp
//Declaration

PFND3D12DDI_DISPATCH_RAYS_0054 Pfnd3d12ddiDispatchRays0054;

// Definition

VOID Pfnd3d12ddiDispatchRays0054
(
	D3D12DDI_HCOMMANDLIST Arg1
	CONST D3D12DDIARG_DISPATCH_RAYS_0054 *
)
{...}

```

## Remarks

This callback can be called from graphics or compute command lists and bundles.

PFND3D12DDI_DISPATCH_RAYS_0054 invokes a grid of ray generation shader invocations. Each invocation (thread) of a ray generation shader knows its location in the overall grid, can generate arbitrary rays via [PFND3D12DDI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_build_raytracing_acceleration_structure_0054), and operates independently of other invocations. So there is no defined order of execution of threads with respect to each other.

## See also