## Description

The **EvtAcxStreamRun** event tells the driver to transition the stream state from Pause to Run.

## Parameters

### `Stream`

An ACXSTREAM object represents an audio stream created by a circuit. The stream is composed of a list of elements created based on the parent circuit's elements. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

An AcxStream supports different states. These states indicate when audio is flowing (RUN state), audio is not flowing but audio hardware is prepared (PAUSE state), or audio is not flowing and audio hardware is not prepared (STOP state).

The EvtAcxStreamRun event will transition the stream state from the Pause state to the Run state. Once the stream is in the Run state, the driver may receive the [EvtAcxStreamPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_pause) event to transition to the Pause state.

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
    streamCallbacks.EvtAcxStreamRun = EvtStreamRun;
    ...
    status = AcxStreamInitAssignAcxStreamCallbacks(StreamInit, &streamCallbacks);
```

```cpp
_Use_decl_annotations_
PAGED_CODE_SEG
NTSTATUS
EvtStreamRun(
    _In_ ACXSTREAM Stream
    )
{
    PSTREAM_CONTEXT ctx;
    NTSTATUS        status;

    PAGED_CODE();

    ctx = GetStreamContext(Stream);

    status = TransitionStreamToRun(Stream);

    if (NT_SUCCESS(status))
    {
        ctx->StreamState = AcxStreamStateRun;
    }

    return status;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)
- [EVT_ACX_STREAM_PREPARE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_prepare_hardware)
- [EVT_ACX_STREAM_PAUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_pause)
- [EVT_ACX_STREAM_RELEASE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_release_hardware)