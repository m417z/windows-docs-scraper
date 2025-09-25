# PRIORITY_HINT enumeration

## Description

Defines values that are used with the [FILE_IO_PRIORITY_HINT_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_io_priority_hint_info) structure to specify the priority hint for a file I/O operation.

## Constants

### `IoPriorityHintVeryLow:0`

The lowest possible priority hint level. The system uses this value for background I/O operations.

### `IoPriorityHintLow`

A low-priority hint level.

### `IoPriorityHintNormal`

A normal-priority hint level. This value is the default setting for an I/O operation.

### `MaximumIoPriorityHintType`

This value is used for validation. Supported values are less than this value.

## See also

[FILE_IO_PRIORITY_HINT_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_io_priority_hint_info)

[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle)