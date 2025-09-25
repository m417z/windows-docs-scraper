# PFND3D12DDI_CALCPRIVATEBLENDSTATESIZE callback function

## Description

Determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a blend state.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A pointer to a D3D12DDI_BLEND_DESC structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

Returns SIZE_T.

## Prototype

```
//Declaration

PFND3D12DDI_CALCPRIVATEBLENDSTATESIZE Pfnd3d12ddiCalcprivateblendstatesize;

// Definition

SIZE_T Pfnd3d12ddiCalcprivateblendstatesize
(
	D3D12DDI_HDEVICE Arg1
	 const D3D12DDI_BLEND_DESC *
)
{...}

```

## Remarks

## See also