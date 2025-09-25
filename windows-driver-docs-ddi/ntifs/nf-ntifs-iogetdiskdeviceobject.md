# IoGetDiskDeviceObject function

## Description

The **IoGetDiskDeviceObject** routine retrieves a pointer to the disk device object associated with a given file system volume device object.

## Parameters

### `FileSystemDeviceObject` [in]

A pointer to the file system device object.

### `DiskDeviceObject`

A pointer to a variable that receives the address of the device object for the disk device object.

## Return value

**IoGetDiskDeviceObject** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | One of the parameters passed to this function was invalid. |
| **STATUS_VOLUME_DISMOUNTED** |  |
| **STATUS_SUCCESS** |  |

## Remarks

**IoGetDiskDeviceObject** returns a pointer to the storage device object associated with the file system volume. The storage device need not be an actual disk

File system filter drivers typically call **IoGetDiskDeviceObject** for a file system volume device object to determine whether the volume is mounted.

**IoGetDiskDeviceObject** increments the reference count on the disk device object pointed to by *DeviceObject*. Thus every successful call to **IoGetDiskDeviceObject** must be matched by a subsequent call to [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject).

## See also

[IoEnumerateDeviceObjectList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioenumeratedeviceobjectlist)

[IoGetAttachedDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetattacheddevice)

[IoGetAttachedDeviceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetattacheddevicereference)

[IoGetLowerDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetlowerdeviceobject)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)