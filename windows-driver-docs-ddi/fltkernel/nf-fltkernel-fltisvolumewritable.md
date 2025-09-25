# FltIsVolumeWritable function

## Description

The **FltIsVolumeWritable** routine determines whether the disk device that corresponds to a volume or minifilter driver instance is writable.

## Parameters

### `FltObject` [in]

An opaque pointer for the volume or instance. Be aware that the associated volume must be a local file system volume.

### `IsWritable` [out]

A pointer to a caller-allocated Boolean variable that receives **TRUE** if the volume is writable; **FALSE** otherwise.

## Return value

**FltIsVolumeWritable** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltIsVolumeWritable** encountered a memory allocation failure. This is an error code. |
| **STATUS_INVALID_DEVICE_REQUEST** | The disk device does not support IOCTL_DISK_IS_WRITABLE requests. This is an error code. |

## Remarks

**FltIsVolumeWritable** sends an [IOCTL_DISK_IS_WRITABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_is_writable) request to the underlying storage device that is associated with the given volume or instance.

In versions of Windows prior to Windows Vista, the **FltIsVolumeWritable** routine accepted only volumes, not instances.

## See also

[IOCTL_DISK_IS_WRITABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_is_writable)