# GetProcessShutdownParameters function

## Description

Retrieves the shutdown parameters for the currently calling process.

## Parameters

### `lpdwLevel` [out]

A pointer to a variable that receives the shutdown priority level. Higher levels shut down first. System level shutdown orders are reserved for system components. Higher numbers shut down first. Following are the level conventions.

| Value | Meaning |
| --- | --- |
| 000-0FF | System reserved last shutdown range. |
| 100-1FF | Application reserved last shutdown range. |
| 200-2FF | Application reserved "in between" shutdown range. |
| 300-3FF | Application reserved first shutdown range. |
| 400-4FF | System reserved first shutdown range. |

All processes start at shutdown level 0x280.

### `lpdwFlags` [out]

A pointer to a variable that receives the shutdown flags. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **SHUTDOWN_NORETRY**<br><br>0x00000001 | If this process takes longer than the specified timeout to shut down, do not display a retry dialog box for the user. Instead, just cause the process to directly exit. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[SetProcessShutdownParameters](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessshutdownparameters)