# KSPROPERTY_VIDEODECODER_S structure

## Description

The KSPROPERTY_VIDEODECODER_S structure describes property settings in the PROPSETID_VIDCAP_VIDEODECODER property set.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `Value`

Specifies the value of a request. For Set requests, the minidriver should set the property specified in **Property** to this value. For Get requests, the minidriver should return the value of the property specified in **Property**.

## Remarks

The KSPROPERTY_VIDEODECODER_S structure is shared among the KSPROPERTY_VIDEODECODER_STANDARD, KSPROPERTY_VIDEODECODER_OUTPUT_ENABLE, and KSPROPERTY_VIDEODECODER_VCR_TIMING properties within the property set.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_VIDEODECODER_OUTPUT_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videodecoder-output-enable)

[KSPROPERTY_VIDEODECODER_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videodecoder-standard)

[KSPROPERTY_VIDEODECODER_VCR_TIMING](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videodecoder-vcr-timing)