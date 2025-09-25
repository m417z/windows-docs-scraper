# DELETE_USN_JOURNAL_DATA structure

## Description

Contains information on the deletion of an update sequence number (USN) change journal using the
[FSCTL_DELETE_USN_JOURNAL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_delete_usn_journal) control code.

## Members

### `UsnJournalID`

The identifier of the change journal to be deleted.

If the journal is active and deletion is requested by setting the USN_DELETE_FLAG_DELETE flag in the **DeleteFlags** member, then this identifier must specify the change journal for the current volume. Use
[FSCTL_QUERY_USN_JOURNAL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_query_usn_journal) to retrieve the identifier of this change journal. If in this case the identifier is not for the current volume's change journal,
[FSCTL_DELETE_USN_JOURNAL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_delete_usn_journal) fails.

If notification instead of deletion is requested by setting only the USN_DELETE_FLAG_NOTIFY flag in **DeleteFlags**, **UsnJournalID** is ignored.

### `DeleteFlags`

Indicates whether deletion or notification regarding deletion is performed, or both. The **DeleteFlags** member must contain one or both of the following values.

| Value | Meaning |
| --- | --- |
| **USN_DELETE_FLAG_DELETE**<br><br>0x00000001 | If this flag is set and the USN_DELETE_FLAG_NOTIFY flag is not set, the [FSCTL_DELETE_USN_JOURNAL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_delete_usn_journal) operation starts the journal deletion process and returns immediately. The journal deletion process continues, if necessary, across system restarts.<br><br>If this flag is set and the USN_DELETE_FLAG_NOTIFY flag is also set, both deletion and notification occur. If this flag is set and the journal is active, you must provide the identifier for the change journal for the current volume in **UsnJournalID** or the operation fails. If the journal is not active, then **UsnJournalID** is ignored and the journal is deleted. |
| **USN_DELETE_FLAG_NOTIFY**<br><br>0x00000002 | If this flag is set, the call sets up notification about when deletion is complete. The journal deletion request is completed when the journal deletion process is complete. If this flag is set and the USN_DELETE_FLAG_DELETE flag is not set, then the call sets up notification of a deletion that may already be in progress. For example, when your application starts, it might use this flag to determine if a deletion is in progress.<br><br>If this flag is set and the USN_DELETE_FLAG_DELETE flag is also set, both deletion and notification occur. The notification is performed using an I/O completion port or another mechanism for asynchronous event notification. |

## Remarks

For more information, see
[Creating, Modifying, and Deleting a Change Journal](https://learn.microsoft.com/windows/desktop/FileIO/creating-modifying-and-deleting-a-change-journal).

## See also

[FSCTL_DELETE_USN_JOURNAL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_delete_usn_journal)

[FSCTL_QUERY_USN_JOURNAL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_query_usn_journal)