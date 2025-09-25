## Description

The **ACX_STREAMAUDIOENGINE_CALLBACKS** structure identifies the driver callbacks for ACX stream audio engine operations.

## Members

### `Size`

The length, in bytes, of this structure.

### `EvtAcxStreamAudioEngineAssignEffectsState`

The [EVT_ACX_STREAMAUDIOENGINE_ASSIGN_EFFECTS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_streamaudioengine_assign_effects_state) callback.

### `EvtAcxStreamAudioEngineRetrieveEffectsState`

The [EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_EFFECTS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_streamaudioengine_retrieve_effects_state) callback.

### `EvtAcxStreamAudioEngineRetrievePresentationPosition`

The [EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_PRESENTATION_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_streamaudioengine_retrieve_presentation_position) callback.

### `EvtAcxStreamAudioEngineAssignCurrentWritePosition`

The [EVT_ACX_STREAMAUDIOENGINE_ASSIGN_CURRENT_WRITE_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_streamaudioengine_assign_current_write_position) callback.

### `EvtAcxStreamAudioEngineRetrieveLinearBufferPosition`

The [EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_LINEAR_BUFFER_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_streamaudioengine_retrieve_linear_buffer_position) callback.

### `EvtAcxStreamAudioEngineAssignLastBufferPosition`

The [EVT_ACX_STREAMAUDIOENGINE_ASSIGN_LAST_BUFFER_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_streamaudioengine_assign_last_buffer_position) callback.

### `EvtAcxStreamAudioEngineAssignLoopbackProtection`

The [EVT_ACX_STREAMAUDIOENGINE_ASSIGN_LOOPBACK_PROTECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_streamaudioengine_assign_loopback_protection) callback.

### `EvtAcxStreamAudioEngineProcessRequest`

The [EVT_ACX_OBJECT_PROCESS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nc-acxrequest-evt_acx_object_process_request) callback.

## Remarks

### Example

Example usage is shown below.

```cpp
        ACX_STREAMAUDIOENGINE_CALLBACKS streamAudioEngineCallbacks;

        // Create the AudioEngine element to control offloaded streaming.
        ACX_STREAMAUDIOENGINE_CALLBACKS_INIT(&streamAudioEngineCallbacks);

        streamAudioEngineCallbacks.EvtAcxStreamAudioEngineAssignEffectsState = CodecR_EvtAcxStreamAudioEngineAssignEffectsState;
        streamAudioEngineCallbacks.EvtAcxStreamAudioEngineRetrieveEffectsState = CodecR_EvtAcxStreamAudioEngineRetrieveEffectsState;
        streamAudioEngineCallbacks.EvtAcxStreamAudioEngineRetrievePresentationPosition = CodecR_EvtAcxStreamAudioEngineRetrievePresentationPosition;
        streamAudioEngineCallbacks.EvtAcxStreamAudioEngineAssignCurrentWritePosition = CodecR_EvtAcxStreamAudioEngineAssignCurrentWritePosition;
        streamAudioEngineCallbacks.EvtAcxStreamAudioEngineRetrieveLinearBufferPosition = CodecR_EvtAcxStreamAudioEngineRetrieveLinearBufferPosition;
        streamAudioEngineCallbacks.EvtAcxStreamAudioEngineAssignLastBufferPosition = CodecR_EvtAcxStreamAudioEngineAssignLastBufferPosition;
        streamAudioEngineCallbacks.EvtAcxStreamAudioEngineAssignLoopbackProtection = CodecR_EvtAcxStreamAudioEngineAssignLoopbackProtection;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)