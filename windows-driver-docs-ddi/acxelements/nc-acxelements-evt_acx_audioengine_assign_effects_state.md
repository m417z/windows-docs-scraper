## Description

The **EVT_ACX_AUDIOENGINE_ASSIGN_EFFECTS_STATE** callback function is implemented by the driver and is called when the global effects state is set for an audio engine node. The global effects state can be set to TRUE or FALSE, where TRUE indicates that global effect processing in the audio engine node is enabled and FALSE indicates that global effect processing in the audio engine node is disabled.

## Parameters

### `AudioEngine`

An ACXAUDIOENGINE object that is used in a render circuit to represent a DSP. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `State`

The State value is of type ULONG but gets converted to type BOOLEAN in the callback to indicate whether global effect processing in the audio engine node is enabled. A value of TRUE indicates that processing is enabled. FALSE indicates that it is disabled.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
typedef struct _DSP_ENGINE_CONTEXT
{
    ACXDATAFORMAT MixFormat;
    BOOLEAN GFxEnabled;
} DSP_ENGINE_CONTEXT, *PDSP_ENGINE_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DSP_ENGINE_CONTEXT, GetDspEngineContext)

EVT_ACX_AUDIOENGINE_ASSIGN_EFFECTS_STATE        DspR_EvtAcxAudioEngineAssignEffectsState;

NTSTATUS
DspR_EvtAcxAudioEngineAssignEffectsState(
    ACXAUDIOENGINE  AudioEngine,
    ULONG           State
)
{
    PAGED_CODE();

    PDSP_ENGINE_CONTEXT   pAudioEngineCtx;
    pAudioEngineCtx = GetDspEngineContext(AudioEngine);

    pAudioEngineCtx->GFxEnabled = (BOOLEAN)State;

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)