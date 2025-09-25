## Description

The **ACX_STREAMAUDIOENGINE_CONFIG** structure is used to define the stream audio engine configuration.

## Members

### `Size`

The length, in bytes, of this structure.

### `Id`

A number that represents the element ID.
### `Name`

A pointer to a GUID that represents the name of the element. Can be used for debugging and will default to GUID_NULL if not provided.

### `Flags`

Acx peakmeter configuration flags defined by the [ACX_STREAMAUDIOENGINE_CONFIG_FLAGS enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ne-acxelements-acx_streamaudioengine_config_flags).

No flag bits are currently defined. Set this member to zero - AcxStreamAudioEngineConfigNoFlags.

### `VolumeElement`

An existing ACXVOLUME object that is used for volume operations by the stream audio engine.

### `MuteElement`

An existing ACXMUTE object that is used for mute operations by the stream audio engine.

### `PeakMeterElement`

An existing ACXPEAKMETER object that is used for peakmeter operations by the stream audio engine.

### `Callbacks`

The [ACX_STREAMAUDIOENGINE_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_streamaudioengine_callbacks) that identifies the driver callbacks for ACX audio engine streaming operations.

## Remarks

### Example

Example usage is shown below.

```cpp
        ACX_STREAMAUDIOENGINE_CONFIG audioEngineCfg;
        ACX_STREAMAUDIOENGINE_CONFIG_INIT(&audioEngineCfg);
        audioEngineCfg.VolumeElement = volumeElement;
        audioEngineCfg.MuteElement = muteElement;
        audioEngineCfg.PeakMeterElement = peakmeterElement;
        audioEngineCfg.Callbacks = &streamAudioEngineCallbacks;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)