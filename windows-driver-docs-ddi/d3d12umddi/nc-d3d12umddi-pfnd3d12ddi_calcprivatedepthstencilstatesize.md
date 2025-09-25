# PFND3D12DDI_CALCPRIVATEDEPTHSTENCILSTATESIZE callback function

## Description

The **CalcPrivateDepthStencilStateSize** function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a depth stencil state.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A pointer to a [D3D12DDI_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_depth_stencil_desc) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

Returns the size of the memory region that the driver requires for creating a depth stencil state.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATEDEPTHSTENCILSTATESIZE Pfnd3d12ddiCalcprivatedepthstencilstatesize;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatedepthstencilstatesize
(
	D3D12DDI_HDEVICE hDevice
	CONST D3D12DDI_DEPTH_STENCIL_DESC *pDepthStencilDesc
)
{...}

```

## See also