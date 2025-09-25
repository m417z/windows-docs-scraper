# D3D12_DRED_PAGE_FAULT_OUTPUT structure

## Description

Describes allocation data related to a GPU page fault on a given virtual address (VA). Contains the VA of a GPU page fault, together with a list of matching allocation nodes for active objects, and a list of allocation nodes for recently deleted objects.

## Members

### `PageFaultVA`

A [D3D12_GPU_VIRTUAL_ADDRESS](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12_gpu_virtual_address) containing the GPU virtual address (VA) of the faulting operation if device removal was due to a GPU page fault.

### `pHeadExistingAllocationNode`

A pointer to a constant [D3D12_DRED_ALLOCATION_NODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_dred_allocation_node) object representing the head of a linked list of allocation nodes for active allocated runtime objects with virtual address (VA) ranges that match the faulting VA (`PageFaultVA`). Has a value of `nullptr` if the list is empty.

### `pHeadRecentFreedAllocationNode`

A pointer to a constant [D3D12_DRED_ALLOCATION_NODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_dred_allocation_node) object representing the head of a linked list of allocation nodes for recently freed runtime objects with virtual address (VA) ranges that match the faulting VA (`PageFaultVA`). Has a value of `nullptr` if the list is empty.

## See also

* [Core structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
* [Use DRED to diagnose GPU faults](https://learn.microsoft.com/windows/desktop/direct3d12/use-dred)