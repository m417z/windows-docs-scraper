# RtlTimeToTimeFields function

## Description

The RtlTimeToTimeFields routine converts system time into a **TIME_FIELDS** structure.

## Parameters

### `Time` [in]

Pointer to a buffer containing the absolute system time as a large integer, accurate to 100-nanosecond resolution.

### `TimeFields` [out]

Pointer to a structure of type [**TIME_FIELDS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-time_fields) to contain the returned information.

## Return value

None

## Remarks

Callers of **RtlTimeToTimeFields** can be running at any IRQL if both input buffers are resident.

## See also

[**TIME_FIELDS** structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-time_fields)

[ExLocalTimeToSystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exlocaltimetosystemtime)

[ExSystemTimeToLocalTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsystemtimetolocaltime)

[KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime)

[RtlTimeFieldsToTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtltimefieldstotime)