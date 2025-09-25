# DIHIDFFINITINFO structure

## Description

The **DIHIDFFINITINFO** structure is used by DirectInput to provide information to a HID force-feedback driver about the device it is being asked to control.

## Members

### `dwSize`

Specifies the size of the structure in bytes. This member must be initialized before the structure is used.

### `pwszDeviceInterface`

Points to a null-terminated Unicode string that identifies the device interface for the device. The driver can pass the device interface to the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function to obtain access to the device.

### `GuidInstance`

Specifies a device instance GUID for this device.