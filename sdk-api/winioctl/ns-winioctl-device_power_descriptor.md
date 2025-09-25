# DEVICE_POWER_DESCRIPTOR structure

## Description

The **DEVICE_POWER_DESCRIPTOR**
structure describes the power capabilities of a storage device.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to
the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this
structure.

### `DeviceAttentionSupported`

True if device attention is supported. Otherwise, false.

### `AsynchronousNotificationSupported`

True if the device supports asynchronous notifications, delivered via
**IOCTL_STORAGE_EVENT_NOTIFICATION**. Otherwise, false.

### `IdlePowerManagementEnabled`

True if the device has been registered for runtime idle power management. Otherwise, false.

### `D3ColdEnabled`

True if the device will be powered off when put into D3 power state. Otherwise, false.

### `D3ColdSupported`

True if the platform supports **D3ColdEnabled** for this device. Otherwise,
false.

### `NoVerifyDuringIdlePower`

### `Reserved`

Reserved.

### `IdleTimeoutInMS`

The idle timeout value in milliseconds. This member is ignored unless
**IdlePowerManagementEnabled** is true.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)

[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query)