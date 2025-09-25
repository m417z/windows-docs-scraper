# PFND3D12DDI_CALCPRIVATEDEVICESIZE callback function

## Description

The CalcPrivateDeviceSize function determines the size of a memory region that the user-mode display driver requires from the Microsoft Direct3D runtime to store frequently-accessed data.

## Parameters

### `unnamedParam1`

A handle that identifies the graphics adapter.

### `unnamedParam2`

A pointer to a D3D12DDIARG_CALCPRIVATEDEVICESIZE structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

Returns the size of the memory region that the driver requires to store frequently-accessed data.

## Prototype

```
//Declaration

PFND3D12DDI_CALCPRIVATEDEVICESIZE Pfnd3d12ddiCalcprivatedevicesize;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatedevicesize
(
	D3D12DDI_HADAPTER Arg1
	 const D3D12DDIARG_CALCPRIVATEDEVICESIZE *
)
{...}

```

## Remarks

## See also