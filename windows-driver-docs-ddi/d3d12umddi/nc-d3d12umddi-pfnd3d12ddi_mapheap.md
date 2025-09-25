# PFND3D12DDI_MAPHEAP callback function

## Description

A client driver implements **PFND3D12DDI_MAPHEAP** to map a heap.

## Parameters

### `unnamedParam1` [in]

*hDisplayDevice*: Handle to the display device (graphics context).

### `unnamedParam2` [in]

*hHeap*: Handle to a display device-managed heap that needs to be mapped.

### `unnamedParam3` [out]

*ppData**: A pointer to the mapped heap data.

## Return value

**PFND3D12DDI_MAPHEAP** returns S_OK on success. It should return an appropriate HRESULT error code on failure.

## Prototype

```cpp
//Declaration

PFND3D12DDI_MAPHEAP Pfnd3d12ddiMapheap;

// Definition

HRESULT Pfnd3d12ddiMapheap
(
    D3D12DDI_HDEVICE hDisplayDevice,
    D3D12DDI_HHEAP hHeap,
    VOID **ppData
)
{...}

PFND3D12DDI_MAPHEAP

```

## Remarks

Heap data is typically accessible to the GPU only. **PFND3D12DDI_MAPHEAP** makes the heap data accessible to the CPU. The driver should map the heap data and return a CPU-accessible pointer in *ppData*.

## See also

[**PFND3D12DDI_UNMAPHEAP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_unmapheap)