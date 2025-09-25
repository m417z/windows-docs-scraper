# D3D12_COMMAND_QUEUE_PRIORITY enumeration

## Description

Defines priority levels for a command queue.

## Constants

### `D3D12_COMMAND_QUEUE_PRIORITY_NORMAL:0`

Normal priority.

### `D3D12_COMMAND_QUEUE_PRIORITY_HIGH:100`

High priority.

### `D3D12_COMMAND_QUEUE_PRIORITY_GLOBAL_REALTIME:10000`

Global realtime priority.

## Remarks

This enumeration is used by the **Priority** member of the
[D3D12_COMMAND_QUEUE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_command_queue_desc) structure.

An application must be sufficiently privileged in order to create a command queue that has global realtime priority. If the application is not sufficiently privileged or if neither the adapter or driver can provide the necessary preemption, then requests to create a global realtime priority queue fail; such a failure could be due to a lack of hardware support or due to conflicts with other command queue parameters. Requests to create a global realtime command queue won't silently downgrade the priority when it can't be supported; the request succeeds or fails as-is to indicate to the application whether or not the command queue is guaranteed to execute before any other queue.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)