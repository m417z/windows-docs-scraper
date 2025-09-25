## Description

The **AcxStreamInitAssignAcxRtStreamCallbacks** function sets the RT callbacks using an ACXSTREAM_INIT object and a [ACX_RT_STREAM_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_rt_stream_callbacks). For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `StreamInit`

Address of a ACXSTREAM_INIT object used to define the stream initialization parameters.

### `RtStreamCallbacks`

An [ACX_RT_STREAM_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_rt_stream_callbacks) that defines the list of callbacks.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_RT_STREAM_CALLBACKS         rtCallbacks;

    //
    // Init RT streaming callbacks.
    //
    ACX_RT_STREAM_CALLBACKS_INIT(&rtCallbacks);
    rtCallbacks.EvtAcxStreamGetHwLatency            = Dsp_EvtStreamGetHwLatency;
    rtCallbacks.EvtAcxStreamAllocateRtPackets       = Dsp_EvtStreamAllocateRtPackets;
    rtCallbacks.EvtAcxStreamFreeRtPackets           = Dsp_EvtStreamFreeRtPackets;
    rtCallbacks.EvtAcxStreamGetCapturePacket        = DspC_EvtStreamGetCapturePacket;
    rtCallbacks.EvtAcxStreamGetCurrentPacket        = Dsp_EvtStreamGetCurrentPacket;
    rtCallbacks.EvtAcxStreamGetPresentationPosition = Dsp_EvtStreamGetPresentationPosition;

    status = AcxStreamInitAssignAcxRtStreamCallbacks(StreamInit, &rtCallbacks);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)