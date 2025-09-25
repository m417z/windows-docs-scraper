## Description

**EvtAcxStreamGetCurrentPacket** tells the driver to indicate which packet (0-based) is currently being rendered to the hardware or is currently being filled by the capture hardware.

## Parameters

### `Stream`

An ACXSTREAM object represents an audio stream created by a circuit. The stream is composed of a list of elements created based on the parent circuit's elements. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `CurrentPacket`

A zero based index to the packet that is currently being rendered to the hardware or is currently being filled by the capture hardware.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    //
    // Init RT streaming callbacks.
    //
    ACX_RT_STREAM_CALLBACKS rtCallbacks;
    ACX_RT_STREAM_CALLBACKS_INIT(&rtCallbacks);

    rtCallbacks.EvtAcxStreamGetCurrentPacket = EvtStreamGetCurrentPacket;

    status = AcxStreamInitAssignAcxRtStreamCallbacks(StreamInit, &rtCallbacks);
```

```cpp
PAGED_CODE_SEG
NTSTATUS
EvtStreamGetCurrentPacket(
    _In_ ACXSTREAM          Stream,
    _Out_ PULONG            CurrentPacket
)
{
    PSTREAM_CONTEXT ctx;

    PAGED_CODE();

    ctx = GetStreamContext(Stream);

    *CurrentPacket = ctx->CurrentPacket;

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)