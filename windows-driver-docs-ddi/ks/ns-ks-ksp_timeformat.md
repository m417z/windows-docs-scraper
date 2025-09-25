# KSP_TIMEFORMAT structure

## Description

The KSP_TIMEFORMAT structure corresponds to [KSPROPERTY_MEDIASEEKING_CONVERTTIMEFORMAT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-mediaseeking-converttimeformat).

## Members

### `Property`

Specifies a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure.

### `SourceFormat`

Pointer to a GUID that specifies the format to convert. If **NULL**, the current format is used.

### `TargetFormat`

Pointer to a GUID that specifies the target format. If **NULL**, the current format is used.

### `Time`

Specifies the time value to convert.

## Remarks

The fields of the structure correspond one to one with DirectShow's IMediaSeeking::ConvertTimeFormat.

## See also

[KSPROPERTY_MEDIASEEKING_CONVERTTIMEFORMAT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-mediaseeking-converttimeformat)