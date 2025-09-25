# D3D12_DESCRIPTOR_HEAP_TYPE enumeration

## Description

Specifies a type of descriptor heap.

## Constants

### `D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV:0`

The descriptor heap for the combination of constant-buffer, shader-resource, and unordered-access views.

### `D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER`

The descriptor heap for the sampler.

### `D3D12_DESCRIPTOR_HEAP_TYPE_RTV`

The descriptor heap for the render-target view.

### `D3D12_DESCRIPTOR_HEAP_TYPE_DSV`

The descriptor heap for the depth-stencil view.

### `D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES`

The number of types of descriptor heaps.

## Remarks

This enum is used by the [D3D12_DESCRIPTOR_HEAP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_heap_desc) structure, and the following methods:

* [CopyDescriptors](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-copydescriptors)
* [CopyDescriptorsSimple](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-copydescriptorssimple)
* [GetDescriptorHandleIncrementSize](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getdescriptorhandleincrementsize)

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)

[Creating Descriptor Heaps](https://learn.microsoft.com/windows/desktop/direct3d12/creating-descriptor-heaps)

[Descriptor Heaps](https://learn.microsoft.com/windows/desktop/direct3d12/descriptor-heaps)