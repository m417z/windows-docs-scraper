## Description

The **EvtAcxStreamGetHwLatency** event tells the driver to provide stream latency for the specific circuit of this stream (overall latency will be a sum of the latency of the different circuits).

## Parameters

### `Stream`

An ACXSTREAM object represents an audio stream created by a circuit. The stream is composed of a list of elements created based on the parent circuit's elements. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `FifoSize`

The FifoSize in bytes.

### `Delay`

The Delay in 100-nanosecond units.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

Example usage is shown below.

```cpp
    //
    // Init streaming callbacks.
    //
    ACX_RT_STREAM_CALLBACKS rtCallbacks;
    ACX_RT_STREAM_CALLBACKS_INIT(&rtCallbacks);

    rtCallbacks.EvtAcxStreamGetHwLatency = EvtStreamGetHwLatency;

    status = AcxStreamInitAssignAcxRtStreamCallbacks(StreamInit, &rtCallbacks));
```

```cpp
PAGED_CODE_SEG
NTSTATUS
EvtStreamGetHwLatency(
    _In_ ACXSTREAM Stream,
    _Out_ ULONG * FifoSize,
    _Out_ ULONG * Delay
)
{
    PSTREAM_CONTEXT ctx;

    PAGED_CODE();

    ctx = GetStreamContext(Stream);

    *FifoSize = ctx->DmaFifoSize;
    *Delay = ctx->ChipsetDelay + ctx->CodecDelay;

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)