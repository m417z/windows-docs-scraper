# D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT structure

## Description

Contains a pointer to the head of a linked list of [D3D12_AUTO_BREADCRUMB_NODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_auto_breadcrumb_node) objects. The list represents the auto-breadcrumb state prior to device removal.

## Members

### `pHeadAutoBreadcrumbNode`

A pointer to a constant [D3D12_AUTO_BREADCRUMB_NODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_auto_breadcrumb_node) object representing the head of a linked list of auto-breadcrumb nodes, or `nullptr` if the list is empty.

## See also

* [Core structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
* [Use DRED to diagnose GPU faults](https://learn.microsoft.com/windows/desktop/direct3d12/use-dred)