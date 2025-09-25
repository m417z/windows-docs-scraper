# PFND3D12DDI_CALC_PRIVATE_ROOT_SIGNATURE_SIZE_0001 callback function

## Description

Calculates the driver's root signature size.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Used to create a root signature.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_PRIVATE_ROOT_SIGNATURE_SIZE_0001 Pfnd3d12ddiCalcPrivateRootSignatureSize0001;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateRootSignatureSize0001
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_ROOT_SIGNATURE_0001 *
)
{...}

PFND3D12DDI_CALC_PRIVATE_ROOT_SIGNATURE_SIZE_0001

```