## Description

The **ACX_MUTE_CONFIG** structure is used to define the acx mute configuration.

## Members

### `Size`

The length, in bytes, of this structure.

### `Id`

A number that represents the element ID.

### `Name`

A pointer to a GUID that represents the name of the element. Can be used for debugging and will default to GUID_NULL if not provided.

### `Flags`

Acx mute configuration flags defined by the [ACX_MUTE_CONFIG_FLAGS enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ne-acxelements-acx_mute_config_flags).

No flag bits are currently defined. Set this member to zero - AcxMuteConfigNoFlags.

### `ChannelsCount`

The number of channels. This is a one based count.

### `Callbacks`

The [ACX_MUTE_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_mute_callbacks) that identifies the driver callbacks for ACX mute operations.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_MUTE_CALLBACKS              muteCallbacks;
    ACX_MUTE_CONFIG                 muteCfg;
    ACXMUTE                         muteElement;

    //
    // Create three elements to handle mute for the audioengine element
    //
    ACX_MUTE_CALLBACKS_INIT(&muteCallbacks);
    muteCallbacks.EvtAcxMuteAssignState = CodecR_EvtMuteAssignState;
    muteCallbacks.EvtAcxMuteRetrieveState = CodecR_EvtMuteRetrieveState;

    ACX_MUTE_CONFIG_INIT(&muteCfg);
    muteCfg.ChannelsCount = MAX_CHANNELS;
    muteCfg.Name = &KSAUDFNAME_WAVE_MUTE;
    muteCfg.Callbacks = &muteCallbacks;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)