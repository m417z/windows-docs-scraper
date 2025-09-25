# TAPE_GET_DRIVE_PARAMETERS structure

## Description

The
**TAPE_GET_DRIVE_PARAMETERS** structure describes the tape drive. It is used by the [GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters) function.

## Members

### `ECC`

If this member is **TRUE**, the device supports hardware error correction. Otherwise, it does not.

### `Compression`

If this member is **TRUE**, hardware data compression is enabled. Otherwise, it is disabled.

### `DataPadding`

If this member is **TRUE**, data padding is enabled. Otherwise, it is disabled. Data padding keeps the tape streaming at a constant speed.

### `ReportSetmarks`

If this member is **TRUE**, setmark reporting is enabled. Otherwise, it is disabled.

### `DefaultBlockSize`

Device's default fixed block size, in bytes.

### `MaximumBlockSize`

Device's maximum block size, in bytes.

### `MinimumBlockSize`

Device's minimum block size, in bytes.

### `MaximumPartitionCount`

Maximum number of partitions that can be created on the device.

### `FeaturesLow`

Low-order bits of the device features flag. This member can be one or more of following values.

| Value | Meaning |
| --- | --- |
| **TAPE_DRIVE_COMPRESSION**<br><br>0x00020000 | The device supports hardware data compression. |
| **TAPE_DRIVE_CLEAN_REQUESTS**<br><br>0x02000000 | The device can report if cleaning is required. |
| **TAPE_DRIVE_ECC**<br><br>0x00010000 | The device supports hardware error correction. |
| **TAPE_DRIVE_EJECT_MEDIA**<br><br>0x01000000 | The device physically ejects the tape on a software eject. |
| **TAPE_DRIVE_ERASE_BOP_ONLY**<br><br>0x00000040 | The device performs the erase operation from the beginning-of-partition marker only. |
| **TAPE_DRIVE_ERASE_LONG**<br><br>0x00000020 | The device performs a long erase operation. |
| **TAPE_DRIVE_ERASE_IMMEDIATE**<br><br>0x00000080 | The device performs an immediate erase operation — that is, it returns when the erase operation begins. |
| **TAPE_DRIVE_ERASE_SHORT**<br><br>0x00000010 | The device performs a short erase operation. |
| **TAPE_DRIVE_FIXED**<br><br>0x00000001 | The device creates fixed data partitions. |
| **TAPE_DRIVE_FIXED_BLOCK**<br><br>0x00000400 | The device supports fixed-length block mode. |
| **TAPE_DRIVE_GET_ABSOLUTE_BLK**<br><br>0x00100000 | The device provides the current device-specific block address. |
| **TAPE_DRIVE_GET_LOGICAL_BLK**<br><br>0x00200000 | The device provides the current logical block address (and logical tape partition). |
| **TAPE_DRIVE_INITIATOR**<br><br>0x00000004 | The device creates initiator-defined partitions. |
| **TAPE_DRIVE_PADDING**<br><br>0x00040000 | The device supports data padding. |
| **TAPE_DRIVE_REPORT_SMKS**<br><br>0x00080000 | The device supports setmark reporting. |
| **TAPE_DRIVE_SELECT**<br><br>0x00000002 | The device creates select data partitions. |
| **TAPE_DRIVE_SET_CMP_BOP_ONLY**<br><br>0x04000000 | The device must be at the beginning of a partition before it can set compression on. |
| **TAPE_DRIVE_SET_EOT_WZ_SIZE**<br><br>0x00400000 | The device supports setting the end-of-medium warning size. |
| **TAPE_DRIVE_TAPE_CAPACITY**<br><br>0x00000100 | The device returns the maximum capacity of the tape. |
| **TAPE_DRIVE_TAPE_REMAINING**<br><br>0x00000200 | The device returns the remaining capacity of the tape. |
| **TAPE_DRIVE_VARIABLE_BLOCK**<br><br>0x00000800 | The device supports variable-length block mode. |
| **TAPE_DRIVE_WRITE_PROTECT**<br><br>0x00001000 | The device returns an error if the tape is write-enabled or write-protected. |

### `FeaturesHigh`

High-order bits of the device features flag. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **TAPE_DRIVE_ABS_BLK_IMMED**<br><br>0x80002000 | The device moves the tape to a device-specific block address and returns as soon as the move begins. |
| **TAPE_DRIVE_ABSOLUTE_BLK**<br><br>0x80001000 | The device moves the tape to a device specific block address. |
| **TAPE_DRIVE_END_OF_DATA**<br><br>0x80010000 | The device moves the tape to the end-of-data marker in a partition. |
| **TAPE_DRIVE_FILEMARKS**<br><br>0x80040000 | The device moves the tape forward (or backward) a specified number of filemarks. |
| **TAPE_DRIVE_LOAD_UNLOAD**<br><br>0x80000001 | The device enables and disables the device for further operations. |
| **TAPE_DRIVE_LOAD_UNLD_IMMED**<br><br>0x80000020 | The device supports immediate load and unload operations. |
| **TAPE_DRIVE_LOCK_UNLOCK**<br><br>0x80000004 | The device enables and disables the tape ejection mechanism. |
| **TAPE_DRIVE_LOCK_UNLK_IMMED**<br><br>0x80000080 | The device supports immediate lock and unlock operations. |
| **TAPE_DRIVE_LOG_BLK_IMMED**<br><br>0x80008000 | The device moves the tape to a logical block address in a partition and returns as soon as the move begins. |
| **TAPE_DRIVE_LOGICAL_BLK**<br><br>0x80004000 | The device moves the tape to a logical block address in a partition. |
| **TAPE_DRIVE_RELATIVE_BLKS**<br><br>0x80020000 | The device moves the tape forward (or backward) a specified number of blocks. |
| **TAPE_DRIVE_REVERSE_POSITION**<br><br>0x80400000 | The device moves the tape backward over blocks, filemarks, or setmarks. |
| **TAPE_DRIVE_REWIND_IMMEDIATE**<br><br>0x80000008 | The device supports immediate rewind operation. |
| **TAPE_DRIVE_SEQUENTIAL_FMKS**<br><br>0x80080000 | The device moves the tape forward (or backward) to the first occurrence of a specified number of consecutive filemarks. |
| **TAPE_DRIVE_SEQUENTIAL_SMKS**<br><br>0x80200000 | The device moves the tape forward (or backward) to the first occurrence of a specified number of consecutive setmarks. |
| **TAPE_DRIVE_SET_BLOCK_SIZE**<br><br>0x80000010 | The device supports setting the size of a fixed-length logical block or setting the variable-length block mode. |
| **TAPE_DRIVE_SET_COMPRESSION**<br><br>0x80000200 | The device enables and disables hardware data compression. |
| **TAPE_DRIVE_SET_ECC**<br><br>0x80000100 | The device enables and disables hardware error correction. |
| **TAPE_DRIVE_SET_PADDING**<br><br>0x80000400 | The device enables and disables data padding. |
| **TAPE_DRIVE_SET_REPORT_SMKS**<br><br>0x80000800 | The device enables and disables the reporting of setmarks. |
| **TAPE_DRIVE_SETMARKS**<br><br>0x80100000 | The device moves the tape forward (or reverse) a specified number of setmarks. |
| **TAPE_DRIVE_SPACE_IMMEDIATE**<br><br>0x80800000 | The device supports immediate spacing. |
| **TAPE_DRIVE_TENSION**<br><br>0x80000002 | The device supports tape tensioning. |
| **TAPE_DRIVE_TENSION_IMMED**<br><br>0x80000040 | The device supports immediate tape tensioning. |
| **TAPE_DRIVE_WRITE_FILEMARKS**<br><br>0x82000000 | The device writes filemarks. |
| **TAPE_DRIVE_WRITE_LONG_FMKS**<br><br>0x88000000 | The device writes long filemarks. |
| **TAPE_DRIVE_WRITE_MARK_IMMED**<br><br>0x90000000 | The device supports immediate writing of short and long filemarks. |
| **TAPE_DRIVE_WRITE_SETMARKS**<br><br>0x81000000 | The device writes setmarks. |
| **TAPE_DRIVE_WRITE_SHORT_FMKS**<br><br>0x84000000 | The device writes short filemarks. |

### `EOTWarningZoneSize`

Indicates the number of bytes between the end-of-tape warning and the physical end of the tape.

## See also

[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters)