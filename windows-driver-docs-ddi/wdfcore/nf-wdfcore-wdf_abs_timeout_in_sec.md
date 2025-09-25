# WDF_ABS_TIMEOUT_IN_SEC function

## Description

[Applies to KMDF and UMDF]

The **WDF_ABS_TIMEOUT_IN_SEC** function converts a specified number of seconds to an absolute time value.

## Parameters

### `Time` [in]

The number of seconds to convert.

## Return value

**WDF_ABS_TIMEOUT_IN_SEC** returns the absolute time value, in system time units (100-nanosecond intervals), that represents the number of seconds that *Time* specifies.

## Remarks

An absolute time value is a time value that specifies a specific date and time. Absolute times are relative to 00:00, January 1, 1601. If an absolute time value is passed to the system, the system adds the absolute time value to the time value that represents 00:00, January 1, 1601.

## See also

[WDF_REL_TIMEOUT_IN_SEC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcore/nf-wdfcore-wdf_rel_timeout_in_sec)