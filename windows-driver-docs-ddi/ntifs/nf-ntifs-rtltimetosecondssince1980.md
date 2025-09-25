# RtlTimeToSecondsSince1980 function

## Description

The **RtlTimeToSecondsSince1980** routine converts a given absolute system time value to the elapsed time, in seconds, since the beginning of 1980.

## Parameters

### `Time` [in]

Pointer to a variable that specifies the system time value to be converted. The approximate valid range for this variable begins at 1980 and ends around 2115.

### `ElapsedSeconds` [out]

Pointer to a caller-allocated variable that receives the corresponding number of seconds since midnight, December 31, 1979.

## Return value

**RtlTimeToSecondsSince1980** returns **TRUE** if the input *Time* falls within a range that it can accurately convert to *ElapsedSeconds*.

## Remarks

The absolute system time is a LARGE_INTEGER value, accurate to 100-nanosecond resolution, assuming an accurate hardware clock. The basis for system time is the start of 1601. The value that is processed by **RtlTimeToSecondsSince1980** is truncated to one-millisecond resolution.

For more information about converting time values, see [Data Conversions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#data-conversions).

## See also

[RtlSecondsSince1980ToTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsecondssince1980totime)

[RtlTimeFieldsToTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtltimefieldstotime)

[RtlTimeToSecondsSince1970](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtltimetosecondssince1970)

[RtlTimeToTimeFields](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtltimetotimefields)