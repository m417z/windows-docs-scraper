## Description

The **PKTMON_NETEVT_CLIENT_REPORT_PACKET_EVENT_OUT** structure contains the start and end pointers of the buffer containing packet event information. This structure is used as an output parameter when reporting packet flow events through the NetEvt interface.

## Members

### `BufferStart`

Pointer to the beginning of the buffer containing the packet event information. This marks the starting address of the event data that has been written.

### `BufferEnd`

Pointer to the end of the buffer containing the packet event information. This marks the address immediately after the last byte of valid event data.

## Remarks

The buffer bounded by *BufferStart* and *BufferEnd* typically contains a **[PKTMON_EVT_STREAM_PACKET_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnetevtnpik/ns-pktmonnetevtnpik-pktmon_evt_stream_packet_header)** followed by the packet metadata and payload data.

## See also

- [PKTMON_EVT_STREAM_PACKET_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnetevtnpik/ns-pktmonnetevtnpik-pktmon_evt_stream_packet_header)
- [PKTMON_NETEVT_CLIENT_REPORT_PACKET_DROP_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnetevtnpik/ns-pktmonnetevtnpik-pktmon_netevt_client_report_packet_drop_out)
- [PKTMON_NETEVT_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnetevtnpik/ns-pktmonnetevtnpik-pktmon_netevt_provider_dispatch)