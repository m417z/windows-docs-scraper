# PFND3D12DDI_CALC_PRIVATE_QUERY_HEAP_SIZE_0001 callback function

## Description

Determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a query.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Used to create a query heap.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_PRIVATE_QUERY_HEAP_SIZE_0001 Pfnd3d12ddiCalcPrivateQueryHeapSize0001;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateQueryHeapSize0001
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_QUERY_HEAP_0001 *
)
{...}

PFND3D12DDI_CALC_PRIVATE_QUERY_HEAP_SIZE_0001

```