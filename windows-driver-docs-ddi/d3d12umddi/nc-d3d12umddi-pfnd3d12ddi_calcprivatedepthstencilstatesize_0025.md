# PFND3D12DDI_CALCPRIVATEDEPTHSTENCILSTATESIZE_0025 callback function

## Description

The **CalcPrivateDepthStencilStateSize** function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a depth stencil state.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A pointer to a [D3D12DDI_DEPTH_STENCIL_DESC_0025](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_depth_stencil_desc_0025) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

Returns the size of the memory region that the driver requires for creating a depth stencil state.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATEDEPTHSTENCILSTATESIZE_0025 Pfnd3d12ddiCalcprivatedepthstencilstatesize0025;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatedepthstencilstatesize0025
(
	D3D12DDI_HDEVICE hDevice
	CONST D3D12DDI_DEPTH_STENCIL_DESC_0025 *pDepthStencilDesc
)
{...}

```

## See also