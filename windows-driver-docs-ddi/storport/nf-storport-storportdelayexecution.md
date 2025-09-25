# StorPortDelayExecution function

## Description

The **StorPortDelayExecution** function delays the current thread by the given amount of time, in microseconds. If the current IRQL is lower than DISPATCH_LEVEL then the current thread is simply put in the wait state and other threads are allowed to run. Otherwise, this routine performs a busy-wait.

## Parameters

### `HwDeviceExtension`

The miniport's device extension.

### `DelayInMicroseconds`

The delay, in microseconds.

## Return value

This function returns either a STOR_STATUS_SUCCESS or a STOR_STATUS_NOT_IMPLEMENTED.

## Remarks

## See also