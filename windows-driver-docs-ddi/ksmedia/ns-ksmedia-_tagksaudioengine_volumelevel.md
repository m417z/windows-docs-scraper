# _tagKSAUDIOENGINE_VOLUMELEVEL structure

## Description

The **KSAUDIOENGINE_VOLUMELEVEL** structure specifies the target volume level, ramp type, and duration within which the volume level should change, for a given volume level request via the [KSPROPERTY_AUDIOENGINE_VOLUMELEVEL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioengine-volumelevel) property.

## Members

### `TargetVolume`

Specifies the desired final volume level using the scale defined for the **KSPROPERTY_AUDIOENGINE_VOLUMELEVEL** property.

### `CurveType`

Uses the [AUDIO_CURVE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-audio_curve_type) enumeration to specify the curve algorithm to apply over the duration specified, in order to reach the desired level. The curve begins at the current volume level and ends at the target volume level specified in the **TargetVolume** parameter.

### `CurveDuration`

Specifies the duration, in hundreds of nanoseconds, over which the volume curve must take effect.

## See also

[AUDIO_CURVE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-audio_curve_type)

[KSPROPERTY_AUDIOENGINE_VOLUMELEVEL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioengine-volumelevel)