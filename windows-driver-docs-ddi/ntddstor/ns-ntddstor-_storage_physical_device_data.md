# STORAGE_PHYSICAL_DEVICE_DATA structure

## Description

Specifies the physical data of a storage device.

## Members

### `DeviceId`

The hardware ID of the storage device.

### `Role`

The role of the storage device. This value can be a bitmask of the following values to specify multiple roles:

* STORAGE_COMPONENT_ROLE_CACHE (0x00000001)
* STORAGE_COMPONENT_ROLE_TIERING (0x00000002)
* STORAGE_COMPONENT_ROLE_DATA (0x00000004)

### `HealthStatus`

A [**STORAGE_COMPONENT_HEALTH_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_component_health_status) value that indicates the health status of a storage device.

### `CommandProtocol`

A [**STORAGE_PROTOCOL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_protocol_type) value that specifies the storage command protocols that are used between software and hardware.

### `SpecVersion`

A [**STORAGE_SPEC_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_spec_version) structure that specifies the storage specification version of the storage device.

### `FormFactor`

A [**STORAGE_DEVICE_FORM_FACTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_device_form_factor) value that indicates the form factor of a storage device.

### `Vendor[8]`

The vendor name of the storage device.

### `Model[40]`

The model name of the storage device.

### `FirmwareRevision[16]`

The revision number of the storage device.

### `Capacity`

The capacity of the storage device in units of kilobytes (1024 bytes).

### `PhysicalLocation[32]`

This member is reserved for future use.

### `Reserved[2]`

Reserved; do not use.

## See also

[**STORAGE_PHYSICAL_NODE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_physical_node_data)