# PFND3D12DDI_CALC_PRIVATE_COMMAND_LIST_SIZE_0040 callback function

## Description

The CalcPrivateCommandListSize function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a command list.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_COMMAND_LIST_0040 structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

Returns the size of the memory region that the driver requires to create a command list.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_PRIVATE_COMMAND_LIST_SIZE_0040 Pfnd3d12ddiCalcPrivateCommandListSize0040;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateCommandListSize0040
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_COMMAND_LIST_0040 *
)
{...}

PFND3D12DDI_CALC_PRIVATE_COMMAND_LIST_SIZE_0040

```

## Remarks

The driver is only required to implement CalcPrivateCommandListSize if the driver supports the D3D11DDICAPS_COMMANDLISTS_BUILD_2 capability that can be returned in the D3D11DDI_THREADING_CAPS structure from a call to the GetCaps(D3D10_2) function.

## See also