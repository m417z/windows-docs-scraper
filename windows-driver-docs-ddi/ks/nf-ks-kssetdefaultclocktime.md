# KsSetDefaultClockTime function

## Description

The **KsSetDefaultClockTime** function sets the current time of the clock. It modifies the current time returned by the clock. The owner of the default clock is expected to serialize access to this function and to the [KsSetDefaultClockState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kssetdefaultclockstate) function.

The function can be called at DISPATCH_LEVEL.

## Parameters

### `DefaultClock` [in]

Specifies an initialize default clock structure that is shared among instances of the default clock for the parent.

### `Time` [in]

Specifies the new time to set the clock.

## Return value

None

## See also

[KsGetDefaultClockTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetdefaultclocktime)