# RtlTimeFieldsToTime function

## Description

The **RtlTimeFieldsToTime** routine converts **TIME_FIELDS** information to a system time value.

## Parameters

### `TimeFields` [in]

Pointer to a structure of type [**TIME_FIELDS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-time_fields) that contains the time information to be converted.

### `Time` [out]

Pointer to a buffer, which is to contain the converted system time value as a large integer.

## Return value

**RtlTimeFieldsToTime** returns **TRUE** if the input *TimeFields* data was successfully converted.

## Remarks

**RtlTimeFieldsToTime** ignores the **Weekday** value in *TimeFields*.

Callers of **RtlTimeFieldsToTime** can be running at any IRQL if both input buffers are resident.

## See also

[ExLocalTimeToSystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exlocaltimetosystemtime)

[ExSystemTimeToLocalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsystemtimetolocaltime)

[KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime)

[RtlTimeToTimeFields](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtltimetotimefields)

[**TIME_FIELDS** structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-time_fields)