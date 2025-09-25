# FSCTL_SET_INTEGRITY_INFORMATION_BUFFER structure

## Description

Input buffer passed with the
[FSCTL_SET_INTEGRITY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_integrity_information) control
code.

## Members

### `ChecksumAlgorithm`

Specifies the checksum algorithm.

| Value | Meaning |
| --- | --- |
| **CHECKSUM_TYPE_NONE**<br><br>0x0000 | The file or directory is not configured to use integrity. |
| **CHECKSUM_TYPE_CRC64**<br><br>0x0002 | The file or directory uses a CRC64 checksum to provide integrity. |
| 3–0xfffe | Reserved for future use. Must not be used. |
| **CHECKSUM_TYPE_UNCHANGED**<br><br>0xffff | The checksum algorithm is to remain the same. |

### `Reserved`

Must be 0

### `Flags`

Contains zero or more flags.

| Value | Meaning |
| --- | --- |
| **FSCTL_INTEGRITY_FLAG_CHECKSUM_ENFORCEMENT_OFF**<br><br>0x00000001 | If set, the checksum enforcement is disabled and reads will succeed even if the checksums do not match. This flag is valid only if the file has an integrity algorithm set. If there is no algorithm set or the **CheckSum** member is set to **CHECKSUM_TYPE_NONE**, then the operation fails with **ERROR_INVALID_PARAMETER**. |

## Remarks

If **FSCTL_INTEGRITY_FLAG_CHECKSUM_ENFORCEMENT_OFF** is specified and the file is opened
with sharing permissions such that subsequent opens can succeed, it's possible for corrupt data to be read by an
application that did not specify **FSCTL_INTEGRITY_FLAG_CHECKSUM_ENFORCEMENT_OFF**.

## See also

[FSCTL_GET_INTEGRITY_INFORMATION_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-fsctl_get_integrity_information_buffer)

[FSCTL_SET_INTEGRITY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_integrity_information)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)