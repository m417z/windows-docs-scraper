## Description

The **PKTMON_NETEVT_CLIENT_DISPATCH_V2** structure represents version 2 of the Packet Monitor NetEvt NMR client dispatch table, containing callback functions for the client module. This structure extends the original dispatch table by adding capture type information to control which packet events (flow, drop, or both) are monitored.

## Members

### `Header`

A **[PKTMON_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_header)** structure containing version and size information for this dispatch table. The *Header* field enables version control and ensures proper structure alignment between client and provider modules.

### `CaptureType`

A **[PKTMON_CAPTURE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ne-pktmondefk-pktmon_capture_type)** value specifying the type of packets to capture. This field determines whether the client monitors all packets, only flow packets, only dropped packets, or no packets at all.

### `HandlerCount`

The number of callback handler functions in the *Handlers* array. This count specifies how many event handler functions the client provides for processing packet events.

### `Handlers`

Pointer to an array of handler functions that the client provides for processing packet monitoring events. These callback functions are invoked by the provider when relevant packet events occur.

## Remarks

The client module must ensure this structure remains valid and resident in memory as long as the provider module is attached. A pointer to this structure is typically passed through the *ClientDispatch* parameter when calling **[NmrClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientattachprovider)**. Version 2 differs from the original **[PKTMON_NETEVT_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnetevtnpik/ns-pktmonnetevtnpik-pktmon_netevt_client_dispatch)** by including the *CaptureType* field to provide more granular control over which packet events are monitored.

## See also

- [PKTMON_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_header)
- [PKTMON_CAPTURE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ne-pktmondefk-pktmon_capture_type)
- [PKTMON_NETEVT_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnetevtnpik/ns-pktmonnetevtnpik-pktmon_netevt_client_dispatch)