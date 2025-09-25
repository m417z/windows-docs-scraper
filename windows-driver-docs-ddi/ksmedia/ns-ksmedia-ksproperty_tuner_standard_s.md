# KSPROPERTY_TUNER_STANDARD_S structure

## Description

The KSPROPERTY_TUNER_STANDARD_S structure describe the standard of a TV tuner device, such as PAL, NTSC or SECAM.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `Standard`

Describes an analog video standard. This member may be set to one or more (logically ORed) values from the [KS_AnalogVideoStandard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_analogvideostandard) enumeration.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TUNER_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-standard)

[KS_AnalogVideoStandard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_analogvideostandard)

[PROPSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-tuner)