## Description

The **EVT_ACX_AUDIOENGINE_RETRIEVE_ENGINE_FORMAT** callback is implemented by the driver and is called when the internal mix format is requested for the specified audio engine.

## Parameters

### `AudioEngine`

The ACXAUDIOENGINE object for which the mix format has been requested. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Format`

The ACXDATAFORMAT object that describes the audio engine mix format.

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

EVT_ACX_AUDIOENGINE_RETRIEVE_ENGINE_FORMAT      CodecR_EvtAcxAudioEngineRetrieveEngineMixFormat;

NTSTATUS
NTAPI
CodecR_EvtAcxAudioEngineRetrieveEngineMixFormat(
    _In_    ACXAUDIOENGINE  AudioEngine,
    _Out_   ACXDATAFORMAT * Format
    )
{
    PCODEC_ENGINE_CONTEXT   audioEngineCtx;
    PAGED_CODE();

    audioEngineCtx = GetCodecEngineContext(AudioEngine);

    if (!audioEngineCtx->MixFormat)
    {
        return STATUS_INVALID_DEVICE_STATE;
    }

    *Format = audioEngineCtx->MixFormat;

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)