# RtlSecondsSince1970ToTime function

## Description

The **RtlSecondsSince1970ToTime** routine converts the elapsed time, in seconds, since the beginning of 1970 to an absolute system time value.

## Parameters

### `ElapsedSeconds` [in]

Number of seconds from midnight, December 31, 1969, to the current date and time.

### `Time` [out]

Pointer to a caller-allocated variable that receives the corresponding current system time.

## Return value

None

## Remarks

The basis for system time is the start of 1601. The absolute system time is a LARGE_INTEGER value, accurate to 100-nanosecond resolution, assuming an accurate hardware clock. The value returned by **RtlSecondsSince1970ToTime** is truncated to one-millisecond resolution.

For more information about converting time values, see [Data Conversions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#data-conversions).

## See also

[RtlSecondsSince1980ToTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsecondssince1980totime)

[RtlTimeFieldsToTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtltimefieldstotime)

[RtlTimeToSecondsSince1970](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtltimetosecondssince1970)

[RtlTimeToTimeFields](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtltimetotimefields)