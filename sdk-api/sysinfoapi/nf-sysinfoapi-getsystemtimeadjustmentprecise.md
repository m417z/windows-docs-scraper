# GetSystemTimeAdjustmentPrecise function

## Description

Determines whether the system is applying periodic, programmed time adjustments to its time-of-day clock, and obtains the value and period of any such adjustments.

## Parameters

### `lpTimeAdjustment` [out]

Returns the adjusted clock update frequency.

### `lpTimeIncrement` [out]

Returns the clock update frequency.

### `lpTimeAdjustmentDisabled` [out]

Returns an indicator which specifies whether the time adjustment is enabled.

A value of **TRUE** indicates that periodic adjustment is disabled. In this case, the system may attempt to keep the time-of-day clock in sync using its own internal mechanisms. This may cause time-of-day to periodically jump to the "correct time."

A value of **FALSE** indicates that periodic, programmed time adjustment is being used to serialize time-of-day, and the system will not interfere or attempt to synchronize time-of-day on its own.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is used in algorithms that synchronize the time-of-day with another time source, using a programmed clock adjustment. To do this, the system computes the adjusted clock update frequency, and then this function allows the caller to obtain that value.

**Note**

For a complete code sample on how to enable system-time privileges, adjust the system clock, and display clock values, see [SetSystemTimeAdjustmentPrecise](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setsystemtimeadjustmentprecise).

## See also

[SetSystemTimeAdjustmentPrecise](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setsystemtimeadjustmentprecise)