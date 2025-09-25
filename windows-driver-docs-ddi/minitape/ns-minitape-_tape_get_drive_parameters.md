# _TAPE_GET_DRIVE_PARAMETERS structure (minitape.h)

## Description

The TAPE_GET_DRIVE_PARAMETERS structure is used in conjunction with the [IOCTL_TAPE_GET_DRIVE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_get_drive_params) request to retrieve information about capabilities of the tape drive.

## Members

### `ECC`

When set to **TRUE**, indicates that the device uses hardware error correction.

### `Compression`

When set to **TRUE**, indicates that compression is enabled on a device that supports it. When compression is enabled, the device compresses data prior to writing it. When set to **FALSE**, compression is not enabled on the device.

### `DataPadding`

When set to **TRUE**, indicates that data padding is enabled on a device that supports it. When padding is enabled, the device pads data with zeros to keep the tape streaming until data is ready. When set to **FALSE**, data padding is not enabled.

### `ReportSetmarks`

When set to **TRUE**, indicates that reporting setmarks is enabled on a device that supports it. The device reports setmarks encountered during read or space operations. When set to **FALSE**, reporting setmarks is not enabled.

### `DefaultBlockSize`

Indicates the default block size, in bytes.

### `MaximumBlockSize`

Indicates the maximum block size, in bytes, of either the tape device or the underlying host bus adapter (HBA), whichever is smaller.

### `MinimumBlockSize`

Indicates the minimum block size, in bytes.

### `MaximumPartitionCount`

Indicates the maximum number of partitions the device supports.

### `FeaturesLow`

Indicates the features supported by this drive. The miniport driver sets TAPE_DRIVE_*XXX* flags for features supported by the drive and clears flags for features not supported. Callers can use the TAPE_DRIVE_*XXX* masks defined in *minitape.h* to determine whether a drive supports a particular feature. The masks available are as follows:

| Mask | Meaning |
| --- | --- |
| TAPE_DRIVE_CLEAN_REQUESTS | The device can report whether it requires cleaning. |
| TAPE_DRIVE_COMPRESSION | The device supports hardware data compression. |
| TAPE_DRIVE_ECC | The device supports hardware error correction. |
| TAPE_DRIVE_EJECT_MEDIA | The device ejects the media. |
| TAPE_DRIVE_EOT_WZ_SIZE | The device can report the end of zone warning size. |
| TAPE_DRIVE_ERASE_BOP_ONLY | The device performs the erase operation from the beginning-of-partition marker only. |
| TAPE_DRIVE_ERASE_IMMEDIATE | The device performs an immediate erase operation ?? that is, it returns when the erase operation begins. |
| TAPE_DRIVE_ERASE_LONG | The device performs a long erase operation. |
| TAPE_DRIVE_ERASE_SHORT | The device performs a short erase operation. |
| TAPE_DRIVE_FIXED | The device creates fixed data partitions. |
| TAPE_DRIVE_FIXED_BLOCK | The device supports fixed-length block mode. |
| TAPE_DRIVE_INITIATOR | The device creates initiator-defined partitions. |
| TAPE_DRIVE_GET_ABSOLUTE_BLK | The device provides the current device-specific block address. |
| TAPE_DRIVE_GET_LOGICAL_BLK | The device provides the current logical block address (and logical tape partition). |
| TAPE_DRIVE_PADDING | The device supports data padding. |
| TAPE_DRIVE_REPORT_SMKS | The device supports setmark reporting. |
| TAPE_DRIVE_RESERVED_BIT | A mask that identifies a reserved bit. Drivers must not set this bit. |
| TAPE_DRIVE_SELECT | The device creates select data partitions. |
| TAPE_DRIVE_SET_CMP_BOP_ONLY | The device only allows compression to be enabled when the read/write head is at the beginning of the partition. |
| TAPE_DRIVE_SET_EOT_WZ_SIZE | The device supports setting the end-of-medium warning size. |
| TAPE_DRIVE_TAPE_CAPACITY | The device returns the maximum capacity of the tape. |
| TAPE_DRIVE_TAPE_REMAINING | The device returns the remaining capacity of the tape. |
| TAPE_DRIVE_VARIABLE_BLOCK | The device supports variable-length block mode. |
| TAPE_DRIVE_WRITE_PROTECT | The device returns an error if the tape is write-enabled or write-protected. |

### `FeaturesHigh`

Indicates the additional features supported by this drive if TAPE_DRIVE_HIGH_FEATURES is set in **FeaturesLow**. The miniport driver sets TAPE_DRIVE_*XXX* flags for features supported by the drive and clears flags for features not supported. Callers can use the TAPE_DRIVE_*XXX* masks defined in *minitape.h* to determine whether a drive supports a particular feature.

| Mask | Meaning |
| --- | --- |
| TAPE_DRIVE_ABS_BLK_IMMED | The device moves the tape to a device-specific block address and returns as soon as the move begins. |
| TAPE_DRIVE_ABSOLUTE_BLK | The device moves the tape to a device specific block address. |
| TAPE_DRIVE_END_OF_DATA | The device moves the tape to the end-of-data marker in a partition. |
| TAPE_DRIVE_FILEMARKS | The device moves the tape forward (or backward) a specified number of filemarks. |
| TAPE_DRIVE_FORMAT | The device can format the media. |
| TAPE_DRIVE_FORMAT_IMMEDIATE | The device can format the media as an immediate command. |
| TAPE_DRIVE_HIGH_FEATURES | A bitmask that indicates those bits which correspond to high features. |
| TAPE_DRIVE_LOAD_UNLOAD | The device enables and disables the device for further operations. |
| TAPE_DRIVE_LOAD_UNLD_IMMED | The device supports immediate load and unload operations. |
| TAPE_DRIVE_LOCK_UNLOCK | The device enables and disables the tape ejection mechanism. |
| TAPE_DRIVE_LOCK_UNLK_IMMED | The device supports immediate lock and unlock operations. |
| TAPE_DRIVE_LOG_BLK_IMMED | The device moves the tape to a logical block address in a partition and returns as soon as the move begins. |
| TAPE_DRIVE_LOGICAL_BLK | The device moves the tape to a logical block address in a partition. |
| TAPE_DRIVE_RELATIVE_BLKS | The device moves the tape forward (or backward) a specified number of blocks. |
| TAPE_DRIVE_REVERSE_POSITION | The device moves the tape backward over blocks, filemarks, or setmarks. |
| TAPE_DRIVE_REWIND_IMMEDIATE | The device supports immediate rewind operation. |
| TAPE_DRIVE_SEQUENTIAL_FMKS | The device moves the tape forward (or backward) to the first occurrence of a specified number of consecutive filemarks. |
| TAPE_DRIVE_SEQUENTIAL_SMKS | The device moves the tape forward (or backward) to the first occurrence of a specified number of consecutive setmarks. |
| TAPE_DRIVE_SET_BLOCK_SIZE | The device supports setting the size of a fixed-length logical block or setting the variable-length block mode. |
| TAPE_DRIVE_SET_COMPRESSION | The device enables and disables hardware data compression. |
| TAPE_DRIVE_SET_ECC | The device enables and disables hardware error correction. |
| TAPE_DRIVE_SET_PADDING | The device enables and disables data padding. |
| TAPE_DRIVE_SET_REPORT_SMKS | The device enables and disables the reporting of setmarks. |
| TAPE_DRIVE_SETMARKS | The device moves the tape forward (or reverse) a specified number of setmarks. |
| TAPE_DRIVE_SPACE_IMMEDIATE | The device supports immediate spacing. |
| TAPE_DRIVE_TENSION | The device supports tape tensioning. |
| TAPE_DRIVE_TENSION_IMMED | The device supports immediate tape tensioning. |
| TAPE_DRIVE_WRITE_FILEMARKS | The device writes filemarks. |
| TAPE_DRIVE_WRITE_LONG_FMKS | The device writes long filemarks. |
| TAPE_DRIVE_WRITE_MARK_IMMED | The device supports immediate writing of short and long filemarks. |
| TAPE_DRIVE_WRITE_SETMARKS | The device writes setmarks. |
| TAPE_DRIVE_WRITE_SHORT_FMKS | The device writes short filemarks. |

### `EOTWarningZoneSize`

Indicates the size in bytes of the early warning zone toward the end of the tape. The device returns a check condition when it enters the zone.

## See also

[IOCTL_TAPE_GET_DRIVE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_get_drive_params)

[TapeMiniGetDriveParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)