# STORAGE_PHYSICAL_DEVICE_DATA structure

## Description

Describes a physical storage device.

## Members

### `DeviceId`

Specifies the device ID.

### `Role`

Value(s) of bitmask from STORAGE_COMPONENT_ROLE_xxx

### `HealthStatus`

A [STORAGE_COMPONENT_HEALTH_STATUS](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_component_health_status) enumeration.

### `CommandProtocol`

A [STORAGE_PROTOCOL_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_protocol_type) enumeration.

### `SpecVersion`

A [STORAGE_SPEC_VERSION](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_spec_version) structure that specifies the supported storage spec version. For example: SBC 3, SATA 3.2, NVMe 1.2

### `FormFactor`

A [STORAGE_DEVICE_FORM_FACTOR](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_device_form_factor) enumeration.

### `Vendor`

Specifies the device vendor.

### `Model`

Specifies the device model.

### `FirmwareRevision`

Specifies the firmware revision of the device.

### `Capacity`

In units of kilobytes (1024 bytes).

### `PhysicalLocation`

Reserved for future use.

### `Reserved`