## Description

The **PKTMON_EVT_STREAM_PACKET_DESCRIPTOR** structure contains a packet descriptor used for event streaming.

## Members

### `PacketOriginalLength`

The original packet length.

### `PacketLoggedLength`

Represents the length of the part of the packet that was logged. This will be same as *PacketOriginalLength* if the packet was not truncated when logged, otherwise it will be shorter.

### `PacketMetaDataLength`

Length of the metadata.

> [!NOTE]
> It's important to rely on *PacketMetaDataLength* instead of the size of structure **[PKTMON_EVT_STREAM_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_evt_stream_metadata)** as this structure might increase in size in future releases.

## Remarks

## See also

- **[PKTMON_EVT_STREAM_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_evt_stream_metadata)**