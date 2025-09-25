# GetProcessVersion function

## Description

Retrieves the major and minor version numbers of the system on which the specified process expects to run.

## Parameters

### `ProcessId` [in]

The process identifier of the process of interest. A value of zero specifies the calling process.

## Return value

If the function succeeds, the return value is the version of the system on which the process expects to run. The high word of the return value contains the major version number. The low word of the return value contains the minor version number.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The function fails if *ProcessId* is an invalid value.

## Remarks

The **GetProcessVersion** function performs less quickly when *ProcessId* is nonzero, specifying a process other than the calling process.

The version number returned by this function is the version number stamped in the image header of the .exe file the process is running. Linker programs set this value.

If this function is called from a 32-bit application running on WOW64, the specified process must be a 32-bit process or the function fails.

## See also

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)