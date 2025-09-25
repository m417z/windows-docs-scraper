# PFND3D12DDI_CALCPRIVATESCHEDULINGGROUPSIZE_0050 callback function

## Description

The **pfnCalcPrivateSchedulingGroupSize** callback function returns the size of the hardware scheduling group.

## Parameters

### `unnamedParam1`

An hDevice that represents a handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a [D3D12DDIARG_CREATESCHEDULINGGROUP_0050](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createschedulinggroup_0050) structure that represents arguments needed to create a hardware scheduling group.

## Return value

Returns SIZE_T that represents the size.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATESCHEDULINGGROUPSIZE_0050 Pfnd3d12ddiCalcprivateschedulinggroupsize0050;

// Definition

SIZE_T Pfnd3d12ddiCalcprivateschedulinggroupsize0050
(
	D3D12DDI_HDEVICE Arg1
	CONST D3D12DDIARG_CREATESCHEDULINGGROUP_0050 *
)
{...}

```

## Remarks

## See also