# CREATE_USN_JOURNAL_DATA structure

## Description

Contains information that describes an update sequence number (USN) change journal.

## Members

### `MaximumSize`

The target maximum size that the NTFS file system allocates for the change journal, in bytes.

The change journal can grow larger than this value, but it is then truncated at the next NTFS file system
checkpoint to less than this value.

### `AllocationDelta`

The size of memory allocation that is added to the end and removed from the beginning of the change journal, in bytes.

The change journal can grow to more than the sum of the values of **MaximumSize** and
**AllocationDelta** before being trimmed.

## Remarks

For more information, see
[Creating, Modifying, and Deleting a Change Journal](https://learn.microsoft.com/windows/desktop/FileIO/creating-modifying-and-deleting-a-change-journal).

## See also

[FSCTL_CREATE_USN_JOURNAL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_create_usn_journal)