# _SUBSYSTEM_INFORMATION_TYPE enumeration

## Description

Indicates the type of subsystem for a process or thread. This enumeration is used in [NtQueryInformationProcess](https://learn.microsoft.com/windows/win32/api/winternl/nf-winternl-ntqueryinformationprocess) and [NtQueryInformationThread](https://learn.microsoft.com/windows/win32/api/winternl/nf-winternl-ntqueryinformationthread) calls.

## Constants

### `SubsystemInformationTypeWin32`

The subsystem type for the process or thread is Win32.

### `SubsystemInformationTypeWSL`

The subsystem type for the process or thread is Windows Subsystem for Linux (WSL). For this process, these members of the [PS_CREATE_NOTIFY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_ps_create_notify_info) structure are set as follows:

* The **FileObject** member is the NTFS file object from LxFs or DriveFs, the file system that is used for interoperability with Windows.
* The **ImageFileName** member is the Linux path of the image file.
* The **CommandLine** member is the Linux NULL-separated command line.

The preceding member values may be NULL.

### `MaxSubsystemInformationType`

Reserved.

## See also

[NtQueryInformationProcess](https://learn.microsoft.com/windows/win32/api/winternl/nf-winternl-ntqueryinformationprocess)

[NtQueryInformationThread](https://learn.microsoft.com/windows/win32/api/winternl/nf-winternl-ntqueryinformationthread)