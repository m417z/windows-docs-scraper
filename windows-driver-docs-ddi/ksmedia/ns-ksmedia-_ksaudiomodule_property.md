# _KSAUDIOMODULE_PROPERTY structure

## Description

The **KSAUDIOMODULE_PROPERTY** structure describes the static, external properties of the audio modules.

## Members

### `Property`

The KSPROPERTY of the audio module is defined as follows.

### `ClassId`

The ClassId of the audio module. The ClassId is an identifier that establishes what type of module this is. The value and mapping is established by the ISV and IHV.

### `InstanceId`

The InstanceId of the audio module. The InstanceId is a unique identifier that distinguishes this instance of a module from another instance of a module.

## Remarks

For more information about audio modules, see [Implementing Audio Module Discovery](https://learn.microsoft.com/windows-hardware/drivers/audio/implementing-audio-module-communication).

## See also

[KSPROPERTY_AUDIOMODULE_DESCRIPTORS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audiomodule-descriptors)