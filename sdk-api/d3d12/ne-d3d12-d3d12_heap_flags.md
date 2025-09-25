## Description

Specifies heap options, such as whether the heap can contain textures, and whether resources are shared across adapters.

## Constants

### `D3D12_HEAP_FLAG_NONE:0`

No options are specified.

### `D3D12_HEAP_FLAG_SHARED:0x1`

The heap is shared. Refer to [Shared Heaps](https://learn.microsoft.com/windows/desktop/direct3d12/shared-heaps).

### `D3D12_HEAP_FLAG_DENY_BUFFERS:0x4`

The heap isn't allowed to contain buffers.

### `D3D12_HEAP_FLAG_ALLOW_DISPLAY:0x8`

The heap is allowed to contain swap-chain surfaces.

### `D3D12_HEAP_FLAG_SHARED_CROSS_ADAPTER:0x20`

The heap is allowed to share resources across adapters. Refer to [Shared Heaps](https://learn.microsoft.com/windows/desktop/direct3d12/shared-heaps). A protected session cannot be mixed with resources that are shared across adapters.

### `D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES:0x40`

The heap is not allowed to store Render Target (RT) and/or Depth-Stencil (DS) textures.

### `D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES:0x80`

The heap is not allowed to contain resources with D3D12_RESOURCE_DIMENSION_TEXTURE1D, D3D12_RESOURCE_DIMENSION_TEXTURE2D, or D3D12_RESOURCE_DIMENSION_TEXTURE3D unless either D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET or D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL are present. Refer to [D3D12_RESOURCE_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_dimension) and [D3D12_RESOURCE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags).

### `D3D12_HEAP_FLAG_HARDWARE_PROTECTED:0x100`

Unsupported. Do not use.

### `D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH:0x200`

The heap supports MEM_WRITE_WATCH functionality, which causes the system to track the pages that are written to in the committed memory region. This flag can't be combined with the D3D12_HEAP_TYPE_DEFAULT or D3D12_CPU_PAGE_PROPERTY_UNKNOWN flags. Applications are discouraged from using this flag themselves because it prevents tools from using this functionality.

### `D3D12_HEAP_FLAG_ALLOW_SHADER_ATOMICS:0x400`

Ensures that atomic operations will be atomic on this heap's memory, according to components able to see the memory.

Creating a heap with this flag will fail under either of these conditions.
- The heap type is **D3D12_HEAP_TYPE_DEFAULT**, and the heap can be visible on multiple nodes, but the device does *not* support [**D3D12_CROSS_NODE_SHARING_TIER_3**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_cross_node_sharing_tier).
- The heap is CPU-visible, but the heap type is *not* **D3D12_HEAP_TYPE_CUSTOM**.

Note that heaps with this flag might be a limited resource on some systems.

### `D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT:0x800`

The heap is created in a non-resident state and must be made resident using [ID3D12Device::MakeResident](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-makeresident) or [ID3D12Device3::EnqueueMakeResident](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device3-enqueuemakeresident).

By default, the final step of heap creation is to make the heap resident, so this flag skips this step and allows the application to decide when to do so.

### `D3D12_HEAP_FLAG_CREATE_NOT_ZEROED:0x1000`

Allows the OS to not zero the heap created. By default, committed resources and heaps are almost always zeroed upon creation. This flag allows this to be elided in some scenarios. However, it doesn't guarantee it. For example, memory coming from other processes still needs to be zeroed for data protection and process isolation. This can lower the overhead of creating the heap.

### `D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES:0`

The heap is allowed to store all types of buffers and/or textures. This is an alias; for more details, see "Aliases" in the Remarks section.

### `D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS:0xc0`

The heap is only allowed to store buffers. This is an alias; for more details, see "Aliases" in the Remarks section.

### `D3D12_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES:0x44`

The heap is only allowed to store non-RT, non-DS textures. This is an alias; for more details, see "Aliases" in the Remarks section.

### `D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES:0x84`

The heap is only allowed to store RT and/or DS textures. This is an alias; for more details, see "Aliases" in the Remarks section.

## Remarks

This enum is used by the following API items:

* [ID3D12Device::CreateHeap](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createheap)
* [ID3D12Device::CreateCommittedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createcommittedresource)
* [D3D12_HEAP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_desc) structure

The following heap flags must be used with [ID3D12Device::CreateHeap](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createheap),
but will be set automatically for implicit heaps created by [ID3D12Device::CreateCommittedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createcommittedresource).
Adapters that only support [heap tier 1](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_heap_tier) must set two out of the three following flags.

| Value | Description |
| --- | --- |
| D3D12_HEAP_FLAG_DENY_BUFFERS | The heap isn't allowed to contain resources with D3D12_RESOURCE_DIMENSION_BUFFER (which is a [D3D12_RESOURCE_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_dimension) enumeration constant). |
| D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES | The heap isn't allowed to contain resources with D3D12_RESOURCE_DIMENSION_TEXTURE1D, D3D12_RESOURCE_DIMENSION_TEXTURE2D, or D3D12_RESOURCE_DIMENSION_TEXTURE3D together with either D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET or D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL. (The latter two items are [D3D12_RESOURCE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) enumeration constants.) |
| D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES | The heap isn't allowed to contain resources with D3D12_RESOURCE_DIMENSION_TEXTURE1D, D3D12_RESOURCE_DIMENSION_TEXTURE2D, or D3D12_RESOURCE_DIMENSION_TEXTURE3D unless D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET and D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL are absent. |

### Aliases

Adapters that support [heap tier 2](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_heap_tier) or greater are additionally allowed to set none of the above flags.
Aliases for these flags are available for applications that prefer thinking only of which resources are supported.

The following aliases exist, so be careful when doing bit-manipulations:

* D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES = 0 and is only supported on [heap tier 2](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_heap_tier) and greater.
* D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS = D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES | D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES
* D3D12_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES = D3D12_HEAP_FLAG_DENY_BUFFERS | D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES
* D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES = D3D12_HEAP_FLAG_DENY_BUFFERS | D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES

### Displayable heaps

Displayable heaps are most commonly created by the swapchain for presentation, to enable scanning out to a monitor.

Displayable heaps are specified with the D3D12_HEAP_FLAG_ALLOW_DISPLAY member of the **D3D12_HEAP_FLAGS** enum.

Applications may create displayable heaps outside of a swapchain; but cannot actually present with them.
This flag is not supported by [CreateHeap](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createheap) and can only be used with [CreateCommittedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createcommittedresource) with D3D12_HEAP_TYPE_DEFAULT.

Additional restrictions to the [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_desc) apply to the resource created with displayable heaps.

* The format must not only be supported by the device, but must be supported for scan-out. Refer to the use of the D3D12_FORMAT_SUPPORT1_DISPLAY member of [D3D12_FORMAT_SUPPORT1](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_format_support1).
* *Dimension* must be D3D12_RESOURCE_DIMENSION_TEXTURE2D.
* *Alignment* must be 0.
* *ArraySize* may be either 1 or 2.
* *MipLevels* must be 1.
* *SampleDesc* must have *Count* set to 1 and *Quality* set to 0.
* *Layout* must be D3D12_TEXTURE_LAYOUT_UNKNOWN.
* D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL and D3D12_RESOURCE_FLAG_ALLOW_CROSS_ADAPTER are invalid
  flags.

## See also

[CD3DX12_HEAP_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-heap-desc)

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)

[Descriptor Heaps](https://learn.microsoft.com/windows/desktop/direct3d12/descriptor-heaps)