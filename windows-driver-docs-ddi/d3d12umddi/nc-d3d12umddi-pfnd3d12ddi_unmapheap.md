# PFND3D12DDI_UNMAPHEAP callback function

## Description

A client driver implements **PFND3D12DDI_UNMAPHEAP** to unmap a heap.

## Parameters

### `unnamedParam1` [in]

*hDisplayDevice*: Handle to the display device (graphics context).

### `unnamedParam2` [in]

*hHeap*: Handle to a display device-managed heap that needs to be unmapped.

## Prototype

```cpp
//Declaration

PFND3D12DDI_UNMAPHEAP Pfnd3d12ddiUnmapheap;

// Definition

VOID Pfnd3d12ddiUnmapheap
(
    D3D12DDI_HDEVICE hDisplayDevice,
    D3D12DDI_HHEAP hHeap
)
{...}

PFND3D12DDI_UNMAPHEAP

```

## Remarks

## See also

[**PFND3D12DDI_MAPHEAP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_mapheap)