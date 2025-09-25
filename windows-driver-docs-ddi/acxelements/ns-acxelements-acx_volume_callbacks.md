## Description

The **ACX_VOLUME_CALLBACKS** structure identifies the driver callbacks for ACX volume operations.

## Members

### `Size`

The length, in bytes, of this structure.

### `EvtAcxVolumeAssignLevel`

The [EVT_ACX_VOLUME_ASSIGN_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_volume_assign_level) callback.

### `EvtAcxRampedVolumeAssignLevel`

The [EVT_ACX_RAMPED_VOLUME_ASSIGN_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_ramped_volume_assign_level) callback.

### `EvtAcxVolumeRetrieveLevel`

The [EVT_ACX_VOLUME_RETRIEVE_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_volume_retrieve_level) callback.

### `EvtAcxVolumeProcessRequest`

The [EVT_ACX_OBJECT_PROCESS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nc-acxrequest-evt_acx_object_process_request) callback.

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