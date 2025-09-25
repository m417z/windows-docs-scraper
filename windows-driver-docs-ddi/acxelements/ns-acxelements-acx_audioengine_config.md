## Description

The **ACX_AUDIOENGINE_CONFIG** structure is used to define the audio engine configuration.

## Members

### `Size`

The length, in bytes, of this structure.

### `Id`

A number that represents the element ID.

### `Name`

A pointer to a GUID that represents the name of the element. Can be used for debugging and will default to GUID_NULL if not provided.

### `Flags`

Audio engine configuration flags defined by the [ACX_AUDIOENGINE_CONFIG_FLAGS enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ne-acxelements-acx_audioengine_config_flags).

No flag bits are currently defined. Set this member to zero - AcxAudioEngineConfigNoFlags

### `HostPin`

An existing ACXPIN object that serves as the host pin for the audio engine. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `OffloadPin`

An existing ACXPIN object that represents the offload pin.

### `LoopbackPin`

An existing ACXPIN object that represents the loopback pin.

### `VolumeElement`

An existing ACXVOLUME object that is used for volume operations by the audio engine.

### `MuteElement`

An existing ACXMUTE object that is used for mute operations by the audio engine.

### `PeakMeterElement`

An existing ACXPEAKMETER object that is used for peakmeter operations by the audio engine.

### `Callbacks`

An [ACX_AUDIOENGINE_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_audioengine_callbacks) that defines the callbacks for the audio engine.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_AUDIOENGINE_CONFIG          audioEngineCfg;
    ACX_AUDIOENGINE_CALLBACKS       audioEngineCallbacks;

    // Initialize the config structure
    ACX_AUDIOENGINE_CONFIG_INIT(&audioEngineCfg);
    // Set the values of the structure
    audioEngineCfg.HostPin = Pins[HostPin];
    audioEngineCfg.OffloadPin = Pins[OffloadPin];
    audioEngineCfg.LoopbackPin = Pins[LoopbackPin];
    audioEngineCfg.VolumeElement = volumeElement;
    audioEngineCfg.MuteElement = muteElement;
    audioEngineCfg.PeakMeterElement = peakmeterElement;
    audioEngineCfg.Callbacks = &audioEngineCallbacks;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)