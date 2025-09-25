## Description

**EvtAcxStreamGetPresentationPosition** tells the driver to indicate the current position along with the QPC value at the time the current position was calculated.

## Parameters

### `Stream`

An ACXSTREAM object represents an audio stream created by a circuit. The stream is composed of a list of elements created based on the parent circuit's elements. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `PositionInBlocks`

Specifies the block offset from the start of the stream to the current post-decoded, uncompressed position in the stream. A "block" refers to the group of channels in the same sample. So, for example, in a PCM stream a block is the same as a frame. However, for compressed formats a block is a single sample within a frame. This means that for a typical MP3 stream that has 1152 samples in a frame, there are 1152 blocks.

### `QPCPosition`

Specifies the value of the performance counter at the time that the audio driver reads the presentation position in response to the KSAUDIO_PRESENTATION_POSITION call. A driver writes to this field with the value read from calling [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryperformancecounter) when a snapshot is taken of the presentation position.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    //
    // Init streaming callbacks.
    //
    ACX_RT_STREAM_CALLBACKS rtCallbacks;
    ACX_RT_STREAM_CALLBACKS_INIT(&rtCallbacks);

    rtCallbacks.EvtAcxStreamGetPresentationPosition = EvtStreamGetPresentationPosition;

    status = AcxStreamInitAssignAcxRtStreamCallbacks(StreamInit, &rtCallbacks);
```

```cpp
PAGED_CODE_SEG
NTSTATUS
EvtStreamGetPresentationPosition(
    _In_ ACXSTREAM      Stream,
    _Out_ PULONGLONG    PositionInBlocks,
    _Out_ PULONGLONG    QPCPosition
)
{
    PSTREAM_CONTEXT ctx;
    ULONG               blockAlign;
    LARGE_INTEGER       qpc;

    PAGED_CODE();

    ctx = GetStreamContext(Stream);

    blockAlign = AcxDataFormatGetBlockAlign(ctx->StreamFormat);

    // Recalculate the stream position that is stored in ctx->StreamPosition
    UpdateStreamPosition(Stream);
    qpc = KeQueryPerformanceCounter(NULL);

    *PositionInBlocks = ctx->StreamPosition / blockAlign;
    *QPCPosition = qpc;

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)