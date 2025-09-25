# PFND3D12DDI_CALC_PRIVATE_ROOT_SIGNATURE_SIZE_0013 callback function

## Description

Calculates the driver's root signature size.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_ROOT_SIGNATURE_0013 structure.

## Return value

Returns SIZE_T.

## Prototype

```
//Declaration

PFND3D12DDI_CALC_PRIVATE_ROOT_SIGNATURE_SIZE_0013 Pfnd3d12ddiCalcPrivateRootSignatureSize0013;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateRootSignatureSize0013
(
	D3D12DDI_HDEVICE Arg1
	 const D3D12DDIARG_CREATE_ROOT_SIGNATURE_0013 *
)
{...}

```

## Remarks

## See also