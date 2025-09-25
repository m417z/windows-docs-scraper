# PFND3D12DDI_CALCPRIVATERASTERIZERSTATESIZE_0010 callback function

## Description

Calculate the private rasterizer state size.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDI_RASTERIZER_DESC_0010 structure.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATERASTERIZERSTATESIZE_0010 Pfnd3d12ddiCalcprivaterasterizerstatesize0010;

// Definition

SIZE_T Pfnd3d12ddiCalcprivaterasterizerstatesize0010
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDI_RASTERIZER_DESC_0010 *
)
{...}

PFND3D12DDI_CALCPRIVATERASTERIZERSTATESIZE_0010

```