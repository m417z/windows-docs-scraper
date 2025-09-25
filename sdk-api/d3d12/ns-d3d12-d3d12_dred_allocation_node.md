# D3D12_DRED_ALLOCATION_NODE structure

## Description

Describes, as a node in a linked list, data about an allocation tracked by Device Removed Extended Data (DRED). This data includes the GPU VA allocation ranges, and an associated runtime object debug name and type. Each **D3D12_DRED_ALLOCATION_NODE** object is singly linked to the next via its `pNext` member; except for the last node in the list, which has its `pNext` set to `nullptr`. A linked list structure is necessary because a runtime object can share allocation ranges with other objects.

If device removal is caused by a GPU page fault—and DRED page fault reporting is enabled—then DRED builds a list of D3D12_DRED_ALLOCATION_NODE structs that includes all matching allocation nodes for active and recently-freed runtime objects.

## Members

### `ObjectNameA`

A pointer to the ANSI debug name of the allocated runtime object.

### `ObjectNameW`

A pointer to the wide debug name of the allocated runtime object.

### `AllocationType`

A [D3D12_DRED_ALLOCATION_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_dred_allocation_type) value representing the runtime object's allocation type.

### `pNext`

A pointer to a constant **D3D12_DRED_ALLOCATION_NODE** representing the next allocation node in the list, or `nullptr` if this is the last node.

## See also

* [Core structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
* [Use DRED to diagnose GPU faults](https://learn.microsoft.com/windows/desktop/direct3d12/use-dred)