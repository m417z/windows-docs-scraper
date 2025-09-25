## Description

The KSAUDIO_PREFERRED_STATUS structure specifies the status of a preferred device.

## Members

### `Enable`

Specifies whether the target device is the new preferred device. If **TRUE**, the target device is selected as the new preferred device. If **FALSE**, the target device was previously the preferred device, but is now deselected.

### `DeviceType`

Specifies the type of preferred device. This parameter is set to one of the following constants:

| Value | Device type |
|---|---|
| KSPROPERTY_SYSAUDIO_NORMAL_DEFAULT | Preferred device for wave playback/recording, MIDI, and mixer topology. |
| KSPROPERTY_SYSAUDIO_PLAYBACK_DEFAULT | Preferred wave playback device. |
| KSPROPERTY_SYSAUDIO_RECORD_DEFAULT | Preferred wave recording device. |
| KSPROPERTY_SYSAUDIO_MIDI_DEFAULT | Preferred MIDI device. |
| KSPROPERTY_SYSAUDIO_MIXER_DEFAULT | Preferred mixer topology device. |

The driver uses this member to determine what aspect or aspects of the audio adapter are currently selected as preferred. A driver might use this information to decide how to configure itself or decide what system resources to request.

### `Flags`

No flags are currently defined. Set to zero.

### `Reserved`

Reserved for future use. Set to zero.

## Remarks

This structure is used by the [KSPROPERTY_AUDIO_PREFERRED_STATUS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-preferred-status) property.

For information about the preferred device, see [SetupPreferredAudioDevices](https://learn.microsoft.com/windows-hardware/drivers/audio/setuppreferredaudiodevices).

## See also

[KSPROPERTY_AUDIO_PREFERRED_STATUS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-preferred-status)

[SetupPreferredAudioDevices](https://learn.microsoft.com/windows-hardware/drivers/audio/setuppreferredaudiodevices)