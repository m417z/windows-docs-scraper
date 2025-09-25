# _DISK_EX_INT13_INFO structure

## Description

The DISK_EX_INT13_INFO structure is used by the BIOS to report disk detection data for a partition with an extended INT13 format.

## Members

### `ExBufferSize`

Indicates the size of the buffer that the caller provides to the BIOS in which to return the requested drive data. **ExBufferSize** must be 26 or greater. If **ExBufferSize** is less than 26, the BIOS returns an error . If **ExBufferSize** is between 30 and 66, the BIOS sets it to exactly 30 on exit. If **ExBufferSize** is 66 or greater, the BIOS sets it to exactly 66 on exit.

### `ExFlags`

Provides information about the drive. The following table describes the significance of each bit, where bit 0 is the least significant bit and bit 15 the most significant bit. A value of one in the indicated bit means that the feature described in the "Meaning" column is available. A value of zero in the indicated bit means that the feature is not available with this drive.

| Bit number | Meaning |
| --- | --- |
| 0 | DMA boundary errors are handled transparently. |
| 1 | The geometry supplied in bytes 8-12 is valid. |
| 2 | Device is removable. |
| 3 | Device supports write with verify. |
| 4 | Device has change line support (bit 2 must be set). |
| 5 | Device is lockable (bit 2 must be set). |
| 6 | Device geometry is set to maximum, no media is present (bit 2 must be set). This bit is turned off when media is present in a removable media device. |
| 7-15 | Reserved, must be 0. |

### `ExCylinders`

Indicates the number of *physical* cylinders. This is one greater than the maximum cylinder number.

### `ExHeads`

Indicates the number of *physical* heads. This is one greater than the maximum head number.

### `ExSectorsPerTrack`

Indicates the number of *physical* sectors per track. This number is the same as the maximum sector number.

### `ExSectorsPerDrive`

Indicates the total count of sectors on the disk. This is one greater than the maximum logical block address.

### `ExSectorSize`

Indicates the sector size in bytes.

### `ExReserved`

Reserved.

## See also

[DISK_DETECTION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_detection_info)

[DISK_INT13_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_int13_info)