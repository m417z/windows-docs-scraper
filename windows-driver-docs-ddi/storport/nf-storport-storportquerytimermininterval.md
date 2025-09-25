## Description

**StorPortQueryTimerMinInterval** queries the minimum timer resolution that is supported by the system clock.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the miniport's device extension.

### `TimerMinInterval` [out]

Pointer to a ULONG in which this function writes the minimum time interval, in 100-nanosecond units, between successive ticks of the system clock.

## Return value

This function returns one of the following status codes.

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The timer minimum interval was successfully queried. |
| STOR_STATUS_INVALID_PARAMETER | A parameter is invalid. |
| STOR_STATUS_UNSUCCESSFUL | Returned for other internal system reasons. |

## Remarks

A miniport can call this function to query the minimum timer resolution that is supported by the system clock, which can be helpful for implementing I/O polling.