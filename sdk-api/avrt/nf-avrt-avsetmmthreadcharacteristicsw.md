# AvSetMmThreadCharacteristicsW function

## Description

Associates the calling thread with the specified task.

## Parameters

### `TaskName` [in]

The name of the task to be performed. This name must match the name of one of the subkeys of the following key **HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile\Tasks**.

### `TaskIndex` [in, out]

The unique task identifier. The first time this function is called, this value must be 0 on input. The index value is returned on output and can be used as input in subsequent calls.

## Return value

If the function succeeds, it returns a handle to the task.

If the function fails, it returns 0. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_TASK_INDEX** | Either *TaskIndex* is not 0 on the first call or is not recognized value (on subsequent calls). |
| **ERROR_INVALID_TASK_NAME** | The specified task does not match any of the tasks stored in the registry. |
| **ERROR_PRIVILEGE_NOT_HELD** | The caller does not have sufficient privilege. |

## Remarks

When the task is completed, call the [AvRevertMmThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avrevertmmthreadcharacteristics) function.

> [!NOTE]
> The avrt.h header defines AvSetMmThreadCharacteristics as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Multimedia Class Scheduler Service](https://learn.microsoft.com/windows/desktop/ProcThread/multimedia-class-scheduler-service)