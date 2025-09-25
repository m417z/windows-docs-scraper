# PFND3D12DDI_EVICT2 callback function

## Description

PFND3D12DDI_EVICT2 instructs the OS to decrement the residency reference count. Once this count reaches zero, it will remove the allocation from the device residency list.

## Parameters

### `unnamedParam1`

A handle to the display device.

### `unnamedParam2`

A pointer to a [D3D12DDIARG_EVICT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_evict) structure that describes the memory pages to evict.

## Return value

If this callback function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## Prototype

```cpp
//Declaration

PFND3D12DDI_EVICT2 Pfnd3d12ddiEvict2;

// Definition

HRESULT Pfnd3d12ddiEvict2
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_EVICT *
)
{...}

PFND3D12DDI_EVICT2

```

## Remarks

Once the eviction request is queued, it is illegal to access the underlying allocation as the allocation may be evicted at anytime from there on at the operating system discretion.

## See also