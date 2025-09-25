# KSPROPERTY_MEDIAAVAILABLE structure

## Description

The KSPROPERTY_MEDIAAVAILABLE structure specifies the media time span (the time span that a client can seek within) that is currently available on a filter. KSPROPERTY_MEDIAAVAILABLE is used in conjunction with the [KSPROPERTY_MEDIASEEKING_AVAILABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-mediaseeking-available) property request.

## Members

### `Earliest`

Pointer to a variable that receives the earliest time for efficient seeking.

### `Latest`

Pointer to a variable that receives the latest time for efficient seeking.

## Remarks

This structure corresponds with DirectShow's **IMediaSeeking::GetAvailable**.

## See also

[KSPROPERTY_MEDIASEEKING_AVAILABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-mediaseeking-available)