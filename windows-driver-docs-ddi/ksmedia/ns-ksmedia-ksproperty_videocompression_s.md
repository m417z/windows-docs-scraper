# KSPROPERTY_VIDEOCOMPRESSION_S structure

## Description

The KSPROPERTY_VIDEOCOMPRESSION_S structure describes a single KSPROPERTY_VIDEOCOMPRESSION_Xxx property of a specified stream.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `StreamIndex`

Contains the zero-based index of the stream.

### `Value`

Specifies the value of a request. For Set requests, the minidriver must set the property specified in **Property** to this value. For Get requests, the minidriver must return the value of the property specified in **Property**.

## Remarks

All KSPROPERTY_VIDEOCOMPRESSION properties that use this structure are read/write.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_VIDEOCOMPRESSION_KEYFRAME_RATE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videocompression-keyframe-rate)

[KSPROPERTY_VIDEOCOMPRESSION_OVERRIDE_FRAME_SIZE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videocompression-override-frame-size)

[KSPROPERTY_VIDEOCOMPRESSION_OVERRIDE_KEYFRAME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videocompression-override-keyframe)

[KSPROPERTY_VIDEOCOMPRESSION_PFRAMES_PER_KEYFRAME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videocompression-pframes-per-keyframe)

[KSPROPERTY_VIDEOCOMPRESSION_QUALITY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videocompression-quality)

[KSPROPERTY_VIDEOCOMPRESSION_WINDOWSIZE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videocompression-windowsize)

[PROPSETID_VIDCAP_VIDEOCOMPRESSION](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videocompression)