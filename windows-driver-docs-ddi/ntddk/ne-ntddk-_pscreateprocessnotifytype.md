# _PSCREATEPROCESSNOTIFYTYPE enumeration

## Description

Indicates the type of process notification. This enumeration is used in [PsSetCreateProcessNotifyRoutineEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutineex2) to register callback notifications.

## Constants

### `PsCreateProcessNotifySubsystems`

Indicates that the driver-registered callback is invoked for processes of all subsystems, including the Win32 subsystem. Drivers can call [NtQueryInformationProcess](https://learn.microsoft.com/windows/win32/api/winternl/nf-winternl-ntqueryinformationprocess) to determine the underlying subsystem. The query retrieves a [SUBSYSTEM_INFORMATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_subsystem_information_type) value.

## See also

[NtQueryInformationProcess](https://learn.microsoft.com/windows/win32/api/winternl/nf-winternl-ntqueryinformationprocess)

[PsSetCreateProcessNotifyRoutineEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutineex2)

[SUBSYSTEM_INFORMATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_subsystem_information_type)