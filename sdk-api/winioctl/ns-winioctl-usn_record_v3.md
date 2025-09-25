# USN_RECORD_V3 structure

## Description

Contains the information for an update sequence number (USN) change journal version 3.0
record. The version 2.0 record is defined by the
[USN_RECORD_V2](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2) structure (also called
**USN_RECORD** structure).

## Members

### `RecordLength`

The total length of a record, in bytes.

Because **USN_RECORD_V3** is a variable size, the
**RecordLength** member should be used when calculating the address of the next record
in an output buffer, for example, a buffer that is returned from operations for the
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function that work with
**USN_RECORD_V3**.

The size in bytes of any change
journal record is at most the size of the **USN_RECORD_V3**
structure, plus *MaximumComponentLength* characters minus 1 (for the character declared
in the structure) times the size of a wide character. The value of
*MaximumComponentLength* may be determined by calling the
[GetVolumeInformation](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumeinformationa) function. In C, you can
determine a record size by using the following code example.

| C++ |
| --- |
| ```   MaximumChangeJournalRecordSize =        QuadAlign( (MaximumComponentLength - 1) * sizeof(WCHAR)         + sizeof(USN_RECORD_V3) ); ``` |

To maintain compatibility across version changes of the change journal software, use a run-time calculation
to determine the size of the **USN_RECORD_V3** structure. For
more information about compatibility across version changes, see the Remarks section in this topic.

### `MajorVersion`

The major version number of the change journal software for this record.

For example, if the change journal software is version 3.0, the major version number is 3.

| Value | Meaning |
| --- | --- |
| 2 | The structure is a [USN_RECORD_V2](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2) structure and the remainder of the structure should be parsed using that layout. |
| 3 | The structure is a **USN_RECORD_V3** structure and the remainder of the structure should be parsed using that layout. |
| 4 | The structure is a [USN_RECORD_V4 structure](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-usn_record_v4) and the remainder of the structure should be parsed using that layout. |

### `MinorVersion`

The minor version number of the change journal software for this record. For example, if the change journal
software is version 3.0, the minor version number is zero.

### `FileReferenceNumber`

The 128-bit ordinal number of the file or directory for which this record notes changes.

This is an arbitrarily assigned value that associates a journal record with a file.

### `ParentFileReferenceNumber`

The 128-bit ordinal number of the directory where the file or directory that is associated with this record
is located.

This is an arbitrarily assigned value that associates a journal record with a parent directory.

### `Usn`

The USN of this record.

### `TimeStamp`

The standard UTC time stamp ([FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)) of this
record, in 64-bit format.

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
| **USN_REASON_EA_CHANGE**<br><br>0x00000400 | The user made a change to the extended attributes of a file or directory. |
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
| **USN_REASON_RENAME_NEW_NAME**<br><br>0x00002000 | A file or directory is renamed, and the file name in the **USN_RECORD_V3** structure is the new name. |
| **USN_REASON_RENAME_OLD_NAME**<br><br>0x00001000 | The file or directory is renamed, and the file name in the **USN_RECORD_V3** structure is the previous name. |
| **USN_REASON_REPARSE_POINT_CHANGE**<br><br>0x00100000 | The reparse point that is contained in a file or directory is changed, or a reparse point is added to or deleted from a file or directory. |
| **USN_REASON_SECURITY_CHANGE**<br><br>0x00000800 | A change is made in the access rights to a file or directory. |
| **USN_REASON_STREAM_CHANGE**<br><br>0x00200000 | A named stream is added to or removed from a file, or a named stream is renamed. |
| **USN_REASON_TRANSACTED_CHANGE**<br><br>0x00400000 | The given stream is modified through a TxF transaction. |

### `SourceInfo`

Additional information about the source of the change, set by the
[FSCTL_MARK_HANDLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_mark_handle) of the
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) operation.

When a thread writes a new USN record, the source information flags in the prior record continues to be
present only if the thread also sets those flags. Therefore, the source information structure allows
applications to filter out USN records that are set only by a known source, for example, an antivirus filter.

One of the two following values can be set.

| Value | Meaning |
| --- | --- |
| **USN_SOURCE_AUXILIARY_DATA**<br><br>0x00000002 | The operation adds a private data stream to a file or directory.<br><br>An example might be a virus detector adding checksum information. As the virus detector modifies the item, the system generates USN records. **USN_SOURCE_AUXILIARY_DATA** indicates that the modifications did not change the application data. |
| **USN_SOURCE_DATA_MANAGEMENT**<br><br>0x00000001 | The operation provides information about a change to the file or directory made by the operating system.<br><br>A typical use is when the Remote Storage system moves data from external to local storage. Remote Storage is the hierarchical storage management software. Such a move usually at a minimum adds the **USN_REASON_DATA_OVERWRITE** flag to a USN record. However, the data has not changed from the user's point of view. By noting **USN_SOURCE_DATA_MANAGEMENT** in the **SourceInfo** member, you can determine that although a write operation is performed on the item, data has not changed. |
| **USN_SOURCE_REPLICATION_MANAGEMENT**<br><br>0x00000004 | The operation is modifying a file to match the contents of the same file which exists in another member of the replica set. |
| **USN_SOURCE_CLIENT_REPLICATION_MANAGEMENT**<br><br>0x00000008 | The operation is modifying a file on client systems to match the contents of the same file that exists in the cloud. |

### `SecurityId`

The unique security identifier assigned to the file or directory associated with this record.

### `FileAttributes`

The attributes for the file or directory associated with this record, as returned by the
[GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa) function. Attributes of streams
associated with the file or directory are excluded.

### `FileNameLength`

The length of the name of the file or directory associated with this record, in bytes. The
**FileName** member contains this name. Use this member to determine file name length,
rather than depending on a trailing '\0' to delimit the file name in **FileName**.

### `FileNameOffset`

The offset of the **FileName** member from the beginning of the structure.

### `FileName`

The name of the file or directory associated with this record in Unicode format. This file or directory name
is of variable length.

When working with **FileName**, do not count on the file name that contains a trailing
'\0' delimiter, but instead determine the length of the file name by using
**FileNameLength**.

Do not perform any compile-time pointer arithmetic using **FileName**. Instead, make
necessary calculations at run time by using the value of the **FileNameOffset** member.
Doing so helps make your code compatible with any future versions of
**USN_RECORD_V3**.

## Remarks

In output buffers returned from [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)
operations that work with **USN_RECORD_V3**, all records are
aligned on 64-bit boundaries from the start of the buffer.

When range tracking is turned on, NTFS switches to producing only **USN_RECORD_V3** records as output.

To provide a path for upward compatibility in change journal clients, Microsoft provides a major and minor
version number of the change journal software in the
**USN_RECORD_V3** structure. Your code should examine these
values, detect its own compatibility with the change journal software, and if necessary gracefully handle any
incompatibility.

A change in the minor version number indicates that the existing
**USN_RECORD_V3** structure members are still valid, but that new
members may have been added between the penultimate member and the last, which is a variable-length string.

To handle such a change gracefully, your code should not do any compile-time pointer arithmetic that relies on
the location of the last member. For example, this makes the C code
`sizeof(USN_RECORD)` unreliable. Instead, rely on run-time calculations by
using the **RecordLength** member.

An increase in the major version number of the change journal software indicates that the
**USN_RECORD_V3** structure may have undergone major changes, and
that the current definition may not be reliable. If your code detects a change in the major version number of the
change journal software, it should not work with the change journal.

For more information, see
[Creating, Modifying, and Deleting a Change Journal](https://learn.microsoft.com/windows/desktop/FileIO/creating-modifying-and-deleting-a-change-journal).

## See also

[FSCTL_MARK_HANDLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_mark_handle)

[FSCTL_READ_USN_JOURNAL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_read_usn_journal)

[GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa)

[GetVolumeInformation](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumeinformationa)

[READ_USN_JOURNAL_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-read_usn_journal_data_v0)

[USN_RECORD_V2](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2)

[USN_RECORD_V4 structure](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-usn_record_v4)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)