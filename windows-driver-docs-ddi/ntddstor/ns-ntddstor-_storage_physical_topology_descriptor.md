# _STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR structure

## Description

The **STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR** structure describes the physical topology of a device or adapter.

## Members

### `Version`

Version of this structure, in bytes. The value of this member will change as members are added to the structure. Set to **sizeof**(STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR).

### `Size`

Total size of the data, in bytes, which may include data that follows this structure. Should be >= **sizeof**(STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR).

### `NodeCount`

Total number of storage nodes in the system.

### `Reserved`

Reserved for future use. Do not use.

### `Node`

Array of [STORAGE_PHYSICAL_NODE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_physical_node_data) structures that describe the physical device data of each storage node. The number of structures in the array is determined by *NodeCount*.

## Remarks

The STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR structure is returned from an [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request that has a **PropertyId** of StorageAdapterPhysicalTopologyProperty or StorageDevicePhysicalTopologyProperty.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[STORAGE_PHYSICAL_NODE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_physical_node_data)