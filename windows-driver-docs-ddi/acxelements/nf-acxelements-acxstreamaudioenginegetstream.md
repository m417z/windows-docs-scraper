## Description

The **AcxStreamAudioEngineGetStream** function retrieves the ACXSTREAM object associated with the given stream audio engine object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `StreamAudioEngine`

An existing, initialized, ACXSTREAMAUDIOENGINE object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
NTSTATUS
DspR_EvtAcxStreamAudioEngineRetrievePresentationPosition(
    _In_    ACXSTREAMAUDIOENGINE    StreamAudioEngine,
    _Out_   PULONGLONG              PositionInBlocks,
    _Out_   PULONGLONG              QPCPosition
)
{
    NTSTATUS status = STATUS_INVALID_PARAMETER;
    ACXSTREAM stream;
    PDSP_STREAM_CONTEXT ctx;
    COffloadStreamEngine* streamEngine = NULL;

    PAGED_CODE();

    stream = AcxStreamAudioEngineGetStream(StreamAudioEngine);
    if (stream)
    {
        ctx = GetDspStreamContext(stream);

        streamEngine = static_cast<COffloadStreamEngine*>(ctx->StreamEngine);

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