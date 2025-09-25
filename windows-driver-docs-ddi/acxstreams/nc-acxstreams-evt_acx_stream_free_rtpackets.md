## Description

The **EvtAcxStreamFreeRtPackets** event tells the driver to free the RtPackets that were allocated in a previous call to EvtAcxStreamAllocateRtPackets. The same packets from that call are included.

## Parameters

### `Stream`

An ACXSTREAM Object represents an audio stream created by a circuit. The stream is composed of a list of elements created based on the parent circuit's elements. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Packets`

A pointer to an array of [ACX_RTPACKET structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_rtpacket) that describes the location and size of the packets to be freed.

### `PacketCount`

Specifies the number of packets to be freed. Valid values are 1 or 2.

## Remarks

When work with the stream is complete, EvtAcxStreamFreeRtPackets is called after [EvtAcxStreamReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_release_hardware). This allows the release hardware phase to finish deallocating bandwidth, freeing DMA resources and any other associated cleanup, to occur before te allocated RT buffers are then freed.

### Example

Example usage is shown below.

```cpp
    // Init RT streaming callbacks.
    //
    ACX_RT_STREAM_CALLBACKS rtCallbacks;
    ACX_RT_STREAM_CALLBACKS_INIT(&rtCallbacks);
    rtCallbacks.EvtAcxStreamFreeRtPackets               = Dsp_EvtStreamFreeRtPackets;

    RETURN_NTSTATUS_IF_FAILED(AcxStreamInitAssignAcxRtStreamCallbacks(StreamInit, &rtCallbacks));

// Later in the code need to free the packets...
#pragma code_seg("PAGE")
VOID
Codec_EvtStreamFreeRtPackets(
    _In_ ACXSTREAM Stream,
    _In_ PACX_RTPACKET Packets,
    _In_ ULONG PacketCount
    )
{
    PCODEC_STREAM_CONTEXT ctx;
    ULONG i;
    PVOID buffer;

    PAGED_CODE();

    ctx = GetCodecStreamContext(Stream);

    for (i = 0; i < PacketCount; ++i)
    {
        if (Packets[i].RtPacketBuffer.u.MdlType.Mdl)
        {
            buffer = MmGetMdlVirtualAddress(Packets[i].RtPacketBuffer.u.MdlType.Mdl);
            IoFreeMdl(Packets[i].RtPacketBuffer.u.MdlType.Mdl);
            ExFreePool(buffer);
        }
    }

    ExFreePool(Packets);

    ctx->PacketsCount = 0;
    ctx->PacketSize = 0;
    ctx->FirstPacketOffset = 0;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)