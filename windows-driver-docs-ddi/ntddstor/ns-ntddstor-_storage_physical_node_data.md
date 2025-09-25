# STORAGE_PHYSICAL_NODE_DATA structure

## Description

Specifies the physical device data of a storage node.

## Members

### `NodeId`

The hardware ID of the storage node.

### `AdapterCount`

A value of 0 or 1 that indicates the adapter count in the storage node.

### `AdapterDataLength`

The data length of the storage adapter in the storage node, in units of kilobytes (1024 bytes).

### `AdapterDataOffset`

The data offset from the beginning of the data structure. The buffer contains an array of [**STORAGE_PHYSICAL_ADAPTER_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_physical_adapter_data).

### `DeviceCount`

A value equal to or greater than 1 that indicates the device count in the storage node.

### `DeviceDataLength`

The data length of the storage device in the storage node, in units of kilobytes (1024 bytes).

### `DeviceDataOffset`

The data offset from the beginning of the data structure. The buffer contains an array of [**STORAGE_PHYSICAL_DEVICE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_physical_device_data).

### `Reserved[3]`

Reserved; do not use.

## See also

[**STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_physical_topology_descriptor)