## Description

The **ACX_VOLUME_CURVE_TYPE** enumeration defines constants that specify a curve algorithm to be applied to set a volume level.

## Constants

### `AcxVolumeCurveTypeNone`

Indicates that no curve algorithm will be applied. When this curve is specified, the duration of the curve specified must be equal to 0.

### `AcxVolumeCurveTypeFade`

Indicates that the algorithm that is applied to the volume setting must follow the curve shown in the diagram in [AUDIO_CURVE_TYPE enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-audio_curve_type).

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)