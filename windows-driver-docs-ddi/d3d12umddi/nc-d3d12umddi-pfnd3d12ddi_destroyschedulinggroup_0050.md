# PFND3D12DDI_DESTROYSCHEDULINGGROUP_0050 callback function

## Description

Destroys a hardware scheduling group.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A D3D12DDI_HSCHEDULINGGROUP_0050 user mode driver handle type that represents a hardware scheduling group.

## Prototype

```cpp
//Declaration

PFND3D12DDI_DESTROYSCHEDULINGGROUP_0050 Pfnd3d12ddiDestroyschedulinggroup0050;

// Definition

VOID Pfnd3d12ddiDestroyschedulinggroup0050
(
	D3D12DDI_HDEVICE Arg1
	D3D12DDI_HSCHEDULINGGROUP_0050 Arg2
)
{...}

```

## Remarks

## See also