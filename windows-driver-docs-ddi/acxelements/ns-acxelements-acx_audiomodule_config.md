## Description

The **ACX_AUDIOMODULE_CONFIG** structure is used to define the audio module configuration.

## Members

### `Size`

The length, in bytes, of this structure.

### `Id`

A number that represents the element ID.

### `Name`

A pointer to a GUID that represents the name of the element. Can be used for debugging and will default to GUID_NULL if not provided.

### `Flags`

Audio module configuration flags defined by the [ACX_AUDIOMODULE_CONFIG_FLAGS enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ne-acxelements-acx_audiomodule_config_flags).

No flag bits are currently defined. Set this member to zero - AcxAudioModuleConfigNoFlags

### `Descriptor`

An [ACX_AUDIOMODULE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_audiomodule_descriptor) structure that describes the audio module.

### `Callbacks`

The [ACX_AUDIOMODULE_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_audiomodule_callbacks) that identifies the driver callbacks for ACX audio module operations.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_AUDIOMODULE_CALLBACKS       audioModuleCallbacks;
    ACX_AUDIOMODULE_CONFIG          audioModuleCfg;
    ACXAUDIOMODULE                  audioModuleElement;

    // Now add audio modules to the circuit
    // module 0

    ACX_AUDIOMODULE_CALLBACKS_INIT(&audioModuleCallbacks);
    audioModuleCallbacks.EvtAcxAudioModuleProcessCommand = CodecR_EvtProcessCommand0;

    ACX_AUDIOMODULE_CONFIG_INIT(&audioModuleCfg);
    audioModuleCfg.Name = &AudioModule0Id;
    audioModuleCfg.Descriptor.ClassId = AudioModule0Id;
    audioModuleCfg.Descriptor.InstanceId = AUDIOMODULE_INSTANCE_ID(0,0);
    audioModuleCfg.Descriptor.VersionMajor = AUDIOMODULE0_MAJOR;
    audioModuleCfg.Descriptor.VersionMinor = AUDIOMODULE0_MINOR;
    wcsncpy_s(audioModuleCfg.Descriptor.Name,
                ACX_AUDIOMODULE_MAX_NAME_CCH_SIZE,
                AUDIOMODULE0DESCRIPTION,
                wcslen(AUDIOMODULE0DESCRIPTION));
    audioModuleCfg.Callbacks = &audioModuleCallbacks;

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)