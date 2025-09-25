# D3D12DDICAPS_HARDWARE_SCHEDULING_CAPS_0050 structure

## Description

Determines how the runtime will manage associations of 3D and compute queues to scheduling groups.

The runtime will manage associations of 3D and compute queues to scheduling groups, on a first-come-first-serve basis.

## Members

### `ComputeQueuesPer3DQueue`

The number of compute API-level command queues that should be associated with a scheduling group.

## Remarks

The runtime will only assign one 3D command queue per node per scheduling group. If the driver reports a cap value of 0, the runtime will not attempt to create scheduling groups, and all contexts will continue to be owned by command queues directly.

Otherwise, the runtime will maintain a device-local set of scheduling groups. Every time a 3D/compute command queue is created, the runtime will runtime the following logic:

1. If an existing scheduling group has a slot for the particular type of command queue being created, fill that slot. Existing scheduling groups are searched in the order they were created.
2. Otherwise, create a new scheduling group to assign the new command queue to.

## See also