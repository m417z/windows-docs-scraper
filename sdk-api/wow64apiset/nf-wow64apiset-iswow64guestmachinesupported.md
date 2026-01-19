# IsWow64GuestMachineSupported function

## Description

Determines which architectures are supported (under [WOW64](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications)) on the given machine architecture.

## Parameters

### `WowGuestMachine` [in]

An [IMAGE_FILE_MACHINE_*](https://learn.microsoft.com/windows/desktop/SysInfo/image-file-machine-constants) value that specifies the machine to test.

### `MachineIsSupported` [out]

A pointer to the variable that, on success, receives **true** if the machine supports WOW64, or **false** if it does not.

## Return value

On success, returns **S_OK**; otherwise, returns an error. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**IsWow64GuestMachineSupported** is designed for the following scenarios:

* Debuggers (such as Visual Studio) that want to determine which debugger extensions it needs to install on the system.
* Apps that need to determine if [WOW64](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications) is turned off or not. For example, many apps assume x86-64 systems can always execute x86-32 code at all times, everywhere. Note that this ability does not exist on WinPE or Xbox, and it is an optional component in Server.
* Test suites that need to achieve full feature coverage by running tests on all supported architectures in the system.