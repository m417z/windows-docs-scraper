## Description

Copies descriptors from a source to a destination.

## Parameters

### `NumDestDescriptorRanges` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of destination descriptor ranges to copy to.

### `pDestDescriptorRangeStarts` [in]

Type: **const [D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)***

An array of **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)** objects to copy to.

All the destination and source descriptors must be in heaps of the same [D3D12_DESCRIPTOR_HEAP_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_descriptor_heap_type).

### `pDestDescriptorRangeSizes` [in, optional]

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

An array of destination descriptor range sizes to copy to.

### `NumSrcDescriptorRanges` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of source descriptor ranges to copy from.

### `pSrcDescriptorRangeStarts` [in]

Type: **const [D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)***

An array of **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)** objects to copy from.

> [!IMPORTANT]
> All elements in the *pSrcDescriptorRangeStarts* parameter must be in a non shader-visible descriptor heap. This is because shader-visible descriptor heaps may be created in **WRITE_COMBINE** memory or GPU local memory, which is prohibitively slow to read from. If your application manages descriptor heaps via copying the descriptors required for a given pass or frame from local "storage" descriptor heaps to the GPU-bound descriptor heap, use shader-opaque heaps for the storage heaps and copy into the GPU-visible heap as required.

### `pSrcDescriptorRangeSizes` [in, optional]

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

An array of source descriptor range sizes to copy from.

### `DescriptorHeapsType` [in]

Type: **[D3D12_DESCRIPTOR_HEAP_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_heap_type)**

The [D3D12_DESCRIPTOR_HEAP_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_heap_type)-typed value that specifies the type of descriptor heap to copy with. This is required as different descriptor types may have different sizes.

Both the source and destination descriptor heaps must have the same type, else the debug layer will emit an error.

## Remarks

Where applicable, prefer [**ID3D12Device::CopyDescriptorsSimple**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-copydescriptorssimple) to this method. It can have a better CPU cache miss rate due to the linear nature of the copy.

## See also

[Copying Descriptors](https://learn.microsoft.com/windows/desktop/direct3d12/copying-descriptors)

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)