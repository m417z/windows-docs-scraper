# PFND3D12DDI_CALC_PRIVATE_COMMAND_LIST_SIZE_0001 callback function

## Description

The CalcPrivateCommandListSize function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a command list.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A pointer to a D3D11DDIARG_CREATECOMMANDLIST structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_PRIVATE_COMMAND_LIST_SIZE_0001 Pfnd3d12ddiCalcPrivateCommandListSize0001;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateCommandListSize0001
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_COMMAND_LIST_0001 *
)
{...}

PFND3D12DDI_CALC_PRIVATE_COMMAND_LIST_SIZE_0001

```

## See also