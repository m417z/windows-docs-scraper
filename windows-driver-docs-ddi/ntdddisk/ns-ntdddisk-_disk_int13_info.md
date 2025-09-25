# _DISK_INT13_INFO structure

## Description

The DISK_INT13_INFO structure is used by the BIOS to report disk detection data for a partition with an INT13 format.

## Members

### `DriveSelect`

Corresponds to the Device/Head register defined in the *AT Attachment (ATA)* specification. When zero, the fourth bit of this register indicates that drive zero is selected. When 1, it indicates that drive one is selected. The values of bits 0, 1, 2, 3, and 6 depend on the command in the command register. Bits 5 and 7 are no longer used. For more information about the values that the Device/Head register can hold, see the ATA specification.

### `MaxCylinders`

Indicates the maximum number of cylinders on the disk.

### `SectorsPerTrack`

Indicates the number of sectors per track.

### `MaxHeads`

Indicates the maximum number of disk heads.

### `NumberDrives`

Indicates the number of drives.

## See also

[DISK_DETECTION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_detection_info)

[DISK_EX_INT13_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_ex_int13_info)