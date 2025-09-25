# UPSTurnOff function

## Description

The **UPSTurnOff** function turns off the UPS unit's power outlets, after a specified delay time.

## Parameters

### `aTurnOffDelay` [in]

Specifies the minimum amount of time, in seconds, to wait before turning off the UPS unit's power outlets.

## Remarks

The actual delay time should not be less than that specified by *aTurnOffDelay*, to ensure adequate time for the operating system to shut down.

The default value for *aTurnOffDelay* is 180 seconds.

The function must not postpone the request to turn off the power. Doing so could result in the operating system unloading the UPS service and the UPS minidriver.

On the other hand, the function must not turn off power from a UPS system that does not have an internal turnoff delay. Doing so will result in a premature loss of power to the computer, which can cause system corruption.