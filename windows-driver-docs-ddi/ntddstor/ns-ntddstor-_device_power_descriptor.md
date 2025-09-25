# _DEVICE_POWER_DESCRIPTOR structure

## Description

Used in conjunction with the
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) control code
to describes the power capabilities of a storage device.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to
the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this
structure.

### `DeviceAttentionSupported`

**True** if device attention is supported. Otherwise, **False**.

### `AsynchronousNotificationSupported`

**True** if the device supports asynchronous notifications, delivered via
**IOCTL_STORAGE_EVENT_NOTIFICATION**. Otherwise, **False**

### `IdlePowerManagementEnabled`

**True** if the device has been registered for runtime idle power management. Otherwise, **False**

### `D3ColdEnabled`

**True** if the device will be powered off when put into the D3 power state. Otherwise, **False**

### `D3ColdSupported`

**True** if the platform supports **D3ColdEnabled** for this device. Otherwise,
**False**.

### `NoVerifyDuringIdlePower`

**True** if the device requires no verification during idle power transitions. Otherwise, **False**

### `Reserved`

Reserved.

### `IdleTimeoutInMS`

The idle timeout value in milliseconds. This member is ignored unless
**IdlePowerManagementEnabled** is true.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)