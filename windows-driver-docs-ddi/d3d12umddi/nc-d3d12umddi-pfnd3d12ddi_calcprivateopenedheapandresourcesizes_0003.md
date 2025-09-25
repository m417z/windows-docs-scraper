# PFND3D12DDI_CALCPRIVATEOPENEDHEAPANDRESOURCESIZES_0003 callback function

## Description

Calculates sizes for private opened heap and resources.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_OPENHEAP_0003.

## Return value

Returns D3D12DDI_HEAP_AND_RESOURCE_SIZES.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATEOPENEDHEAPANDRESOURCESIZES_0003 Pfnd3d12ddiCalcprivateopenedheapandresourcesizes0003;

// Definition

D3D12DDI_HEAP_AND_RESOURCE_SIZES Pfnd3d12ddiCalcprivateopenedheapandresourcesizes0003
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_OPENHEAP_0003 *
)
{...}

PFND3D12DDI_CALCPRIVATEOPENEDHEAPANDRESOURCESIZES_0003

```