## Description

The **CREATE_USN_JOURNAL_DATA** structure contains information for the creation of an update sequence number (USN) change journal.

## Members

### `MaximumSize`

The target maximum size that the NTFS file system allocates for the change journal, in bytes.

### `AllocationDelta`

The size of memory allocation that is added to the end and removed from the beginning of the change journal, in bytes.

The change journal can grow to more than the sum of the values of **MaximumSize** and **AllocationDelta** before being trimmed.

## Remarks

For more information, see [Creating, Modifying, and Deleting a Change Journal](https://learn.microsoft.com/windows/win32/fileio/creating-modifying-and-deleting-a-change-journal).

## See also

[**FSCTL_CREATE_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_create_usn_journal)