# PFND3D12DDI_CREATESCHEDULINGGROUP_0050 callback function

## Description

Creates a scheduling group.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a [D3D12DDIARG_CREATESCHEDULINGGROUP_0050](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createschedulinggroup_0050) structure that contains arguments to create a scheduling group.

### `unnamedParam3`

A D3D12DDI_HRTSCHEDULINGGROUP_0050 runtime handle type that represents the contexts associated with a hardware scheduling group.

### `unnamedParam4`

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATESCHEDULINGGROUP_0050 Pfnd3d12ddiCreateschedulinggroup0050;

// Definition

HRESULT Pfnd3d12ddiCreateschedulinggroup0050
(
	D3D12DDI_HDEVICE Arg1
	CONST D3D12DDIARG_CREATESCHEDULINGGROUP_0050 *
	D3D12DDI_HSCHEDULINGGROUP_0050 Arg2
	D3D12DDI_HRTSCHEDULINGGROUP_0050 Arg3
)
{...}

```

## Remarks

A scheduling group is a driver object that the runtime will create, and which must have at least one 3D/compute context created during its construction. The runtime will allow multiple contexts to be constructed. Once the driver returns from CreateSchedulingGroup, no more contexts may be added.

The scheduling group should contain all contexts which target shared hardware or resources that will be leveraged by any child command queues. It does not need to contain all contexts for all child queues.

## See also