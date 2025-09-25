# PFND3D12DDI_CALCPRIVATERASTERIZERSTATESIZE callback function

## Description

The CalcPrivateRasterizerStateSize function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a rasterizer state.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDI_RASTERIZER_DESC structure.

## Return value

Returns SIZE_T.

## Prototype

```
//Declaration

PFND3D12DDI_CALCPRIVATERASTERIZERSTATESIZE Pfnd3d12ddiCalcprivaterasterizerstatesize;

// Definition

SIZE_T Pfnd3d12ddiCalcprivaterasterizerstatesize
(
	D3D12DDI_HDEVICE Arg1
	 const D3D12DDI_RASTERIZER_DESC *
)
{...}

```

## Remarks

## See also