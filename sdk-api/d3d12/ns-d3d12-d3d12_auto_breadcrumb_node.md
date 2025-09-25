## Description

Represents Device Removed Extended Data (DRED) auto-breadcrumb data as a node in a linked list. Each **D3D12_AUTO_BREADCRUMB_NODE** object is singly linked to the next via its `pNext` member; except for the last node in the list, which has its `pNext` set to `nullptr`.

The Direct3D 12 runtime creates one of these for each graphics command list, and tracks them in the command allocator associated with the list. When a command list is executed, the command queue information is set. After device removal is detected, the Direct3D 12 runtime links together the auto-breadcrumb nodes for any GPU work that is still outstanding.

## Members

### `pCommandListDebugNameA`

A pointer to the ANSI debug name of the outstanding command list (if any).

### `pCommandListDebugNameW`

A pointer to the wide debug name of the outstanding command list (if any).

### `pCommandQueueDebugNameA`

A pointer to the ANSI debug name of the outstanding command queue (if any).

### `pCommandQueueDebugNameW`

A pointer to the wide debug name of the outstanding command queue (if any).

### `pCommandList`

A pointer to the [ID3D12GraphicsCommandList interface](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist) representing the outstanding command list at the time of execution.

### `pCommandQueue`

A pointer to the [ID3D12CommandQueue interface](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue) representing the outstanding command queue.

### `BreadcrumbCount`

A **UINT32** containing the count of [D3D12_AUTO_BREADCRUMB_OP](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_auto_breadcrumb_op) values in the array pointed to by `pCommandHistory`.

### `pLastBreadcrumbValue`

A pointer to a constant **UINT32** containing the number of *pCommandHistory* breadcrumbs ops completed. As such, the last successfully completed breadcrumb op is at index `(*pLastBreadcrumbValue - 1)` in *pCommandHistory*.

### `pCommandHistory`

A pointer to a constant array of [D3D12_AUTO_BREADCRUMB_OP](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_auto_breadcrumb_op) values representing all of the render/compute operations recorded into the associated command list.

### `pNext`

A pointer to a constant **D3D12_AUTO_BREADCRUMB_NODE** representing the next auto-breadcrumb node in the list, or `nullptr` if this is the last node.

## See also

* [Core structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
* [Use DRED to diagnose GPU faults](https://learn.microsoft.com/windows/desktop/direct3d12/use-dred)