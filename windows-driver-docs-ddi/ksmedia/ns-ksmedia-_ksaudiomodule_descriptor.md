# _KSAUDIOMODULE_DESCRIPTOR structure

## Description

The **KSAUDIOMODULE_DESCRIPTOR** structure describes the static, external properties of audio modules.

## Members

### `ClassId`

The ClassId of the audio module. The ClassId is an identifier that establishes what type of module this is. The value and mapping is established by the ISV and IHV.

### `InstanceId`

The InstanceId of the audio module. The InstanceId is a unique identifier that distinguishes this instance of a module from another instance of a module.

### `VersionMajor`

The major version of the audio module. Usage is defined by the implementer.

### `VersionMinor`

The minor version of the audio module. Usage is defined by the implementer.

### `Name`

The friendly name of the audio module. The maximum length is AUDIOMODULE_MAX_NAME_CCH_SIZE wide characters. It is defined as 128 in KSMedia.h.

## Remarks

For more information about audio modules, see [Implementing Audio Module Discovery](https://learn.microsoft.com/windows-hardware/drivers/audio/implementing-audio-module-communication).

## See also

[KSPROPERTY_AUDIOMODULE_DESCRIPTORS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audiomodule-descriptors)