# UPSWaitForStateChange function

## Description

The **UPSWaitForStateChange** function waits until a specified UPS state changes, or until a time-out interval elapses.

## Parameters

### `aCurrentState` [in]

Specifies the UPS state on which to wait. When the state of the UPS system changes from the specified state to any other state, the function returns. The specified value can be one of the following:

#### UPS_ONLINE

Utility-supplied power is normal.

#### UPS_ONBATTERY

Utility-supplied power is inadequate, and the UPS batteries are discharging.

#### UPS_LOWBATTERY

Utility-supplied power is inadequate, and the UPS batteries are critically low.

#### UPS_NOCOMM

Communication with the UPS is not currently established.

### `anInterval` [in]

Specifies a time-out interval, in milliseconds, for the function. If the UPS state has not changed from the specified state when the interval elapses, the function returns. A value of INFINITE means the interval never elapses.

## Remarks

The **UPSWaitForStateChange** function must wait until either the state of the UPS changes from the value specified by *aCurrentState*, or until the time specified by *anInterval* has elapsed, whichever occurs first.

A call to [UPSCancelWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/upssvc/nf-upssvc-upscancelwait) interrupts **UPSWaitForStateChange** and causes it to return.

## See also

[UPSCancelWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/upssvc/nf-upssvc-upscancelwait)