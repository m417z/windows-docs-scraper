## Description

The **READ_USN_JOURNAL_DATA_V1** structure contains information defining a set of update sequence number (USN) change journal records to return to the calling process. It is used by the [**FSCTL_QUERY_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_usn_journal) and [**FSCTL_READ_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_read_usn_journal) control codes. Prior to Windows 8 and Windows Server 2012 this structure was named **READ_USN_JOURNAL_DATA**. Windows Server 2012 introduced **READ_USN_JOURNAL_DATA_V1** to support 128-bit file identifiers used by ReFS.

## Members

### `StartUsn`

See [**READ_USN_JOURNAL_DATA_V0.StartUsn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-read_usn_journal_data_v0).

### `ReasonMask`

See [**READ_USN_JOURNAL_DATA_V0.ReasonMask**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-read_usn_journal_data_v0).

### `ReturnOnlyOnClose`

See [**READ_USN_JOURNAL_DATA_V0.ReturnOnlyOnClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-read_usn_journal_data_v0).

### `Timeout`

See [**READ_USN_JOURNAL_DATA_V0.Timeout**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-read_usn_journal_data_v0).

### `BytesToWaitFor`

See [**READ_USN_JOURNAL_DATA_V0.BytesToWaitFor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-read_usn_journal_data_v0).

### `UsnJournalID`

See [**READ_USN_JOURNAL_DATA_V0.UsnJournalID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-read_usn_journal_data_v0).

### `MinMajorVersion`

The minimum major version of the USN record that the caller can accept. This allows the caller to ensure compatibility with the journal format.

### `MaxMajorVersion`

The maximum major version of the USN record that the caller can accept. This ensures that the caller does not receive records in an unexpected format.

## Remarks

## See also

[**FSCTL_QUERY_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_usn_journal)

[**FSCTL_READ_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_read_usn_journal)