# D3D12_DEVICE_REMOVED_EXTENDED_DATA1 structure

## Description

Represents Device Removed Extended Data (DRED) version 1.1 device removal data, so that debuggers and debugger extensions can access DRED data. Also see [D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_versioned_device_removed_extended_data).

This structure is not used by any interface methods, and it provides no runtime API access.

## Members

### `DeviceRemovedReason`

An [HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) containing the reason the device was removed (matches the return value of [GetDeviceRemovedReason](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getdeviceremovedreason)). Also see [COM Error Codes (UI, Audio, DirectX, Codec)](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

### `AutoBreadcrumbsOutput`

A [D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_auto_breadcrumb_node) value that contains the auto-breadcrumb state prior to device removal.

### `pHeadAutoBreadcrumbNode`

An output parameter of type pointer to [D3D12_AUTO_BREADCRUMB_NODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_auto_breadcrumb_node) representing the returned auto-breadcrumb object(s). This is a pointer to the head of a linked list of auto-breadcrumb node objects. All of the nodes in the linked list represent potentially incomplete command list execution on the GPU at the time of the device-removal event.

### `PageFaultOutput`

A [D3D12_DRED_PAGE_FAULT_OUTPUT](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_auto_breadcrumb_node) value that contains page fault data if device removal was the result of a GPU page fault.

## See also

* [Core structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
* [D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_versioned_device_removed_extended_data)
* [Use DRED to diagnose GPU faults](https://learn.microsoft.com/windows/desktop/direct3d12/use-dred)