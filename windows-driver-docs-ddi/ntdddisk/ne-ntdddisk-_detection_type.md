# DETECTION_TYPE enumeration

## Description

The **DETECTION_TYPE** enumeration type is used in conjunction with the [**IOCTL_DISK_GET_DRIVE_GEOMETRY_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_geometry_ex) request and the [**DISK_GEOMETRY_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry_ex) structure to determine the type of formatting used by the BIOS to record the disk geometry.

## Constants

### `DetectNone`

Indicates that the disk contains neither an INT 13h partition nor an extended INT 13h partition.

### `DetectInt13`

Indicates that the disk has a standard INT 13h partition.

### `DetectExInt13`

Indicates that the disk contains an extended INT 13h partition.

## Remarks

Possible formatting types are the standard INT 13h partition format or the extended INT 13h partition format.

## See also

[**DISK_DETECTION_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_detection_info)