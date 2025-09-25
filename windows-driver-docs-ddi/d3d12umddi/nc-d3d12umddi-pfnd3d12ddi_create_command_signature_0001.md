# PFND3D12DDI_CREATE_COMMAND_SIGNATURE_0001 callback function

## Description

Create a command signature.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_COMMAND_SIGNATURE_0001 structure.

### `unnamedParam3`

A handle to a command signature.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_COMMAND_SIGNATURE_0001 Pfnd3d12ddiCreateCommandSignature0001;

// Definition

HRESULT Pfnd3d12ddiCreateCommandSignature0001
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_COMMAND_SIGNATURE_0001 *
	 D3D12DDI_HCOMMANDSIGNATURE
)
{...}

PFND3D12DDI_CREATE_COMMAND_SIGNATURE_0001

```