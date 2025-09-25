# PFND3D12DDI_OPENHEAPANDRESOURCE_0003 callback function

## Description

Implemented by the client driver to open heap and resource.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_OPENHEAP_0003 structure.

### `unnamedParam3`

A heap handle.

### `unnamedParam4`

The handle of the resource for the driver to use when it calls back into the runtime.

### `unnamedParam5`

A resource handle.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_OPENHEAPANDRESOURCE_0003 Pfnd3d12ddiOpenheapandresource0003;

// Definition

HRESULT Pfnd3d12ddiOpenheapandresource0003
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_OPENHEAP_0003 *
	 D3D12DDI_HHEAP
	 D3D12DDI_HRTRESOURCE
	 D3D12DDI_HRESOURCE
)
{...}

PFND3D12DDI_OPENHEAPANDRESOURCE_0003

```

## Remarks

## See also