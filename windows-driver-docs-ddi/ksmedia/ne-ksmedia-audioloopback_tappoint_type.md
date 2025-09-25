# AUDIOLOOPBACK_TAPPOINT_TYPE enumeration (ksmedia.h)

## Description

The **AUDIOLOOPBACK_TAPPOINT_TYPE** enum contains the pre and post tap point definitions.

## Constants

### `AUDIOLOOPBACK_TAPPOINT_PREVOLUMEMUTE`

The loopback stream tap point is returned before applying endpoint volume and mute.

### `AUDIOLOOPBACK_TAPPOINT_POSTVOLUMEMUTE`

The loopback stream tap point is after applying endpoint volume and mute.

## Remarks

The **AUDIOLOOPBACK_TAPPOINT_TYPE** enumeration is available starting in Windows 11 24H2.

The enum is used by [KSPROPERTY_AUDIOLOOPBACK](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioloopback) in the [KSPROPSETID_AudioLoopback](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-audioloopback) property set to indicate if the loopback tap point is pre or post volume and mute.

## See also

- [KSPROPERTY_AUDIOLOOPBACK](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioloopback)
- [KSPROPSETID_AudioLoopback](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-audioloopback)
- [KSATTRIBUTE_AUDIOLOOPBACK_TAPPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksattribute_audioloopback_tappoint)