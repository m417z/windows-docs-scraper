# D3D12_FEATURE_DATA_ARCHITECTURE1 structure

## Description

Provides detail about each adapter's architectural details, so that your application can better optimize for certain adapter properties.

**Note** This structure, introduced in Windows 10, version 1703 (Creators' Update), supersedes the [D3D12_FEATURE_DATA_ARCHITECTURE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_architecture) structure. If your application targets Windows 10, version 1703 (Creators' Update) or higher, then use **D3D12_FEATURE_DATA_ARCHITECTURE1** (and [D3D12_FEATURE_ARCHITECTURE1](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_feature)).

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device is relevant.
See [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).
**NodeIndex** is filled out by the application before calling [CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport), as the application can retrieve details about the architecture of each adapter.

### `TileBasedRenderer`

Specifies whether the hardware and driver support a tile-based renderer.
The runtime sets this member to **TRUE** if the hardware and driver support a tile-based renderer.

### `UMA`

Specifies whether the hardware and driver support UMA.
The runtime sets this member to **TRUE** if the hardware and driver support UMA.

### `CacheCoherentUMA`

Specifies whether the hardware and driver support cache-coherent UMA.
The runtime sets this member to **TRUE** if the hardware and driver support cache-coherent UMA.

### `IsolatedMMU`

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-structs-and-classes): `_Out_`

Specifies whether the hardware and driver support isolated Memory Management Unit (MMU).
The runtime sets this member to **TRUE** if the GPU honors CPU page table properties like **MEM_WRITE_WATCH** (for more information, see [VirtualAlloc](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc)) and **PAGE_READONLY** (for more information, see [Memory Protection Constants](https://learn.microsoft.com/windows/win32/Memory/memory-protection-constants)).

If **TRUE**, the application must take care to no use memory with these page table properties with the GPU, as the GPU might trigger these page table properties in unexpected ways. For example, GPU write operations might be coarser than the application expects, particularly writes from within shaders. Certain write-watch pages might appear dirty, even when it isn't obvious how GPU writes may have affected them. GPU operations associated with upload and readback heap usage scenarios work well with write-watch pages, but might occasionally generate false positives that can be safely ignored.

## Remarks

### How to use UMA and CacheCoherentUMA

D3D12 apps should be concerned about managing memory residency and providing the optimal heap properties.
D3D12 apps can stay simplified and run reasonably well across many GPU architectures by only managing the residency for resources in [D3D12_HEAP_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type)_DEFAULT heaps.
Those apps only need to call [IDXGIAdapter3::QueryVideoMemoryInfo](https://learn.microsoft.com/windows/win32/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-queryvideomemoryinfo) for DXGI_MEMORY_SEGMENT_GROUP_LOCAL,
and they must be tolerant that D3D12_HEAP_TYPE_UPLOAD and D3D12_HEAP_TYPE_READBACK come from that same memory segment group.

However, such a simple design is too constraining for applications that push the limits.
So, D3D12_FEATURE_DATA_ARCHITECTURE helps applications better optimize for the underlying adapter properties.

Some applications may want to better optimize for discrete adapters, and take on the additional complexity of managing both system memory and video memory budgets.
If the size of upload heaps rivals the size of default textures, a near doubling of memory utilization is available.
When supporting such optimizations, an application can either detect two residency budgets or recognize **UMA** is **false**.

Some applications may want to better optimize for integrated/ UMA adapters, especially those that are interested in extending battery life on mobile device.
Simple D3D12 applications are forced into copying data between heaps with different attributions, when it isn't always necessary on UMA.
However, the UMA property, by itself, encompasses a reasonably vague grey area of GPU designs.
Do not assume UMA means all GPU-accessible memory can be freely made CPU-accessible, because it doesn't.
There's a property that more closely aligns to that type of thinking: **CacheCoherentUMA**.

When **CacheCoherentUMA** is **false**, a single residency budget is available but the UMA design commonly benefits from the three heap attributions.
Opportunities do exist to remove resource copying through wise usage of upload and readback resources and heaps, that provide CPU-access to the memory.
Such opportunities are not clear-cut, though.
So, applications should be cautious; and experimentation across a variety of "UMA" systems is advisable, as resorting to enabling or precluding certain device IDs may be warranted.
An understanding of the GPU memory architecture and how heap types translate to cache properties is recommended.
The feasibility of success is likely dependent on how often each processor either reads or writes the data, the size and locality of data accesses, etc.
For advanced developers: when **UMA** is true and **CacheCoherentUMA** is **false**, the most unique characteristic for these adapters is that upload heaps are still write-combined.
However, some UMA adapters benefit from both the no-CPU-access and write-combine properties of default and upload heaps.
See [GetCustomHeapProperties](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getcustomheapproperties(uint_d3d12_heap_type)) for more details.

When **CacheCoherentUMA** is true, applications can more strongly entertain abandoning the attribution of heaps and using the custom heap equivalent of upload heaps everywhere.
Zero-copy UMA optimizations such those offered by
[WriteToSubresource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12resource-writetosubresource) are more generally encouraged as more scenarios will just benefit from shared usage.
The memory model is very conducive to more scenarios and wider adoption.
Some corner cases may still exist where benefits are not easily obtained, but they should be much rarer and less detrimental than other options.
For advanced developers: **CacheCoherentUMA** means that a significant amount of the caches in the memory hierarchy are also unified or integrated between the CPU and GPU.
The most unique observable characteristic is that upload heaps are actually write-back on **CacheCoherentUMA**.
For these architecture, the usage of write-combine on upload heaps is commonly a detriment.

The low-level details should be ignored by a vast majority of single-adapter applications.
As usual, single-adapter applications can simplify the landscape and ensure that the CPU writes to upload heaps use patterns that are write-combine-friendly.
The lower-level details help reinforce the concepts for multi-adapter applications.
Multi-adapter applications likely need to understand adapter architecture properties well enough to choose the optimal custom heap properties to efficiently move data between adapters.

## See also

[Core Structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_feature)