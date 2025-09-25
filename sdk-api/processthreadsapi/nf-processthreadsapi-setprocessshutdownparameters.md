# SetProcessShutdownParameters function

## Description

Sets shutdown parameters for the currently calling process. This function sets a shutdown order for a process relative to the other processes in the system.

## Parameters

### `dwLevel` [in]

The shutdown priority for a process relative to other processes in the system. The system shuts down processes from high *dwLevel* values to low. The highest and lowest shutdown priorities are reserved for system components. This parameter must be in the following range of values.

| Value | Meaning |
| --- | --- |
| 000-0FF | System reserved last shutdown range. |
| 100-1FF | Application reserved last shutdown range. |
| 200-2FF | Application reserved "in between" shutdown range. |
| 300-3FF | Application reserved first shutdown range. |
| 400-4FF | System reserved first shutdown range. |

All processes start at shutdown level 0x280.

### `dwFlags` [in]

This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **SHUTDOWN_NORETRY**<br><br>0x00000001 | The system terminates the process without displaying a retry dialog box for the user. |

## Return value

If the function is succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Applications running in the system security context do not get shut down by the operating system. They get notified of shutdown or logoff through the callback function installable via
[SetConsoleCtrlHandler](https://learn.microsoft.com/windows/console/setconsolectrlhandler). They also get notified in the order specified by the *dwLevel* parameter.

## See also

[GetProcessShutdownParameters](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessshutdownparameters)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[SetConsoleCtrlHandler](https://learn.microsoft.com/windows/console/setconsolectrlhandler)