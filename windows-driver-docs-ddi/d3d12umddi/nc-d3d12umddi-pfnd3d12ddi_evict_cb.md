# PFND3D12DDI_EVICT_CB callback function

## Description

PFND3D12DDI_EVICT_CB instructs the OS to decrement the residency reference count. Once this count reaches zero, it will remove the allocation from the device residency list.

## Parameters

### `hRTDevice`

A handle to the display device.

### `unnamedParam2`

A pointer to a [D3DDDICB_EVICT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_evict) structure that describes the memory pages to evict.

## Return value

If this callback function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## Prototype

```cpp
//Declaration

PFND3D12DDI_EVICT_CB Pfnd3d12ddiEvictCb;

// Definition

HRESULT Pfnd3d12ddiEvictCb
(
	D3D12DDI_HRTDEVICE hRTDevice
	 const D3DDDICB_EVICT *
)
{...}

```

## Remarks

Once the eviction request is queued, it is illegal to access the underlying allocation as the allocation may be evicted at anytime from there on at the operating system discretion.

## See also