# KsGetDefaultClockState function

## Description

The **KsGetDefaultClockState** function gets the current state of the clock.

The function can be called at DISPATCH_LEVEL.

## Parameters

### `DefaultClock` [in]

Specifies an initialized, default clock structure that is shared among any instance of the default clock for the parent.

## Return value

The **KsGetDefaultClockState** function returns the current clock state.

## See also

[KsSetDefaultClockState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kssetdefaultclockstate)