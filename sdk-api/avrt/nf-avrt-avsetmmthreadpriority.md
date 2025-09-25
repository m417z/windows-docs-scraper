# AvSetMmThreadPriority function

## Description

Adjusts the thread priority of the calling thread relative to other threads performing the same task.

## Parameters

### `AvrtHandle` [in]

A handle to the task. This handle is returned by the [AvSetMmThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmthreadcharacteristicsa) or [AvSetMmMaxThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmmaxthreadcharacteristicsa) function.

### `Priority` [in]

The relative thread priority of this thread to other threads performing a similar task. This parameter can be one of the following values.

#### AVRT_PRIORITY_CRITICAL (2)

#### AVRT_PRIORITY_HIGH (1)

#### AVRT_PRIORITY_LOW (-1)

#### AVRT_PRIORITY_NORMAL (0)

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Multimedia Class Scheduler Service](https://learn.microsoft.com/windows/desktop/ProcThread/multimedia-class-scheduler-service)