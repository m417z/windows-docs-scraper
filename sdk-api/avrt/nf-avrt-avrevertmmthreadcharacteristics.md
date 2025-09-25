# AvRevertMmThreadCharacteristics function

## Description

Indicates that a thread is no longer performing work associated with the specified task.

## Parameters

### `AvrtHandle` [in]

A handle to the task. This handle is returned by the [AvSetMmThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmthreadcharacteristicsa) or [AvSetMmMaxThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmmaxthreadcharacteristicsa) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function must be called from the same thread that called the [AvSetMmThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmthreadcharacteristicsa) or [AvSetMmMaxThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmmaxthreadcharacteristicsa) function to create the handle. Otherwise, the function will fail.

## See also

[Multimedia Class Scheduler Service](https://learn.microsoft.com/windows/desktop/ProcThread/multimedia-class-scheduler-service)