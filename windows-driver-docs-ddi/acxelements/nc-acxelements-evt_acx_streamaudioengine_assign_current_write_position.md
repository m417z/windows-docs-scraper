## Description

The **EVT_ACX_STREAMAUDIOENGINE_ASSIGN_CURRENT_WRITE_POSITION** callback function is implemented by the driver and is called when the current write position for the specified stream audio engine is set.

## Parameters

### `StreamAudioEngine`

An existing, initialized, ACXSTREAMAUDIOENGINE object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Position`

The current write position for the ACXSTREAMAUDIOENGINE object in bytes. For more information on the position value, see [KSPROPERTY_AUDIO_WAVERT_CURRENT_WRITE_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-wavert-current-write-position).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
EVT_ACX_STREAMAUDIOENGINE_ASSIGN_CURRENT_WRITE_POSITION     CodecR_EvtAcxStreamAudioEngineAssignCurrentWritePosition;

NTSTATUS
CodecR_EvtAcxStreamAudioEngineAssignCurrentWritePosition(
    _In_    ACXSTREAMAUDIOENGINE    StreamAudioEngine,
    _In_    ULONG                   Position
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

        status = streamEngine->SetCurrentWritePosition(Position);
    }

    return status;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)