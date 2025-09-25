# PFND3D12DDI_CREATE_ROOT_SIGNATURE_0001 callback function

## Description

Create a root signature.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_ROOT_SIGNATURE_0001 structure.

### `unnamedParam3`

A handle to a root signature.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_ROOT_SIGNATURE_0001 Pfnd3d12ddiCreateRootSignature0001;

// Definition

HRESULT Pfnd3d12ddiCreateRootSignature0001
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_ROOT_SIGNATURE_0001 *
	 D3D12DDI_HROOTSIGNATURE
)
{...}

PFND3D12DDI_CREATE_ROOT_SIGNATURE_0001

```