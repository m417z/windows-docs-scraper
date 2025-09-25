## Description

**FILE_STAT_BASIC_INFORMATION** contains basic metadata about a file.

## Members

### `FileId`

Specifies the identifier of a file.

### `CreationTime`

Specifies the creation time of a file.

### `LastAccessTime`

Specifies the last time a file was accessed.

### `LastWriteTime`

Specifies the last time a file was written to.

### `ChangeTime`

Specifies the last time a file was changed.

### `AllocationSize`

File allocation size, in bytes. Usually this value is a multiple of the sector or cluster size of the underlying physical device.

### `EndOfFile`

The absolute new end-of-file position as a byte offset from the start of the file. **EndOfFile** specifies the byte offset to the end of the file. Because this value is zero-based, it actually refers to the first free byte in the file. In other words, **EndOfFile** is the offset to the byte immediately following the last valid byte in the file.

### `FileAttributes`

File attributes, which can be any valid combination of the following:

Attribute | Value
------------|------------
FILE_ATTRIBUTE_READONLY |0x00000001
FILE_ATTRIBUTE_HIDDEN |0x00000002
FILE_ATTRIBUTE_SYSTEM |0x00000004
FILE_ATTRIBUTE_DIRECTORY|0x00000010
FILE_ATTRIBUTE_ARCHIVE |0x00000020
FILE_ATTRIBUTE_NORMAL |0x00000080

### `ReparseTag`

Specifies the tag for a reparse point. See [About reparse points](https://learn.microsoft.com/windows-hardware/drivers/ifs/reparse-points) for more information.

### `NumberOfLinks`

Specifies the number of links to the file.

### `DeviceType`

Set when a driver calls [**IoCreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) as appropriate for the type of underlying device. For more information, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

### `DeviceCharacteristics`

The device characteristics. For a description of relevant values, see [**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `Reserved`

Reserved for system use.

### `VolumeSerialNumber`

Serial number of the volume where the file is located.

### `FileId128`

The 128-byte file reference number for the file. This number is generated and assigned to the file by the file system.

## Remarks

This information can be queried in either of the following ways:

* Call [**ZwQueryDirectoryFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwquerydirectoryfile), passing **FileStatBasicInformation** as the value of [**FileInformationClass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class) and passing a caller-allocated, **FILE_ID_EXTD_DIR_INFORMATION**-structured buffer as the value of **FileInformation**.

* Create an IRP with major function code [IRP_MJ_DIRECTORY_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control) and minor function code IRP_MN_QUERY_DIRECTORY.

No specific access rights are required to query this information.

File reference numbers, also called file IDs, are guaranteed to be unique only within a static file system. They are not guaranteed to be unique over time, because file systems are free to reuse them. Nor are they guaranteed to remain constant. For example, the FAT file system generates the file reference number for a file from the byte offset of the file's directory entry record (DIRENT) on the disk. Defragmentation can change this byte offset. Thus a FAT file reference number can change over time.

All dates and times are in absolute system-time format. Absolute system time is the number of 100-nanosecond intervals since the start of the year 1601.

This structure must be aligned on a LONGLONG (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry, except the last, falls on an 8-byte boundary.

## See also

[**FILE_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class)

[**ZwQueryInformationByName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryinformationbyname)