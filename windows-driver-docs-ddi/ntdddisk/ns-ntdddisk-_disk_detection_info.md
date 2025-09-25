# DISK_DETECTION_INFO structure

## Description

The **DISK_DETECTION_INFO** structure contains the detected drive parameters that are supplied by an x86 PC BIOS on boot.

## Members

### `SizeOfDetectInfo`

Contains the quantity, in bytes, of retrieved detect information.

### `DetectionType`

A [**DETECTION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ne-ntdddisk-_detection_type) value that determines the type of formatting used by the BIOS to record the disk geometry.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Int13`

A [**DISK_INT13_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_int13_info) structure when **DetectionType** is **DetectInt13**.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ExInt13`

A [**DISK_EX_INT13_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_ex_int13_info) structure when **DetectionType** is **DetectExInt13**.

## See also

[**DISK_EX_INT13_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_ex_int13_info)

[**DISK_GEOMETRY_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry_ex)

[**DISK_INT13_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_int13_info)