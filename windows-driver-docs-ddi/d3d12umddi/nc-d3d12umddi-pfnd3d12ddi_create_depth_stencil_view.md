# PFND3D12DDI_CREATE_DEPTH_STENCIL_VIEW callback function

## Description

The PFND3D12DDI_CREATE_DEPTH_STENCIL_VIEW callback function creates a depth stencil view.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A pointer to a [D3D12DDIARG_CREATE_DEPTH_STENCIL_VIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_depth_stencil_view) structure that describes the parameters that the display driver uses to create a depth stencil view.

### `DestDescriptor`

A pointer to [D3D12DDI_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_cpu_descriptor_handle) structure that describes the depth buffer bindings.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_DEPTH_STENCIL_VIEW Pfnd3d12ddiCreateDepthStencilView;

// Definition

VOID Pfnd3d12ddiCreateDepthStencilView
(
	D3D12DDI_HDEVICE hDevice
	CONST D3D12DDIARG_CREATE_DEPTH_STENCIL_VIEW *pCreateDepthStencilView
	D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptor
)
{...}

```

## Remarks

## See also