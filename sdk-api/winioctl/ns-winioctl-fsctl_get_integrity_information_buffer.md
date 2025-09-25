# FSCTL_GET_INTEGRITY_INFORMATION_BUFFER structure

## Description

Contains the integrity information for a file or directory. Returned from the [FSCTL_GET_INTEGRITY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_integrity_information) control code.

## Members

### `ChecksumAlgorithm`

The checksum algorithm used.

| Value | Meaning |
| --- | --- |
| **CHECKSUM_TYPE_NONE**<br><br>0x0000 | The file or directory is not configured to use integrity. |
| **CHECKSUM_TYPE_CRC64**<br><br>0x0002 | The file or directory uses a CRC64 checksum to provide integrity. |
| 3–0xffff | Reserved for future use. |

### `Reserved`

Reserved for future use. Set to 0.

### `Flags`

Contains one or more flags.

| Value | Meaning |
| --- | --- |
| **FSCTL_INTEGRITY_FLAG_CHECKSUM_ENFORCEMENT_OFF**<br><br>0x00000001 | If set, the checksum enforcement is disabled. |

### `ChecksumChunkSizeInBytes`

Size in bytes of the chunks used to calculate checksums.

### `ClusterSizeInBytes`

Size in bytes of a cluster for this volume. This value must be a power of 2, must be greater than or equal
to the sector size of the underlying hardware and must be a power of 2 multiple of the sector size.

## See also

[FSCTL_GET_INTEGRITY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_integrity_information)

[FSCTL_SET_INTEGRITY_INFORMATION_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-fsctl_set_integrity_information_buffer)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)