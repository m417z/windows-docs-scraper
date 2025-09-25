## Description

Creates a command queue with a creator ID.

Also see [ID3D12Device::CreateCommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcommandqueue).

## Parameters

### `pDesc`

Type: \_In\_ **const [D3D12_COMMAND_QUEUE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_command_queue_desc)\***

Specifies a **D3D12_COMMAND_QUEUE_DESC** that describes the command queue.

### `CreatorID`

Type: **[REFIID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/bbde795f-5398-42d8-9f59-3613da03c318)**

A creator ID. See **Remarks**.

### `riid`

Type: **[REFIID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/bbde795f-5398-42d8-9f59-3613da03c318)**

The globally unique identifier (GUID) for the command queue interface.

### `ppCommandQueue`

Type: \_COM\_Outptr\_ **void\*\***

A pointer to a memory block that receives a pointer to the [ID3D12CommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue) interface for the command queue.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **E_OUTOFMEMORY** if there's insufficient memory to create the command queue; otherwise **S_OK**. See [Direct3D 12 return codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

When multiple components in the same process are sharing a single Direct3D 12 device, often they will end up with separate workloads on independent command queues. In some hardware implementations, independent queues can run in parallel only with specific other command queues.
Direct3D 12 applies a first-come, first-serve grouping for queues, which might not work well for all application or component designs. To help inform Direct3D 12's grouping of queues, you can specify a *creator ID* (which is unique per component) that restricts the grouping to other queues with the same ID. When possible, a component should choose the same unique ID for all of its queues. Microsoft has reserved a few well-known creator IDs for use by Microsoft-developed implementations of APIs on top of Direct3D 12.

## See also

* [ID3D12Device::CreateCommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcommandqueue)