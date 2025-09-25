# RequestWakeupLatency function

## Description

[**RequestWakeupLatency**
is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in
subsequent versions.]

Has no effect and returns **STATUS_NOT_SUPPORTED**. This function is provided only for compatibility with earlier versions of Windows.

**Windows Server 2008 and Windows Vista:** Has no effect and always returns success.

## Parameters

### `latency` [in]

The latency requirement for the time is takes to wake the computer. This parameter can be one of the
following values.

| Value | Meaning |
| --- | --- |
| **LT_LOWEST_LATENCY**<br><br>1 | PowerSystemSleeping1 state (equivalent to ACPI state S0 and APM state Working). |
| **LT_DONT_CARE**<br><br>0 | Any latency (default). |

## Return value

The return value is nonzero.

## Remarks

The system uses the wake-up latency requirement when choosing a sleeping state. The latency is not guaranteed
because wake-up time is determined by the hardware design of the particular computer.

To cancel a latency request, call
**RequestWakeupLatency** with
**LT_DONT_CARE**.

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)