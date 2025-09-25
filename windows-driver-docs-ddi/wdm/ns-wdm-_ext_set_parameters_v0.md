# _EXT_SET_PARAMETERS_V0 structure

## Description

The **EXT_SET_PARAMETERS** structure contains an extended set of parameters for the [ExSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsettimer) routine.

## Members

### `Version`

The version number of this **EXT_SET_PARAMETERS** structure. The [ExInitializeSetTimerParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializesettimerparameters) routine sets this member to the correct version number.

### `Reserved`

Set to zero. The **ExInitializeSetTimerParameters** routine sets this member to zero.

### `NoWakeTolerance`

The maximum time, in system time units (100-nanosecond intervals), that the timer can wait to wake the processor after the timer reaches its expiration time. Only after the processor wakes can the timer expire. If a timer is set to expire when the processor is in a low-power state, the timer will not wake the processor to expire until the expiration time plus the **NoWakeTolerance** delay is exceeded. As an option, a driver can set this member to EX_TIMER_UNLIMITED_TOLERANCE, which indicates that the timer never wakes the processor and, thus, cannot expire until the processor wakes for some other reason.

Do not set this member to a negative value (other than EX_TIMER_UNLIMITED_TOLERANCE). Otherwise, the routine bug checks.

## Remarks

The *Parameters* parameter of the [ExSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsettimer) routine is a pointer to an **EXT_SET_PARAMETERS** structure. Before passing an **EXT_SET_PARAMETERS** structure to this routine, call the [ExInitializeSetTimerParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializesettimerparameters) routine to initialize the structure.

The **ExInitializeSetTimerParameters** routine sets the **NoWakeTolerance** member to zero, which means that the timer immediately wakes the processor if the timer reaches its expiration time when the processor is in a low-power state. To reduce power consumption, a driver can set this member to a nonzero value to extend the time that the processor spends in a low-power state.

## See also

[ExInitializeSetTimerParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializesettimerparameters)

[ExSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsettimer)