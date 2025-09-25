# KSPROPERTY_VIDEODECODER_STATUS_S structure

## Description

The KSPROPERTY_VIDEODECODER_STATUS_S structure describes the present status of a video decoding device, such as number of lines in the incoming analog signal and whether the signal is locked in.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `NumberOfLines`

Indicates the number of lines detected in the incoming analog video signal.

### `SignalLocked`

Indicates whether the signal is locked. Zero indicates that the signal is not locked. A nonzero value indicates the signal is locked.

## Remarks

The KSPROPERTY_VIDEODECODER_STATUS_S structure retrieves information about the video decoding process, including the number of lines in the incoming analog video signal.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_VIDEODECODER_STATUS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videodecoder-status)