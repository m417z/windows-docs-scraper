## Description

The **USN_RECORD_UNION** is a union that encapsulates different versions of USN record structures. It provides a flexible way to handle USN records of varying formats.

## Members

### `Header`

A [**USN_RECORD_COMMON_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_common_header) structure that provides common header information for USN records. This member is useful for accessing shared fields across different USN record versions.

### `V2`

A [**USN_RECORD_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v2) structure representing the version 2 format of a USN record.

### `V3`

A [**USN_RECORD_V3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v3) structure representing the version 3 format of a USN record.

### `V4`

A [**USN_RECORD_V4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v4) structure representing the version 4 format of a USN record.

## See also

[**FSCTL_READ_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_read_usn_journal)