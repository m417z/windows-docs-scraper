# PFND3D12DDI_CALCPRIVATEOPENEDHEAPANDRESOURCESIZES_0043 callback function

## Description

Pointer to a CalcPrivateOpenedHeapAndResourceSizes function that calculates sizes for private opened heap and resources.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Open heap and resource.

### `unnamedParam3`

The protected resource session.

## Return value

Returns D3D12DDI_HEAP_AND_RESOURCE_SIZES that contains the sizes for private opened heap and resources.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATEOPENEDHEAPANDRESOURCESIZES_0043 Pfnd3d12ddiCalcprivateopenedheapandresourcesizes0043;

// Definition

D3D12DDI_HEAP_AND_RESOURCE_SIZES Pfnd3d12ddiCalcprivateopenedheapandresourcesizes0043
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_OPENHEAP_0003 *
	 D3D12DDI_HPROTECTEDRESOURCESESSION_0030
)
{...}

PFND3D12DDI_CALCPRIVATEOPENEDHEAPANDRESOURCESIZES_0043

```

## Remarks

## See also