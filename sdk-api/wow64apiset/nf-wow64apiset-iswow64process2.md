# IsWow64Process2 function

## Description

Determines whether the specified process is running under
[WOW64](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications); also returns additional machine process and architecture information.

## Parameters

### `hProcess` [in]

A handle to the process. The handle must have the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `pProcessMachine` [out]

On success, returns a pointer to an [IMAGE_FILE_MACHINE_*](https://learn.microsoft.com/windows/desktop/SysInfo/image-file-machine-constants) value. The value will be **IMAGE_FILE_MACHINE_UNKNOWN** if the target process is not a [WOW64](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications) process; otherwise, it will identify the type of WoW process.

### `pNativeMachine` [out, optional]

On success, returns a pointer to a possible [IMAGE_FILE_MACHINE_*](https://learn.microsoft.com/windows/desktop/SysInfo/image-file-machine-constants) value identifying the native architecture of host system.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**IsWow64Process2** provides an improved direct replacement for IsWow64Process. In addition to determining if the specified process is running under [WOW64](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications), **IsWow64Process2** returns the following information:

* Whether the target process, specified by *hProcess*, is running under Wow or not.
* The architecture of the target process.
* Optionally, the architecture of the host system.