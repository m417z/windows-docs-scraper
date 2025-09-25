# PFND3D12DDI_CALCPRIVATEFENCESIZE callback function

## Description

Calculate private fence size.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_FENCE structure.

## Return value

Returns SIZE_T that.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATEFENCESIZE Pfnd3d12ddiCalcprivatefencesize;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatefencesize
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_FENCE *
)
{...}

PFND3D12DDI_CALCPRIVATEFENCESIZE

```