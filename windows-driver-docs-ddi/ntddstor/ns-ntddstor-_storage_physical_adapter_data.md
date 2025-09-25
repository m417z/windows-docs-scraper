# STORAGE_PHYSICAL_ADAPTER_DATA structure

## Description

Specifies the physical data of a storage adapter.

## Members

### `AdapterId`

The hardware ID of the storage adapter.

### `HealthStatus`

A [**STORAGE_COMPONENT_HEALTH_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_component_health_status) value that indicates the health status of a storage adapter.

### `CommandProtocol`

A [**STORAGE_PROTOCOL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_protocol_type) value that specifies the storage command protocols that are used between software and hardware.

### `SpecVersion`

A [**STORAGE_SPEC_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_spec_version) structure that specifies the storage specification version of the storage adapter.

### `Vendor[8]`

The vendor name of the storage adapter

### `Model[40]`

The model name of the storage adapter.

### `FirmwareRevision[16]`

The firmware revision number of the storage adapter.

### `PhysicalLocation[32]`

This member is reserved for future use.

### `ExpanderConnected`

Indicates whether a storage expander is connected to the storage adapter.

### `Reserved0[3]`

Reserved; do not use.

### `Reserved1[3]`

Reserved; do not use.

## See also

[**STORAGE_PHYSICAL_NODE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_physical_node_data)