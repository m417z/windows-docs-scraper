## Description

The **ACX_AUDIOENGINE_CALLBACKS** structure defines callbacks for the ACX audio engine.

## Members

### `Size`

The length, in bytes, of this structure.

### `EvtAcxAudioEngineRetrieveBufferSizeLimits`

The [EVT_ACX_AUDIOENGINE_RETRIEVE_BUFFER_SIZE_LIMITS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_audioengine_retrieve_buffer_size_limits) callback.

### `EvtAcxAudioEngineAssignEffectsState`

The [EVT_ACX_AUDIOENGINE_ASSIGN_EFFECTS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_audioengine_assign_effects_state) callback.

### `EvtAcxAudioEngineRetrieveEffectsState`

The [EVT_ACX_AUDIOENGINE_RETRIEVE_EFFECTS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_audioengine_retrieve_effects_state) callback.

### `EvtAcxAudioEngineRetrieveEngineMixFormat`

The [EVT_ACX_AUDIOENGINE_RETRIEVE_ENGINE_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_audioengine_retrieve_engine_format) callback.

### `EvtAcxAudioEngineAssignEngineDeviceFormat`

The [EVT_ACX_AUDIOENGINE_ASSIGN_ENGINE_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_audioengine_assign_engine_format) callback.

### `EvtAcxAudioEngineProcessRequest`

The [EVT_ACX_OBJECT_PROCESS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nc-acxrequest-evt_acx_object_process_request) callback.

## Remarks

### Example

Example usage is shown below.

```cpp
  ACX_AUDIOENGINE_CALLBACKS       audioEngineCallbacks;

  ACX_AUDIOENGINE_CALLBACKS_INIT(&audioEngineCallbacks);
    audioEngineCallbacks.EvtAcxAudioEngineRetrieveBufferSizeLimits = CodecR_EvtAcxAudioEngineRetrieveBufferSizeLimits;
    audioEngineCallbacks.EvtAcxAudioEngineAssignEffectsState = CodecR_EvtAcxAudioEngineAssignEffectsState;
    audioEngineCallbacks.EvtAcxAudioEngineRetrieveEffectsState = CodecR_EvtAcxAudioEngineRetrieveEffectsState;
    audioEngineCallbacks.EvtAcxAudioEngineRetrieveEngineMixFormat = CodecR_EvtAcxAudioEngineRetrieveEngineMixFormat;
    audioEngineCallbacks.EvtAcxAudioEngineAssignEngineDeviceFormat = CodecR_EvtAcxAudioEngineAssignEngineDeviceFormat;

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)