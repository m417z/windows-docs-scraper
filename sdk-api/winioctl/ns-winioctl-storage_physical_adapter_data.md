## Description

Describes a physical storage adapter.

## Members

### `AdapterId`

Specifies the adapter ID.

### `HealthStatus`

A [STORAGE_COMPONENT_HEALTH_STATUS](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_component_health_status)-typed value.

### `CommandProtocol`

A [STORAGE_PROTOCOL_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_protocol_type)-typed value.

### `SpecVersion`

A [STORAGE_SPEC_VERSION](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_spec_version)-typed value that specifies the supported storage spec version (for example, AHCI 1.3.1).

### `ExpanderConnected`

Indicates whether an expander is connected.

### `FirmwareRevision`

Specifies the firmware revision.

### `Model`

Specifies the adapter model.

### `PhysicalLocation`

Reserved for future use.

### `Reserved0`

Reserved.

### `Reserved1`

Reserved.

### `Vendor`

Specifies the adapter vendor.