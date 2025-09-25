# PFND3D12DDI_CALC_PRIVATE_COMMAND_SIGNATURE_SIZE_0001 callback function

## Description

Calculates the command signature size.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_COMMAND_SIGNATURE_0001 structure that contains the arguments to calculate a command signature size.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_PRIVATE_COMMAND_SIGNATURE_SIZE_0001 Pfnd3d12ddiCalcPrivateCommandSignatureSize0001;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateCommandSignatureSize0001
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_COMMAND_SIGNATURE_0001 *
)
{...}

PFND3D12DDI_CALC_PRIVATE_COMMAND_SIGNATURE_SIZE_0001

```

## Remarks

## See also