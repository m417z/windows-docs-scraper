## Description

The **ACX_RTPACKET** structure represents a single allocated packet. The PacketBuffer must be a Memory Descriptor List (MDL).

## Members

### `Size`

The size of the ACX_RTPACKET structure in bytes.

### `RtPacketBuffer`

A [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure that is used as a buffer. Only WdfMemoryDescriptorTypeMdl and WdfMemoryDescriptorTypeInvalid are supported.

The RtPacketBuffer must be valid for the first ACX_RTPACKET in an array of ACX_RTPACKET structures. The RtPacketBuffer must be PAGE-aligned with a PAGE-aligned size.

### `RtPacketOffset`

The zero-based offset in bytes in the RtPacketBuffer at which the actual audio packet starts.

### `RtPacketSize`

The size in bytes of the allocated packet.

## Remarks

The ACX framework currently only supports WdfMemoryDescriptorTypeMdl packet buffers.

See [EVT_ACX_STREAM_ALLOCATE_RTPACKETS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_allocate_rtpackets) for details on allocating ACX_RTPACKET structures.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)
- [EVT_ACX_STREAM_ALLOCATE_RTPACKETS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_allocate_rtpackets)