## Description

The **EVT_ACX_STREAMAUDIOENGINE_ASSIGN_LOOPBACK_PROTECTION** callback is implemented by the driver and is called when the loopback protection status is set for an audio engine node.

## Parameters

### `StreamAudioEngine`

An existing, initialized, ACXSTREAMAUDIOENGINE object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ConstrictorOption`

The [ACX_CONSTRICTOR_OPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ne-acxelements-acx_constrictor_option) that specifies the loopback protection status of the stream audio engine. The status can either be set to AcxConstrictorOptionNone or AcxConstrictorOptionMute. If there are any active streams with AcxConstrictorOptionMute in effect, then the loopback tap for this audio output will emit silence. If all the active stream have AcxConstrictorOptionNone in effect, then the loopback tap contains meaningful data.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
EVT_ACX_STREAMAUDIOENGINE_ASSIGN_LOOPBACK_PROTECTION        CodecR_EvtAcxStreamAudioEngineAssignLoopbackProtection;

NTSTATUS
CodecR_EvtAcxStreamAudioEngineAssignLoopbackProtection(
    _In_    ACXSTREAMAUDIOENGINE    StreamAudioEngine,
    _In_    ACX_CONSTRICTOR_OPTION  ConstrictorOption
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

        status = streamEngine->SetLoopbackProtection(ConstrictorOption);
    }

    return status;
}

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)