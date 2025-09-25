## Description

The **ACX_STREAM_CALLBACKS_INIT** function initializes the ACX stream callbacks.

## Parameters

### `Callbacks`

A [ACX_STREAM_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_stream_callbacks) structure.

## Remarks

### Example

```cpp

  ACX_STREAM_CALLBACKS        streamCallbacks;

    //
    // Init streaming callbacks.
    //
    ACX_STREAM_CALLBACKS_INIT(&streamCallbacks);
    streamCallbacks.EvtAcxStreamPrepareHardware = EvtStreamPrepareHardware;
    streamCallbacks.EvtAcxStreamReleaseHardware = EvtStreamReleaseHardware;
    streamCallbacks.EvtAcxStreamRun = EvtStreamRun;
    streamCallbacks.EvtAcxStreamPause = EvtStreamPause;
    streamCallbacks.EvtAcxStreamAssignDrmContentId = EvtStreamAssignDrmContentId;

    status = AcxStreamInitAssignAcxStreamCallbacks(StreamInit, &streamCallbacks);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxStreamInitAssignAcxStreamCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxstreaminitassignacxstreamcallbacks)
- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)