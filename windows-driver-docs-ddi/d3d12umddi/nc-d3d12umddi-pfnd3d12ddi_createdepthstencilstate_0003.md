# PFND3D12DDI_CREATEDEPTHSTENCILSTATE_0003 callback function

## Description

The PFND3D12DDI_CREATEDEPTHSTENCILSTATE_0003 callback function creates a depth stencil state.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A pointer to a [D3D12DDI_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_depth_stencil_desc) structure that describes the parameters that the user-mode display driver uses to create a depth stencil state.

### `unnamedParam3`

A handle to the driver's private data for the depth stencil state. The driver returns the size, in bytes, of the memory region that the Microsoft Direct3D runtime must allocate for the private data from a call to the driver's [CalcPrivateDepthStencilStateSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatedepthstencilstatesize) function. The handle is really just a pointer to a region of memory, the size of which the driver requested. The driver uses this region of memory to store internal data structures that are related to its depth stencil state object.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATEDEPTHSTENCILSTATE_0003 Pfnd3d12ddiCreatedepthstencilstate0003;

// Definition

VOID Pfnd3d12ddiCreatedepthstencilstate0003
(
	D3D12DDI_HDEVICE hDevice
	CONST D3D12DDI_DEPTH_STENCIL_DESC *pDepthStencilDesc
	D3D12DDI_HDEPTHSTENCILSTATE hDepthStencilState
)
{...}

```

## See also