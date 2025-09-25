# KsSetDefaultClockState function

## Description

The **KsSetDefaultClockState** function sets the current state of the clock that is used to reflect the current state of the underlying filter pin. The owner of the default clock is expected to serialize access to this function and to call [KsSetDefaultClockTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kssetdefaultclocktime).

The function can be called at DISPATCH_LEVEL.

## Parameters

### `DefaultClock` [in]

Specifies an initialize default clock structure that is shared among any instance of the default clock for the parent.

### `State` [in]

Specifies the new state to set the clock.

## Return value

None

## See also

[KsGetDefaultClockState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetdefaultclockstate)