# PFND3D12DDI_CALCPRIVATEBLENDSTATESIZE_0010 callback function

## Description

The CalcPrivateBlendStateSize function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a blend state.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A pointer to a D3D12DDI_BLEND_DESC_0010 structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATEBLENDSTATESIZE_0010 Pfnd3d12ddiCalcprivateblendstatesize0010;

// Definition

SIZE_T Pfnd3d12ddiCalcprivateblendstatesize0010
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDI_BLEND_DESC_0010 *
)
{...}

PFND3D12DDI_CALCPRIVATEBLENDSTATESIZE_0010

```

## Remarks

## See also