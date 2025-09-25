# D3D12_COMMAND_QUEUE_DESC structure

## Description

Describes a command queue.

## Members

### `Type`

Specifies one member of [D3D12_COMMAND_LIST_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_command_list_type).

### `Priority`

The priority for the command queue, as a
[D3D12_COMMAND_QUEUE_PRIORITY](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_command_queue_priority) enumeration constant to select normal or high priority.

### `Flags`

Specifies any flags from the [D3D12_COMMAND_QUEUE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_command_queue_flags) enumeration.

### `NodeMask`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies.
Each bit in the mask corresponds to a single node.
Only 1 bit must be set.
Refer to [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

## Remarks

This structure is passed into [CreateCommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcommandqueue).

This structure is returned by [ID3D12CommandQueue::GetDesc](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-getdesc).

## See also

[Core Structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)