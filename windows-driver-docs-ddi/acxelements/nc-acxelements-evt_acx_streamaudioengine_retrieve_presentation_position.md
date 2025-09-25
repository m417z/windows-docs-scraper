## Description

The **EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_PRESENTATION_POSITION** callback function is implemented by the driver and is called to retrieve the current position within the audio data being rendered to the stream audio engine node.

## Parameters

### `StreamAudioEngine`

An existing, initialized, ACXSTREAMAUDIOENGINE object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `PositionInBlocks`

Specifies the block offset from the start of the stream to the current post-decoded, uncompressed position in the stream. See [KSAUDIO_PRESENTATION_POSITION structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksaudio_presentation_position) for more information on this value.

### `QPCPosition`

Specifies the value of the performance counter at the time that the audio driver reads the presentation position in response to the callback. See [KSAUDIO_PRESENTATION_POSITION structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksaudio_presentation_position) for more information on this value.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_PRESENTATION_POSITION    CodecR_EvtAcxStreamAudioEngineRetrievePresentationPosition;

NTSTATUS
CodecR_EvtAcxStreamAudioEngineRetrievePresentationPosition(
    _In_    ACXSTREAMAUDIOENGINE    StreamAudioEngine,
    _Out_   PULONGLONG              PositionInBlocks,
    _Out_   PULONGLONG              QPCPosition
)
{
    NTSTATUS status = STATUS_INVALID_PARAMETER;
    ACXSTREAM stream;
    PCODEC_STREAM_CONTEXT ctx;
    CRenderStreamEngine * streamEngine = NULL;

    PAGED_CODE();

    stream = AcxStreamAudioEngineGetStream(StreamAudioEngine);
    if (stream)
    {
        ctx = GetCodecStreamContext(stream);

        streamEngine = static_cast<CRenderStreamEngine*>(ctx->StreamEngine);

        status = streamEngine->GetPresentationPosition(PositionInBlocks, QPCPosition);
    }

    return status;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)