## Description

The **EVT_ACX_AUDIOENGINE_RETRIEVE_EFFECTS_STATE** callback function is implemented by the driver and is called when the global effects state is requested for the specified audio engine node.

## Parameters

### `AudioEngine`

The ACXAUDIOENGINE object for which the global effects state has been requested. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `State`

A ULONG value indicating the global effects state of the specified audio engine node. A nonzero value indicates that global effect processing in the audio engine node is enabled and a value of 0 indicates that global effect processing in the audio engine node is disabled.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
typedef struct _CODEC_ENGINE_CONTEXT {
    ACXDATAFORMAT   MixFormat;
    BOOLEAN         GFxEnabled;
} CODEC_ENGINE_CONTEXT, *PCODEC_ENGINE_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(CODEC_ENGINE_CONTEXT, GetCodecEngineContext)

EVT_ACX_AUDIOENGINE_RETRIEVE_EFFECTS_STATE      Codec_EvtAcxAudioEngineRetrieveEffectsState;

NTSTATUS
Codec_EvtAcxAudioEngineRetrieveEffectsState(
    _In_    ACXAUDIOENGINE  AudioEngine,
    _Out_   PULONG          State
)
{
    PAGED_CODE();

    PCODEC_ENGINE_CONTEXT   pAudioEngineCtx;
    pAudioEngineCtx = GetCodecEngineContext(AudioEngine);

    *State = pAudioEngineCtx->GFxEnabled;

    return STATUS_SUCCESS;
}

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)