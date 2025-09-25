# DISK_EX_INT13_INFO structure

## Description

Contains extended Int13 drive parameters.

## Members

### `ExBufferSize`

The size of the extended drive parameter buffer for this partition or disk. For valid values, see the BIOS documentation.

### `ExFlags`

The information flags for this partition or disk. For valid values, see the BIOS documentation.

### `ExCylinders`

The number of cylinders per head. For valid values, see the BIOS documentation.

### `ExHeads`

The maximum number of heads for this hard disk. For valid values, see the BIOS documentation.

### `ExSectorsPerTrack`

The number of sectors per track. For valid values, see the BIOS documentation.

### `ExSectorsPerDrive`

The total number of sectors for this disk. For valid values, see the BIOS documentation.

### `ExSectorSize`

The sector size for this disk. For valid values, see the BIOS documentation.

### `ExReserved`

Reserved for future use.

## See also

[DISK_DETECTION_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-disk_detection_info)