## Description

The **D3D12DDIARG_CREATEHEAP_0001** structure describes a heap.

## Members

### `ByteSize`

Size of the heap, in bytes.

### `Alignment`

The alignment value of the heap. See [**D3D12_HEAP_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_heap_desc) for a list of possible values.

### `MemoryPool`

A [**D3D12DDI_MEMORY_POOL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_memory_pool) value that specifies the memory pool for the heap.

### `CPUPageProperty`

A [**D3D12DDI_CPU_PAGE_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_cpu_page_property) value that specifies the CPU page properties for the heap.

### `Flags`

A [**D3D12DDI_HEAP_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_heap_flags) value with a bit-wise OR of heap options.

### `CreationNodeMask`

For multi-adapter operations, this indicates the node where the resource should be created.

Exactly one bit of this UINT must be set. See [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

Passing zero is equivalent to passing one, in order to simplify the usage of single-GPU adapters.

### `VisibleNodeMask`

For multi-adapter operations, this indicates the set of nodes where the resource is visible.

**VisibleNodeMask** must have the same bit set that is set in **CreationNodeMask**. **VisibleNodeMask** can also have additional bits set for cross-node resources, but doing so can potentially reduce performance for resource accesses, so you should do so only when needed.

Passing zero is equivalent to passing one, in order to simplify the usage of single-GPU adapters.

## Remarks

## See also