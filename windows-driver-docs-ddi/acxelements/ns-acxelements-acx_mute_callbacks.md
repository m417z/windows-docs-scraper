## Description

The **ACX_MUTE_CALLBACKS** structure identifies the driver callbacks for ACX mute operations.

## Members

### `Size`

The length, in bytes, of this structure.

### `EvtAcxMuteAssignState`

The [EVT_ACX_MUTE_ASSIGN_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_mute_assign_state) callback.

### `EvtAcxMuteRetrieveState`

The [EVT_ACX_MUTE_RETRIEVE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_mute_retrieve_state) callback.

### `EvtAcxMuteProcessRequest`

The [EVT_ACX_OBJECT_PROCESS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nc-acxrequest-evt_acx_object_process_request) callback.

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