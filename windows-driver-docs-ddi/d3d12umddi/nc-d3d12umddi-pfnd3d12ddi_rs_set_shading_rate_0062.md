# PFND3D12DDI_RS_SET_SHADING_RATE_0062 callback function

## Description

Sets the command-level shading rate and combiners.

## Parameters

### `unnamedParam1`

A handle to the command list.

### `ShadingRate`

A [D3D12DDI_SHADING_RATE_0062](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_shading_rate_0062) enum that indicates the shading rate.

### `Combiners`

Pointer to a [D3D12DDI_SHADING_RATE_COMBINER_0062](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_shading_rate_combiner_0062) enum that indicates the combined shading rate.

## Prototype

```
//Declaration

PFND3D12DDI_RS_SET_SHADING_RATE_0062 Pfnd3d12ddiRsSetShadingRate0062;

// Definition

VOID Pfnd3d12ddiRsSetShadingRate0062
(
	D3D12DDI_HCOMMANDLIST Arg1
	D3D12DDI_SHADING_RATE_0062 ShadingRate
	const D3D12DDI_SHADING_RATE_COMBINER_0062 *Combiners
)
{...}

```

## Remarks

The shading rate, and optionally, combiners, are specified through a command list method.

## See also