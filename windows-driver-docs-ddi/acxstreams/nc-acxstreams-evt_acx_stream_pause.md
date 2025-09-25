## Description

The **EvtAcxStreamPause** event tells the driver to transition the stream state from Run to Pause.

## Parameters

### `Stream`

An ACXSTREAM object represents an audio stream created by a circuit. The stream is composed of a list of elements created based on the parent circuit's elements. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

An AcxStream supports different states. These states indicate when audio is flowing (RUN state), audio is not flowing but audio hardware is prepared (PAUSE state), or audio is not flowing and audio hardware is not prepared (STOP state).

The EvtAcxStreamPause event will transition the stream state from the Run state to the Pause state. Once the stream is in the Pause state, the driver may receive the [EvtAcxStreamRun](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_run) event to transition to the Run state or the driver may receive the [EvtAcxStreamReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_release_hardware) event to transition to the Stop state.

During ACX device power down and removal, if streams are present, ACX will call the EvtAcxStreamPause to transition streams to Pause. This is Stream Instance scoped.

ACX Events are analogous to KS states as described in this table.

| Start State | End State | ACX Driver Event Called | Notes |
|-------------|-----------|-------------------------|-------------------------------------------------------|
| STOP | ACQUIRE | PrepareHardware | Driver performs hardware allocations and preparations |
| ACQUIRE | PAUSE | (No Call) | |
| PAUSE | RUN | Run | |
| RUN | PAUSE | Pause | |
| PAUSE | ACQUIRE | (No call) | |
| ACQUIRE | STOP | ReleaseHardware | Driver releases hardware allocations |

### Example

Example usage is shown below.

```cpp
    ACX_STREAM_CALLBACKS streamCallbacks;
    ACX_STREAM_CALLBACKS_INIT(&streamCallbacks);
    streamCallbacks.EvtAcxStreamPause = EvtStreamPause;
    ...
    status = AcxStreamInitAssignAcxStreamCallbacks(StreamInit, &streamCallbacks);
```

```cpp
#pragma code_seg("PAGE")
NTSTATUS
EvtStreamPause(
    _In_ ACXSTREAM Stream
    )
{
    PSTREAM_CONTEXT ctx;
    NTSTATUS        status = STATUS_SUCCESS;

    PAGED_CODE();

    ctx = GetStreamContext(Stream);

    status = TransitionStreamToPause(Stream);

    ctx->StreamState = AcxStreamStatePause;

    return status;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)
- [EVT_ACX_STREAM_PREPARE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_prepare_hardware)
- [EVT_ACX_STREAM_RUN_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_run)
- [EVT_ACX_STREAM_RELEASE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_release_hardware)