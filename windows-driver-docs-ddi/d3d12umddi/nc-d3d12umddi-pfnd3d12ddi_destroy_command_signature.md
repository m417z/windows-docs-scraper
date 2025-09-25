# PFND3D12DDI_DESTROY_COMMAND_SIGNATURE callback function

## Description

Destroys a command signature.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A command signature handle.

## Prototype

```cpp
//Declaration

PFND3D12DDI_DESTROY_COMMAND_SIGNATURE Pfnd3d12ddiDestroyCommandSignature;

// Definition

VOID Pfnd3d12ddiDestroyCommandSignature
(
	 D3D12DDI_HDEVICE
	 D3D12DDI_HCOMMANDSIGNATURE
)
{...}

PFND3D12DDI_DESTROY_COMMAND_SIGNATURE

```