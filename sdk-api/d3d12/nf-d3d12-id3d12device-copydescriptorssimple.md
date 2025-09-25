# ID3D12Device::CopyDescriptorsSimple

## Description

Copies descriptors from a source to a destination.

## Parameters

### `NumDescriptors` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of descriptors to copy.

### `DestDescriptorRangeStart` [in]

Type: **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)**

A **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)** that describes the destination descriptors to start to copy to.

The destination and source descriptors must be in heaps of the same [D3D12_DESCRIPTOR_HEAP_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_descriptor_heap_type).

### `SrcDescriptorRangeStart` [in]

Type: **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)**

A **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)** that describes the source descriptors to start to copy from.

> [!IMPORTANT]
> The *SrcDescriptorRangeStart* parameter must be in a non shader-visible descriptor heap. This is because shader-visible descriptor heaps may be created in **WRITE_COMBINE** memory or GPU local memory, which is prohibitively slow to read from. If your application manages descriptor heaps via copying the descriptors required for a given pass or frame from local "storage" descriptor heaps to the GPU-bound descriptor heap, then use shader-opaque heaps for the storage heaps and copy into the GPU-visible heap as required.

### `DescriptorHeapsType` [in]

Type: **[D3D12_DESCRIPTOR_HEAP_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_heap_type)**

The [D3D12_DESCRIPTOR_HEAP_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_heap_type)-typed value that specifies the type of descriptor heap to copy with. This is required as different descriptor types may have different sizes.

Both the source and destination descriptor heaps must have the same type, else the debug layer will emit an error.

## Remarks

Where applicable, prefer this method to [**ID3D12Device::CopyDescriptors**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-copydescriptors). It can have a better CPU cache miss rate due to the linear nature of the copy.

## See also

[Copying Descriptors](https://learn.microsoft.com/windows/desktop/direct3d12/copying-descriptors)

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)