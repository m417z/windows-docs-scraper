# PFND3D12DDI_CALC_PRIVATE_PASS_SIZE callback function

## Description

Used in the creation of a pass.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A pointer to the D3D12DDIARG_CREATE_PASS structure that contains arguments used to create a pass.

## Return value

Returns SIZE_T.

## Prototype

```
//Declaration

PFND3D12DDI_CALC_PRIVATE_PASS_SIZE Pfnd3d12ddiCalcPrivatePassSize;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivatePassSize
(
	D3D12DDI_HDEVICE Arg1
	 const D3D12DDIARG_CREATE_PASS *
)
{...}

```

## Remarks

This callback is used as part of a test to see if drivers can find perf wins from being told when apps are repeating "passes" of consistent workloads. The app instructs the driver to observe how some passes run and gives the driver a chance to make optimizations for future runs of the same pass. The contents of a "pass" can be anything - it is up to the app to be relatively consistent in the overall performance characteristics of a pass.

## See also