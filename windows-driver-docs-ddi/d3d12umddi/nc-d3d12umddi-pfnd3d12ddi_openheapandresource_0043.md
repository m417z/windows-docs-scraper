# PFND3D12DDI_OPENHEAPANDRESOURCE_0043 callback function

## Description

Implemented by the client driver to open heap and resource.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Open heap and resource.

### `unnamedParam3`

Used to create a heap.

### `unnamedParam4`

Used to create a resource.

### `unnamedParam5`

The protected resource session.

### `unnamedParam6`

The hardware resource.

## Return value

Returns STATUS_SUCCESS if completed successfully.

## Prototype

```cpp
//Declaration

PFND3D12DDI_OPENHEAPANDRESOURCE_0043 Pfnd3d12ddiOpenheapandresource0043;

// Definition

HRESULT Pfnd3d12ddiOpenheapandresource0043
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_OPENHEAP_0003 *
	 D3D12DDI_HHEAP
	 D3D12DDI_HRTRESOURCE
	 D3D12DDI_HPROTECTEDRESOURCESESSION_0030
	 D3D12DDI_HRESOURCE
)
{...}

PFND3D12DDI_OPENHEAPANDRESOURCE_0043

```

## See also