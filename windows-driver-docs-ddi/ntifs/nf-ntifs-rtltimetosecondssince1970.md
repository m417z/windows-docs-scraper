# RtlTimeToSecondsSince1970 function

## Description

The **RtlTimeToSecondsSince1970** routine converts a given absolute system time value to the elapsed time, in seconds, since the beginning of 1970.

## Parameters

### `Time` [in]

Pointer to a variable that specifies the system time value to be converted. The approximate valid range for this variable begins at 1970 and ends around 2105.

### `ElapsedSeconds` [out]

Pointer to a caller-allocated variable that receives the corresponding number of seconds since midnight, December 31, 1969.

## Return value

**RtlTimeToSecondsSince1970** returns **TRUE** if the input *Time* falls within a range that it can accurately convert to *ElapsedSeconds*.

## Remarks

The basis for system time is the start of 1601. The absolute system time is a LARGE_INTEGER value, accurate to 100-nanosecond resolution, assuming an accurate hardware clock. The value processed by **RtlTimeToSecondsSince1970** is truncated to one-millisecond resolution.

For more information about converting time values, see [Data Conversions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#data-conversions).

## See also

[RtlSecondsSince1970ToTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsecondssince1970totime)

[RtlTimeFieldsToTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtltimefieldstotime)

[RtlTimeToSecondsSince1980](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtltimetosecondssince1980)

[RtlTimeToTimeFields](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtltimetotimefields)