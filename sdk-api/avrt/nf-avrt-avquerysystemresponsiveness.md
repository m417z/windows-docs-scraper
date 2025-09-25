# AvQuerySystemResponsiveness function

## Description

Retrieves the system responsiveness setting used by the multimedia class scheduler service.

## Parameters

### `AvrtHandle` [in]

A handle to the task. This handle is returned by the [AvSetMmThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmthreadcharacteristicsa) or [AvSetMmMaxThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmmaxthreadcharacteristicsa) function.

### `SystemResponsivenessValue` [out]

The system responsiveness value. This value can range from 10 to 100 percent.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Multimedia Class Scheduler Service](https://learn.microsoft.com/windows/desktop/ProcThread/multimedia-class-scheduler-service)