## Description

The **EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_EFFECTS_STATE** callback function is implemented by the driver and is called when the local effects state is requested for the specified stream audio engine.

## Parameters

### `StreamAudioEngine`

An existing, initialized, ACXSTREAMAUDIOENGINE object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `State`

A ULONG value indicating whether local effect processing in the stream audio engine node is enabled. A nonzero value indicates that processing is enabled. A value of 0 indicates that it is disabled.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_EFFECTS_STATE            DspR_EvtAcxStreamAudioEngineRetrieveEffectsState;

NTSTATUS
DspR_EvtAcxStreamAudioEngineRetrieveEffectsState(
    ACXSTREAMAUDIOENGINE    StreamAudioEngine,
    PULONG                  State
)
{
    PAGED_CODE();

    PDSP_STREAMAUDIOENGINE_CONTEXT pStreamAudioEngineCtx;
    pStreamAudioEngineCtx = GetDspStreamAudioEngineContext(StreamAudioEngine);

    *State = pStreamAudioEngineCtx->LFxEnabled;

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)