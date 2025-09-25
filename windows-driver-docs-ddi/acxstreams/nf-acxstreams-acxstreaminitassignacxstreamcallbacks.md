## Description

The **AcxStreamInitAssignAcxStreamCallbacks** function sets the callbacks using an [ACX_STREAM_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_stream_callbacks) and an ACXSTREAM_INIT object. For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `StreamInit`

Address of a ACXSTREAM_INIT object used to define the stream initialization parameters.

### `StreamCallbacks`

An [ACX_STREAM_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_stream_callbacks) that is used to define the following callbacks.

- PFN_ACX_STREAM_PREPARE_HARDWARE
- PFN_ACX_STREAM_RELEASE_HARDWARE
- PFN_ACX_STREAM_RUN
- PFN_ACX_STREAM_PAUSE
- PFN_ACX_STREAM_ASSIGN_DRM_CONTENT_ID

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_STREAM_CALLBACKS            streamCallbacks;
    //
    // Init streaming callbacks.
    //
    ACX_STREAM_CALLBACKS_INIT(&streamCallbacks);
    streamCallbacks.EvtAcxStreamPrepareHardware     = Dsp_EvtStreamPrepareHardware;
    streamCallbacks.EvtAcxStreamReleaseHardware     = Dsp_EvtStreamReleaseHardware;
    streamCallbacks.EvtAcxStreamRun                 = Dsp_EvtStreamRun;
    streamCallbacks.EvtAcxStreamPause               = Dsp_EvtStreamPause;

    status = AcxStreamInitAssignAcxStreamCallbacks(StreamInit, &streamCallbacks);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)