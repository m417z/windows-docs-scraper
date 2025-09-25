## Description

A **DIRECTORY_NOTIFY_INFORMATION_CLASS** value specifies which structure to use to query or set information for files in a directory.

## Constants

### `DirectoryNotifyInformation`

Use a [**FILE_NOTIFY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_notify_information) structure.

### `DirectoryNotifyExtendedInformation`

Use a [**FILE_NOTIFY_EXTENDED_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_notify_extended_information) structure.

### `DirectoryNotifyFullInformation`

Use a [**FILE_NOTIFY_FULL_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_notify_full_information) structure. Supported starting in Windows 11, version 22H2.

### `DirectoryNotifyMaximumInformation`

The maximum value for this enumeration.

## See also

[**IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control)