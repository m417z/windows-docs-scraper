# KSPROPERTY_POSITIONS structure

## Description

The KSPROPERTY_POSITIONS structure specifies the current position and stop position, relative to the total duration of the stream.

## Members

### `Current`

Specifies the current position as a 64-bit value.

### `Stop`

Specifies the stop position as a 64-bit value.

### `CurrentFlags`

A structure of type [KS_SEEKING_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ks_seeking_flags) containing flags pertaining to the **Current** parameter.

### `StopFlags`

A structure of type [KS_SEEKING_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ks_seeking_flags) containing flags pertaining to the **Stop** parameter.

## Remarks

The KSPROPERTY_POSITIONS structure is used with positioning properties in the KSPROPSETID_MediaSeeking property set. These properties correspond to DirectShow's **IMediaSeeking::GetPositions** and **IMediaSeeking::SetPositions**.

## See also

[KSPROPERTY_MEDIASEEKING_POSITIONS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-mediaseeking-positions)