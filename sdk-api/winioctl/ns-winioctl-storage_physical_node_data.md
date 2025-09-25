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

The data offset from the beginning of the data structure. The buffer contains an array of [STORAGE_PHYSICAL_ADAPTER_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_physical_adapter_data).

### `DeviceCount`

A value less than or equal to 1.

### `DeviceDataLength`

The data length of the storage device in the storage node, in units of kilobytes (1024 bytes).

### `DeviceDataOffset`

The data offset from the beginning of the data structure. The buffer contains an array of [STORAGE_PHYSICAL_DEVICE_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_physical_device_data).

### `Reserved`

Specifies if the storage adapter is reserved.