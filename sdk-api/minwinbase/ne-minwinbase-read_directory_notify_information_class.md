# READ_DIRECTORY_NOTIFY_INFORMATION_CLASS enumeration

## Description

Indicates the possible types of information that an application that calls the [ReadDirectoryChangesExW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readdirectorychangesexw) function can request.

## Constants

### `ReadDirectoryNotifyInformation:1`

The [ReadDirectoryChangesExW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readdirectorychangesexw) function should provide information that describes the changes within the specified directory, and return this information in the output buffer in the form of [FILE_NOTIFY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-file_notify_information) structures.

### `ReadDirectoryNotifyExtendedInformation`

The [ReadDirectoryChangesExW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readdirectorychangesexw) function should provide extended information that describes the changes within the specified directory, and return this information in the output buffer in the form of [FILE_NOTIFY_EXTENDED_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-file_notify_extended_information) structures.

## See also

[FILE_NOTIFY_EXTENDED_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-file_notify_extended_information)

[FILE_NOTIFY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-file_notify_information)

[ReadDirectoryChangesExW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readdirectorychangesexw)