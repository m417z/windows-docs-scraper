# NdisGetSystemUpTimeEx function

## Description

The
**NdisGetSystemUpTimeEx** function returns the number of milliseconds that have elapsed since the
computer was restarted.

## Parameters

### `pSystemUpTime` [out]

A pointer to a caller-supplied LARGE_INTEGER variable in which this function returns the time, in
milliseconds, since the computer was last restarted.

## Remarks

NDIS drivers should call the
**NdisGetSystemUpTimeEx** function instead of the
[NdisGetSystemUpTime](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff552110(v=vs.85)) function.

## See also

[NdisGetSystemUpTime](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff552110(v=vs.85))