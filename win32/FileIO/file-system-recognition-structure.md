# FILE\_SYSTEM\_RECOGNITION\_STRUCTURE structure

Contains the on-disk file system recognition information stored in the volume's boot sector (logical disk sector zero).

This is an internally-defined data structure not available in a public header and is provided here for file system developers who want to take advantage of file system recognition. For more information, see [File System Recognition](https://learn.microsoft.com/windows/win32/fileio/file-system-recognition).

## Members

**Jmp**

The JMP instruction. This data member is not included in the value contained in the **Checksum** data member.

**FsName**

The file system name. This is a sequence of 8 ASCII characters that represents the nonlocalizable human-readable name of the file system the volume is formatted with.

This string is in the same place as the OEM file system name on a disk with a normal BIOS parameter block (BPB) structure.

**MustBeZero**

Reserved space that contains all zeros.

This data member overlaps what normally are the following data members in a BPB:

- **BytesPerSector**
- **SectorsPerCluster**
- **ReservedSectorCount**

Because these data members are set to zero, this should be sufficient to cause earlier OSs to conclude that this is not a valid BPB and therefore recognize the volume.

**Identifier**

A structure identifier. Must contain the value 0x53525346 arranged in little-endian byte order.

At this point in the structure, the data is aligned to 16 bytes.

**Length**

The number of bytes in this structure, from the beginning to the end, including the **Jmp** data member.

**Checksum**

A two-byte checksum calculated over the bytes starting at the **FsName** data member and ending at the last byte of this structure, excluding the **Jmp** and **Checksum** data members.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |

## See also

[Computing a File System Recognition Checksum](https://learn.microsoft.com/windows/win32/fileio/computing-a-file-system-recognition-checksum)

[File System Recognition](https://learn.microsoft.com/windows/win32/fileio/file-system-recognition)

[**FILE\_SYSTEM\_RECOGNITION\_INFORMATION**](https://learn.microsoft.com/windows/desktop/api/WinIoCtl/ns-winioctl-file_system_recognition_information)

[**FSCTL\_QUERY\_FILE\_SYSTEM\_RECOGNITION**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_query_file_system_recognition)

