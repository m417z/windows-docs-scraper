# PFND3D12DDI_CALCPRIVATECOMMANDALLOCATORSIZE callback function

## Description

Calculates private command allocator size.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATECOMMANDALLOCATOR structure.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATECOMMANDALLOCATORSIZE Pfnd3d12ddiCalcprivatecommandallocatorsize;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatecommandallocatorsize
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATECOMMANDALLOCATOR *
)
{...}

PFND3D12DDI_CALCPRIVATECOMMANDALLOCATORSIZE

```

## Remarks

## See also