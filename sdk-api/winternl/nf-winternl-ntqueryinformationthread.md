# NtQueryInformationThread function

## Description

[**NtQueryInformationThread** may be altered or unavailable in future versions of Windows. Applications should use the alternate functions listed in this topic.]

Retrieves information about the specified thread.

## Parameters

### `ThreadHandle` [in]

A handle to the thread about which information is being requested.

### `ThreadInformationClass` [in]

If this parameter is the **ThreadIsIoPending** value of the **THREADINFOCLASS** enumeration, the function determines whether the thread has any I/O operations pending.

Use the public function [GetThreadIOPendingFlag](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadiopendingflag) instead to obtain this information.

If this parameter is the **ThreadQuerySetWin32StartAddress** value of the **THREADINFOCLASS** enumeration, the function returns the start address of the thread. Note that on versions of Windows prior to Windows Vista, the returned start address is only reliable before the thread starts running.

If this parameter is the **ThreadSubsystemInformation** value of the **THREADINFOCLASS** enumeration, the function retrieves a [SUBSYSTEM_INFORMATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddk/ne-ntddk-_subsystem_information_type) value indicating the subsystem type of the thread. The buffer pointed to by the *ThreadInformation* parameter should be large enough to hold a single **SUBSYSTEM_INFORMATION_TYPE** enumeration.

### `ThreadInformation` [in, out]

A pointer to a buffer in which the function writes the requested information. If **ThreadIsIoPending** is specified for the *ThreadInformationClass* parameter, this buffer must be large enough to hold a **ULONG** value, which indicates whether the specified thread has I/O requests pending. If this value is equal to zero, then there are no I/O operations pending; otherwise, if the value is nonzero, then the thread does have I/O operations pending.

Use the public function [GetThreadIOPendingFlag](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadiopendingflag) instead to obtain this information.

If **ThreadQuerySetWin32StartAddress** is specified for the *ThreadInformationClass* parameter, this buffer must be large enough to hold a PVOID value, which is the start address of the thread.

### `ThreadInformationLength` [in]

The size of the buffer pointed to by the *ThreadInformation* parameter, in bytes.

### `ReturnLength` [out, optional]

A pointer to a variable in which the function returns the size of the requested information. If the function was successful, this is the size of the information written to the buffer pointed to by the *ThreadInformation* parameter, but if the buffer was too small, this is the minimum size of buffer required to receive the information successfully.

## Return value

Returns an NTSTATUS success or error code.

The forms and significance of NTSTATUS error codes are listed in the Ntstatus.h header file available in the DDK, and are described in the DDK documentation under Kernel-Mode Driver Architecture / Design Guide / Driver Programming Techniques / Logging Errors.

## Remarks

The **NtQueryInformationThread** function is internal to the operating system and subject to change from one release of Windows to another. To maintain the compatibility of your application, it is better to use the public function previously mentioned instead.

If you do use **NtQueryInformationThread**, access the function through [run-time dynamic linking](https://learn.microsoft.com/windows/desktop/Dlls/using-run-time-dynamic-linking). This gives your code an opportunity to respond gracefully if the function has been changed or removed from the operating system. Signature changes, however, may not be detectable.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## See also

[GetThreadIOPendingFlag](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadiopendingflag)