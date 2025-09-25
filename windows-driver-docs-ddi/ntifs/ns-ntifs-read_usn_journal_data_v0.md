## Description

The **READ_USN_JOURNAL_DATA_V0** structure contains information defining a set of update sequence number (USN) change journal records to return to the calling process. It is used by the [**FSCTL_QUERY_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_usn_journal) and [**FSCTL_READ_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_read_usn_journal) control codes. Prior to Windows 8 and Windows Server 2012 this structure was named **READ_USN_JOURNAL_DATA**. Windows Server 2012 introduced [**READ_USN_JOURNAL_DATA_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-read_usn_journal_data_v1) to support 128-bit file identifiers used by ReFS.

## Members

### `StartUsn`

The USN at which to begin reading the change journal.

To start the read operation at the first record in the journal, set the **StartUsn** member to zero. Because a USN is contained in every journal record, the output buffer tells at which record the read operation actually started.

To start the read operation at a specific record, set **StartUsn** to that record USN.

If a nonzero USN is specified that is less than the first USN in the change journal, then an error occurs and the ERROR_JOURNAL_ENTRY_DELETED error code is returned. This code may indicate a case in which the specified USN is valid at one time but has since been deleted.

For more information on navigating the change journal buffer returned in **READ_USN_JOURNAL_DATA_V0**, see [Walking a Buffer of Change Journal Records](https://learn.microsoft.com/windows/win32/fileio/walking-a-buffer-of-change-journal-records).

### `ReasonMask`

A mask of flags, each flag noting a change for which the file or directory has a record in the change journal. To be returned in a [**FSCTL_READ_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_read_usn_journal) operation, a change journal record must have at least one of these flags set.

The list of valid flags is as follows. Unused bits are reserved.

| Value | Meaning |
| ----- | ------- |
| USN_REASON_BASIC_INFO_CHANGE (0x00008000) | A user has either changed one or more file or directory attributes (such as the read-only, hidden, system, archive, or sparse attribute), or one or more time stamps. |
| USN_REASON_CLOSE (0x80000000) | The file or directory is closed. |
| USN_REASON_COMPRESSION_CHANGE (0x00020000) | The compression state of the file or directory is changed from or to compressed. |
| USN_REASON_DATA_EXTEND (0x00000002) | The file or directory is added to. |
| USN_REASON_DATA_OVERWRITE (0x00000001) | Data in the file or directory is overwritten. |
| USN_REASON_DATA_TRUNCATION (0x00000004) | The file or directory is truncated. |
| USN_REASON_EA_CHANGE (0x00000400) | The user makes a change to the file or directory extended attributes. These NTFS file system attributes are not accessible to Windows-based applications. |
| USN_REASON_ENCRYPTION_CHANGE (0x00040000) | The file or directory is encrypted or decrypted. |
| USN_REASON_FILE_CREATE (0x00000100) | The file or directory is created for the first time. |
| USN_REASON_FILE_DELETE (0x00000200) | The file or directory is deleted. |
| USN_REASON_HARD_LINK_CHANGE (0x00010000) | An NTFS file system hard link is added to or removed from the file or directory. An NTFS file system hard link, similar to a POSIX hard link, is one of several directory entries that see the same file or directory. |
| USN_REASON_INDEXABLE_CHANGE (0x00004000) | A user changed the FILE_ATTRIBUTE_NOT_CONTENT_INDEXED attribute. That is, the user changed the file or directory from one that can be content indexed to one that cannot, or vice versa. (Content indexing permits rapid searching of data by building a database of selected content.) |
| USN_REASON_NAMED_DATA_EXTEND (0x00000020) | One or more named data streams for the file were added to. |
| USN_REASON_NAMED_DATA_OVERWRITE (0x00000010) | Data in one or more named data streams for the file is overwritten. |
| USN_REASON_NAMED_DATA_TRUNCATION (0x00000040) | One or more named data streams for the file is truncated. |
| USN_REASON_OBJECT_ID_CHANGE (0x00080000) | The object identifier of the file or directory is changed. |
| USN_REASON_RENAME_NEW_NAME (0x00002000) | The file or directory is renamed, and the file name in the USN_RECORD_V2 or USN_RECORD_V3 structure holding this journal record is the new name. |
| USN_REASON_RENAME_OLD_NAME (0x00001000) | The file or directory is renamed, and the file name in the USN_RECORD_V2 or USN_RECORD_V3 structure holding this journal record is the previous name. |
| USN_REASON_REPARSE_POINT_CHANGE (0x00100000) | The reparse point contained in the file or directory is changed, or a reparse point is added to or deleted from the file or directory. |
| USN_REASON_SECURITY_CHANGE (0x00000800) | A change is made in the access permissions to the file or directory. |
| USN_REASON_STREAM_CHANGE (0x00200000) | A named stream is added to or removed from the file or directory, or a named stream is renamed. |

### `ReturnOnlyOnClose`

A value that specifies when to return change journal records.

To receive notification when the final handle for the changed file or directory is closed, rather than at the time a change occurs, set **ReturnOnlyOnClose** to any nonzero value and specify the USN_REASON_CLOSE flag in the **ReasonMask** member.

All changes indicated by **ReasonMask** flags eventually generate a call to the change journal software when the file is closed. If your call is waiting for the file to be closed, that call in turn will allow your call to return. In the event that a file or directory is not closed prior to a volume failure, operating system failure, or shutdown, a cleanup call to the change journal software occurs the next time the volume is mounted. The call occurs even if there is an intervening system restart.

To receive notification the first time each change is logged, as well as at cleanup, set **ReturnOnlyOnClose** to zero.

Whether **ReturnOnlyOnClose** is zero or nonzero, the records generated at cleanup log within the change journal all reasons for USN changes that occurred to the file or directory. Each time a final close operation occurs for an item, a USN close record is written to the change journal, and the ReasonMask flags for the item are all reset.

For a file or directory for which no user data exists (for example, a mounted folder), the final close operation occurs when the CloseHandle function is called on the last user handle to the item.

### `Timeout`

The time-out value, in seconds, used with the **BytesToWaitFor** member to tell the operating system what to do if the [**FSCTL_READ_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_read_usn_journal) operation requests more data than exists in the change journal.

If **Timeout** is zero and **BytesToWaitFor** is nonzero, and the **FSCTL_READ_USN_JOURNAL** operation call reaches the end of the change journal without finding data to return, **FSCTL_READ_USN_JOURNAL** waits until **BytesToWaitFor** bytes of unfiltered data have been added to the change journal and then retrieves the specified records.

If **Timeout** is nonzero and **BytesToWaitFor** is nonzero, and the **FSCTL_READ_USN_JOURNAL** operation call reaches the end of the change journal without finding data to return, **FSCTL_READ_USN_JOURNAL** waits **Timeout** seconds and then attempts to return the specified records. After **Timeout** seconds, **FSCTL_READ_USN_JOURNAL** retrieves any records available within the specified range.

In either case, after the time-out period any new data appended to the change journal is processed. If there are still no records to return from the specified set, the time-out period is repeated. In this mode, **FSCTL_READ_USN_JOURNAL** remains outstanding until at least one record is returned or I/O is canceled.

If **BytesToWaitFor** is zero, then **Timeout** is ignored. **Timeout** is also ignored for asynchronously opened handles.

### `BytesToWaitFor`

The number of bytes of unfiltered data added to the change journal. Use this value with **Timeout** to tell the operating system what to do if the **FSCTL_READ_USN_JOURNAL** operation requests more data than exists in the change journal.

If **BytesToWaitFor** is zero, then **Timeout** is ignored. In this case, the **FSCTL_READ_USN_JOURNAL** operation always returns successfully when the end of the change journal file is encountered. It also retrieves the USN that should be used for the next [**FSCTL_READ_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_read_usn_journal) operation. When the returned next USN is the same as the StartUsn supplied, there are no records available. The calling process should not use **FSCTL_READ_USN_JOURNAL** again immediately.

Because the amount of data returned cannot be predicted when **BytesToWaitFor** is zero, you run a risk of overflowing the output buffer. To reduce this risk, specify a nonzero **BytesToWaitFor** value in repeated **FSCTL_READ_USN_JOURNAL** operations until all records in the change journal are exhausted. Then specify zero to await new records.

### `UsnJournalID`

The identifier for the instance of the journal that is current for the volume.

The NTFS file system can miss putting events in the change journal if the change journal is stopped and restarted or deleted and re-created. If either of these events occurs, the NTFS file system gives the journal a new identifier. If the journal identifier does not agree with the current journal identifier, the call fails and returns an appropriate error code. To retrieve the new journal identifier, call with the [**FSCTL_QUERY_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_usn_journal) operation.

## See also

[**FSCTL_QUERY_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_usn_journal)

[**FSCTL_READ_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_read_usn_journal)