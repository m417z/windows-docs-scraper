# IsNativeVhdBoot function

## Description

Indicates if the OS was booted from a VHD container.

## Parameters

### `NativeVhdBoot` [out]

Pointer to a variable that receives a boolean
indicating if the OS was booted from a VHD.

## Return value

TRUE if the OS was a native VHD boot; otherwise, FALSE.

Call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## See also

[GetProcessHandleCount](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocesshandlecount)

[GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo)

[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo)

[GetSystemRegistryQuota](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getsystemregistryquota)

[GetSystemTimes](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getsystemtimes)