# D3D12DDIARG_CREATECOMMANDQUEUE_0050 structure

## Description

Arguments used to create a hardware command queue.

## Members

### `QueueFlags`

Command queue flags.

### `NodeMask`

The node mask of the command list.

### `QueueCreationFlags`

Command queue creation flags.

### `SchedulingGroup`

The hardware scheduling group.

## Remarks

The driver is allowed to have a command queue which owns both software-scheduled contexts, and hardware queues, if and only if the command queue also owns the contexts for those hardware queues. Each command queue must be capable of performing broadcast synchronization across only contexts for mixed hardware and software, or only hardware queues.

## See also