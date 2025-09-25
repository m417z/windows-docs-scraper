# PFND3D12DDI_QUERY_NODE_MAP callback function

## Description

Query node map.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `NumPhysicalAdapters`

The number of physical adapters.

### `pMap`

Pointer to a map.

## Prototype

```cpp
//Declaration

PFND3D12DDI_QUERY_NODE_MAP Pfnd3d12ddiQueryNodeMap;

// Definition

VOID Pfnd3d12ddiQueryNodeMap
(
	 D3D12DDI_HDEVICE
	UINT NumPhysicalAdapters
	UINT *pMap
)
{...}

PFND3D12DDI_QUERY_NODE_MAP

```

## Remarks

## See also