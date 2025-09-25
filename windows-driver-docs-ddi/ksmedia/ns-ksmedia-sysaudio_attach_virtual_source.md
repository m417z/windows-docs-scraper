# SYSAUDIO_ATTACH_VIRTUAL_SOURCE structure

## Description

The SYSAUDIO_ATTACH_VIRTUAL_SOURCE structure is used to attach a mixer-line virtual source (for example, a volume or mute control) to a mixer pin on the virtual audio device.

## Members

### `Property`

Specifies the property. This parameter is a structure of type [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure).

### `MixerPinId`

Specifies the virtual source index.

### `Reserved`

Reserved. Set to zero.

## Remarks

This structure is used by the [KSPROPERTY_SYSAUDIO_ATTACH_VIRTUAL_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sysaudio-attach-virtual-source) property.

## See also

[KSPROPERTY_SYSAUDIO_ATTACH_VIRTUAL_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sysaudio-attach-virtual-source)