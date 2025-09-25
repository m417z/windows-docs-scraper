# PFND3D12DDI_CHECKRESOURCEVIRTUALADDRESS callback function

## Description

Check resource virtual address.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

## Return value

Returns D3D12DDI_GPU_VIRTUAL_ADDRESS.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CHECKRESOURCEVIRTUALADDRESS Pfnd3d12ddiCheckresourcevirtualaddress;

// Definition

D3D12DDI_GPU_VIRTUAL_ADDRESS Pfnd3d12ddiCheckresourcevirtualaddress
(
	 D3D12DDI_HDEVICE
	 D3D12DDI_HRESOURCE
)
{...}

PFND3D12DDI_CHECKRESOURCEVIRTUALADDRESS

```

## Remarks

## See also