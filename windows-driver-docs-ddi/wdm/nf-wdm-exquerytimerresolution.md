# ExQueryTimerResolution function

## Description

The **ExQueryTimerResolution** routine reports the range of timer resolutions that are supported by the system clock.

## Parameters

### `MaximumTime` [out]

A pointer to a location to which the routine writes the maximum time interval, in 100-nanosecond units, between successive ticks of the system clock. A *tick* is an interrupt caused by the system clock timer.

### `MinimumTime` [out]

A pointer to a location to which the routine writes the minimum time interval, in 100-nanosecond units, between successive ticks of the system clock.

### `CurrentTime` [out]

A pointer to a location to which the routine writes the current time interval, in 100-nanosecond units, between successive ticks of the system clock.

## Remarks

If your driver calls the [ExSetTimerResolution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsettimerresolution) routine to change the time interval between successive system clock interrupts, the driver can first call **ExQueryTimerResolution** to determine the range of intervals supported by the system clock.

When your driver calls a routine such as [KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex) to set a timer, the accuracy of the timer depends on the resolution of the system clock. For more information, see [Timer Accuracy](https://learn.microsoft.com/windows-hardware/drivers/kernel/timer-accuracy).

## See also

[ExSetTimerResolution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsettimerresolution)

[KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex)