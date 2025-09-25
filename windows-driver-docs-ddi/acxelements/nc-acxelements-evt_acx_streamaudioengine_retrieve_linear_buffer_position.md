## Description

The **EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_LINEAR_BUFFER_POSITION** callback is implemented by the driver and is called when the linear buffer position is requested for the specified stream audio engine.

## Parameters

### `StreamAudioEngine`

An existing, initialized, ACXSTREAMAUDIOENGINE object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Position`

A ULONGLONG value that represents the number of bytes that the DMA has fetched from the audio buffer of the specified stream audio engine since the beginning of the stream.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_LINEAR_BUFFER_POSITION   CodecR_EvtAcxStreamAudioEngineRetrieveLinearBufferPosition;

NTSTATUS
CodecR_EvtAcxStreamAudioEngineRetrieveLinearBufferPosition(
    _In_    ACXSTREAMAUDIOENGINE    StreamAudioEngine,
    _Out_   PULONGLONG              Position
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

        status = streamEngine->GetLinearBufferPosition(Position);
    }

    return status;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)