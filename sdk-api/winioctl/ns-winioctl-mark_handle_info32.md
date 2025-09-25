# MARK_HANDLE_INFO32 structure

## Description

Contains information that is used to mark a specified file or directory, and its update sequence number (USN) change journal record with data about changes. This is only defined for 64-bit code and exists to interpret [MARK_HANDLE_INFO structures](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-mark_handle_info) sent by 32-bit code. It is used by the [FSCTL_MARK_HANDLE IOCTL](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_mark_handle) control code.

## Members

### `DUMMYUNIONNAME`

### `UsnSourceInfo`

The type of changes being made.

The operation does not modify the file or directory externally from the point of view of the application that created it.

When a thread writes a new USN record, the source information flags in the prior record continues to be present only if the thread also sets those flags. Therefore, the source information structure allows applications to filter out USN records that are set only by a known source, such as an antivirus filter.

The following values are defined.

| Value | Meaning |
| --- | --- |
| **USN_SOURCE_DATA_MANAGEMENT**<br><br>0x00000001 | The operation provides information about a change to the file or directory made by the operating system.<br><br>A typical use is when Remote Storage moves data from external to local storage. Remote Storage is the hierarchical storage management software. Such a move usually at a minimum adds the **USN_REASON_DATA_OVERWRITE** flag to a USN record. However, the data has not changed from the user point of view. By noting **USN_SOURCE_DATA_MANAGEMENT** in the **SourceInfo** member of the [USN_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2) structure that holds the record, you can determine that although a write operation is performed on the item, data has not changed. |
| **USN_SOURCE_AUXILIARY_DATA**<br><br>0x00000002 | The operation adds a private data stream to a file or directory.<br><br>An example might be a virus detector adding checksum information. As the virus detector modifies the item, the system generates USN records. **USN_SOURCE_AUXILIARY_DATA** indicates that the modifications did not change the application data. |
| **USN_SOURCE_REPLICATION_MANAGEMENT**<br><br>0x00000004 | The operation creates or updates the contents of a replicated file.<br><br>For example, the file replication service sets this flag when it creates or updates a file in a replicated directory. |

### `CopyNumber`

### `VolumeHandle`

The volume handle to the volume where the file or directory resides. For more information on obtaining a
volume handle, see the Remarks section.

This handle is required to check the privileges for this operation.

The caller must have the **SE_MANAGE_VOLUME_NAME** privilege. For more information,
see [Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges).

### `HandleInfo`

The flag that specifies additional information about the file or directory identified by the handle value
in the **VolumeHandle** member.

| Value | Meaning |
| --- | --- |
| **MARK_HANDLE_PROTECT_CLUSTERS**<br><br>0x00000001 | The file is marked as unable to be defragmented until the handle is closed. |
| **MARK_HANDLE_TXF_SYSTEM_LOG**<br><br>0x00000004 | The file is marked as unable to be defragmented until the handle is closed. |
| **MARK_HANDLE_NOT_TXF_SYSTEM_LOG**<br><br>0x00000008 | The file is marked as unable to be defragmented until the handle is closed. |
| **MARK_HANDLE_REALTIME**<br><br>0x00000020 | The file is marked for real-time read behavior regardless of the actual file type. Files marked with this flag must be opened for [unbuffered I/O](https://learn.microsoft.com/windows/desktop/FileIO/file-buffering). |
| **MARK_HANDLE_NOT_REALTIME**<br><br>0x00000040 | The file previously marked for real-time read behavior using the **MARK_HANDLE_REALTIME** flag can be unmarked using this flag, removing the real-time behavior. Files marked with this flag must be opened for [unbuffered I/O](https://learn.microsoft.com/windows/desktop/FileIO/file-buffering). |