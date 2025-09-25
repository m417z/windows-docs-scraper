# USN_RECORD_V4 structure

## Description

Contains the information for an update sequence number (USN) change journal version 4.0 record. The version 2.0 and 3.0 records are defined by the [USN_RECORD_V2](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2) (also called **USN_RECORD**) and [USN_RECORD_V3](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v3) structures respectively.

## Members

### `Header`

A [USN_RECORD_COMMON_HEADER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_common_header) structure that describes the record length, major version, and minor version for the record.

### `FileReferenceNumber`

The 128-bit ordinal number of the file or directory for which this record notes changes.

This value is an arbitrarily assigned value that associates a journal record with a file.

### `ParentFileReferenceNumber`

The 128-bit ordinal number of the directory where the file or directory that is associated with this record
is located.

This value is an arbitrarily assigned value that associates a journal record with a parent directory.

### `Usn`

The USN of this record.

### `Reason`

The flags that identify reasons for changes that have accumulated in this file or directory journal record
since the file or directory opened.

When a file or directory closes, then a final USN record is generated with the
**USN_REASON_CLOSE** flag set. The next change (for example, after the next open
operation or deletion) starts a new record with a new set of reason flags.

A rename or move operation generates two USN records, one that records the old parent directory for the item,
and one that records a new parent.

The following table identifies the possible flags.

**Note** Unused bits are reserved.

| Value | Meaning |
| --- | --- |
| **USN_REASON_BASIC_INFO_CHANGE**<br><br>0x00008000 | A user has either changed one or more file or directory attributes (for example, the read-only, hidden, system, archive, or sparse attribute), or one or more time stamps. |
| **USN_REASON_CLOSE**<br><br>0x80000000 | The file or directory is closed. |
| **USN_REASON_COMPRESSION_CHANGE**<br><br>0x00020000 | The compression state of the file or directory is changed from or to compressed. |
| **USN_REASON_DATA_EXTEND**<br><br>0x00000002 | The file or directory is extended (added to). |
| **USN_REASON_DATA_OVERWRITE**<br><br>0x00000001 | The data in the file or directory is overwritten. |
| **USN_REASON_DATA_TRUNCATION**<br><br>0x00000004 | The file or directory is truncated. |
| **USN_REASON_EA_CHANGE**<br><br>0x00000400 | The user made a change to the extended attributes of a file or directory.<br><br>These NTFS file system attributes are not accessible to Windows-based applications. |
| **USN_REASON_ENCRYPTION_CHANGE**<br><br>0x00040000 | The file or directory is encrypted or decrypted. |
| **USN_REASON_FILE_CREATE**<br><br>0x00000100 | The file or directory is created for the first time. |
| **USN_REASON_FILE_DELETE**<br><br>0x00000200 | The file or directory is deleted. |
| **USN_REASON_HARD_LINK_CHANGE**<br><br>0x00010000 | An NTFS file system hard link is added to or removed from the file or directory.<br><br>An NTFS file system hard link, similar to a POSIX hard link, is one of several directory entries that see the same file or directory. |
| **USN_REASON_INDEXABLE_CHANGE**<br><br>0x00004000 | A user changes the **FILE_ATTRIBUTE_NOT_CONTENT_INDEXED** attribute.<br><br>That is, the user changes the file or directory from one where content can be indexed to one where content cannot be indexed, or vice versa. Content indexing permits rapid searching of data by building a database of selected content. |
| **USN_REASON_INTEGRITY_CHANGE**<br><br>0x00800000 | A user changed the state of the **FILE_ATTRIBUTE_INTEGRITY_STREAM** attribute for the given stream.<br><br>On the ReFS file system, integrity streams maintain a checksum of all data for that stream, so that the contents of the file can be validated during read or write operations. |
| **USN_REASON_NAMED_DATA_EXTEND**<br><br>0x00000020 | The one or more named data streams for a file are extended (added to). |
| **USN_REASON_NAMED_DATA_OVERWRITE**<br><br>0x00000010 | The data in one or more named data streams for a file is overwritten. |
| **USN_REASON_NAMED_DATA_TRUNCATION**<br><br>0x00000040 | The one or more named data streams for a file is truncated. |
| **USN_REASON_OBJECT_ID_CHANGE**<br><br>0x00080000 | The object identifier of a file or directory is changed. |
| **USN_REASON_RENAME_NEW_NAME**<br><br>0x00002000 | A file or directory is renamed, and the file name in the **USN_RECORD_V4** structure is the new name. |
| **USN_REASON_RENAME_OLD_NAME**<br><br>0x00001000 | The file or directory is renamed, and the file name in the **USN_RECORD_V4** structure is the previous name. |
| **USN_REASON_REPARSE_POINT_CHANGE**<br><br>0x00100000 | The reparse point that is contained in a file or directory is changed, or a reparse point is added to or deleted from a file or directory. |
| **USN_REASON_SECURITY_CHANGE**<br><br>0x00000800 | A change is made in the access rights to a file or directory. |
| **USN_REASON_STREAM_CHANGE**<br><br>0x00200000 | A named stream is added to or removed from a file, or a named stream is renamed. |
| **USN_REASON_TRANSACTED_CHANGE**<br><br>0x00400000 | The given stream is modified through a committed TxF transaction. |

### `SourceInfo`

Additional information about the source of the change, set by the
[FSCTL_MARK_HANDLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_mark_handle) of the
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) operation.

When a thread writes a new USN record, the source information flags in the prior record continue to be
present only if the thread also sets those flags. Therefore, the source information structure allows
applications to filter out USN records that are set only by a known source, for example, an antivirus filter.

One of the following values can be set.

| Value | Meaning |
| --- | --- |
| **USN_SOURCE_AUXILIARY_DATA**<br><br>0x00000002 | The operation adds a private data stream to a file or directory.<br><br>One example is a virus detector adding checksum information. As the virus detector modifies the item, the system generates USN records. **USN_SOURCE_AUXILIARY_DATA** indicates that the modifications did not change the application data. |
| **USN_SOURCE_DATA_MANAGEMENT**<br><br>0x00000001 | The operation provides information about a change to the file or directory made by the operating system.<br><br>A typical use is when the Remote Storage system moves data from external to local storage. Remote Storage is the hierarchical storage management software. Such a move usually at a minimum adds the **USN_REASON_DATA_OVERWRITE** flag to a USN record. However, the data has not changed from the user's point of view. By noting **USN_SOURCE_DATA_MANAGEMENT** in the **SourceInfo** member, you can determine that although a write operation is performed on the item, data has not changed. |
| **USN_SOURCE_REPLICATION_MANAGEMENT**<br><br>0x00000004 | The operation is modifying a file to match the contents of the same file which exists in another member of the replica set. |
| **USN_SOURCE_CLIENT_REPLICATION_MANAGEMENT**<br><br>0x00000008 | The operation is modifying a file on client systems to match the contents of the same file that exists in the cloud. |

### `RemainingExtents`

The number of extents that remain after the current **USN_RECORD_V4** record. Multiple version 4.0 records may be required to describe all of the modified extents for a given file. When the **RemainingExtents** member is 0, the current **USN_RECORD_V4** record is the last **USN_RECORD_V4** record for the file. The last **USN_RECORD_V4** entry for a given file is always followed by a [USN_RECORD_V3](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v3) record with at least the **USN_REASON_CLOSE** flag set.

### `NumberOfExtents`

The number of extents in current **USN_RECORD_V4** entry.

### `ExtentSize`

The size of each [USN_RECORD_EXTENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_extent) structure in the **Extents** member, in bytes.

### `Extents`

An array of [USN_RECORD_EXTENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_extent) structures that represent the extents in the **USN_RECORD_V4** entry.

## Remarks

A **USN_RECORD_V4** record is only output when range tracking is turned on and the file size is equal or larger than the value of the **RangeTrackFileSizeThreshold** member. The user always receives one or more **USN_RECORD_V4** records followed by one [USN_RECORD_V3](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v3) record.

To provide a path forward compatibility in change journal clients, Microsoft provides a major and minor version number of the change journal software in the **USN_RECORD_V4** structure. Your code should examine these values, examine its own compatibility with the change journal software, and gracefully handle any incompatibility if necessary.

A change in the minor version number indicates that the existing **USN_RECORD_V4** structure members are still valid, but that new members may have been added between the penultimate member and the last, which is a variable-length string.

To handle such a change gracefully, your code should not do any compile-time pointer arithmetic that relies on the location of the last member. For example, a change in the minor version number makes the `sizeof(USN_RECORD)` call unreliable. Instead, rely on run-time calculations that use the **RecordLength** member.

An increase in the major version number of the change journal software indicates that the **USN_RECORD_V4** structure may have undergone major changes, and that the current definition may not be reliable. If your code detects a change in the major version number of the change journal software, the code should not work with the change journal.

For more information, see [Creating, Modifying, and Deleting a Change Journal](https://learn.microsoft.com/windows/desktop/FileIO/creating-modifying-and-deleting-a-change-journal).

## See also

[FSCTL_MARK_HANDLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_mark_handle)

[FSCTL_READ_USN_JOURNAL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_read_usn_journal)

[FSCTL_USN_TRACK_MODIFIED_RANGES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_usn_track_modified_ranges)

[GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa)

[GetVolumeInformation](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumeinformationa)

[READ_USN_JOURNAL_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-read_usn_journal_data_v0)

[USN_RECORD_COMMON_HEADER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_common_header)

[USN_RECORD_EXTENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_extent)

[USN_RECORD_V2](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2)

[USN_RECORD_V3](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v3)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)