## Description

The **ACX_VOLUME_CONFIG** structure is used to define the acx volume configuration.

## Members

### `Size`

The length, in bytes, of this structure.

### `Id`

A number that represents the element ID.

### `Name`

A pointer to a GUID that represents the name of the element. Can be used for debugging and will default to GUID_NULL if not provided.

### `Flags`

Acx volume configuration flags defined by the [ACX_VOLUME_CONFIG_FLAGS enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ne-acxelements-acx_volume_config_flags).

No flag bits are currently defined. Set this member to zero - AcxVolumeConfigNoFlags

### `ChannelsCount`

The number of channels. This is a one based count.

### `Maximum`

The maximum boost level for the volume.

### `Minimum`

The minimum boost level for the volume.

### `SteppingDelta`

The stepping delta for the volume.

### `Callbacks`

The [ACX_VOLUME_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_volume_callbacks) that identifies the driver callbacks for ACX volume operations.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_VOLUME_CALLBACKS            volumeCallbacks;
    ACX_VOLUME_CONFIG               volumeCfg;

    ACX_VOLUME_CALLBACKS_INIT(&volumeCallbacks);
    volumeCallbacks.EvtAcxVolumeAssignLevel = CodecC_EvtVolumeAssignLevelCallback;
    volumeCallbacks.EvtAcxVolumeRetrieveLevel = CodecC_EvtVolumeRetrieveLevelCallback;

    ACX_VOLUME_CONFIG_INIT(&volumeCfg);
    volumeCfg.ChannelsCount = MAX_CHANNELS;
    volumeCfg.Minimum = VOLUME_LEVEL_MINIMUM;
    volumeCfg.Maximum = VOLUME_LEVEL_MAXIMUM;
    volumeCfg.SteppingDelta = VOLUME_STEPPING;
    volumeCfg.Callbacks = &volumeCallbacks;

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)