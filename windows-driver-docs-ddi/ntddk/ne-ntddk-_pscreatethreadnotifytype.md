# _PSCREATETHREADNOTIFYTYPE enumeration

## Description

Indicates the type of thread notification. This enumeration is used in [PsSetCreateThreadNotifyRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutineex) to register callback notifications associated with thread creation or deletion.

## Constants

### `PsCreateThreadNotifyNonSystem`

The driver-registered callback function is executed on the new non-system thread, which enables the callback function to perform tasks such as setting the initial thread context.

### `PsCreateThreadNotifySubsystems`

Indicates that the driver-registered callback function is invoked for threads of all subsystems. Drivers can call [NtQueryInformationThread](https://learn.microsoft.com/windows/win32/api/winternl/nf-winternl-ntqueryinformationthread) to determine the underlying subsystem. The query retrieves a [SUBSYSTEM_INFORMATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_subsystem_information_type) value.

## See also

[NtQueryInformationThread](https://learn.microsoft.com/windows/win32/api/winternl/nf-winternl-ntqueryinformationthread)

[PsSetCreateThreadNotifyRoutineEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutineex)

[SUBSYSTEM_INFORMATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_subsystem_information_type)