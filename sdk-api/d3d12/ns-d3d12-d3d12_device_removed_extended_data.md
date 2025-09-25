# D3D12_DEVICE_REMOVED_EXTENDED_DATA structure

## Description

> [!NOTE]
> As of Windows 10, version 1903, **D3D12_DEVICE_REMOVED_EXTENDED_DATA** is deprecated, and it may not be available in future versions of Windows. Use [**D3D12_DEVICE_REMOVED_EXTENDED_DATA1**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_device_removed_extended_data1), instead.

Represents Device Removed Extended Data (DRED) version 1.0 data.

## Members

### `Flags`

An input parameter of type [D3D12_DRED_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_dred_flags), specifying control flags for the Direct3D runtime.

### `pHeadAutoBreadcrumbNode`

An output parameter of type pointer to [D3D12_AUTO_BREADCRUMB_NODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_auto_breadcrumb_node) representing the returned auto-breadcrumb object(s). This is a pointer to the head of a linked list of auto-breadcrumb objects. All of the nodes in the linked list represent potentially incomplete command list execution on the GPU at the time of the device-removal event.

## See also

* [Core structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
* [Use DRED to diagnose GPU faults](https://learn.microsoft.com/windows/desktop/direct3d12/use-dred)