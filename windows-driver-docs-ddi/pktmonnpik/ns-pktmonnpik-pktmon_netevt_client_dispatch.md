## Description

The **PKTMON_NETEVT_CLIENT_DISPATCH** structure contains the Packet Monitor NetEvt NMR client dispatch table of [NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) callback functions for the client module. A pointer to this structure is passed through the *ClientDispatch* parameter when calling **[NmrClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientattachprovider)**.

## Members

### `Header`

Represents header information as described in **[PKTMON_NETEVT_DISPATCH_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_netevt_dispatch_header)**.

### `HandlerCount`

The number of handler functions.

### `Handlers`

Pointer to the list of handler functions.

## Remarks

The client module must make sure that this structure remains valid and resident in memory as long as the provider module is attached to the client module. The contents of the structure are NPI-specific.

## See also

- [NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface)
- **[NmrClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientattachprovider)**
- **[PKTMON_NETEVT_DISPATCH_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_netevt_dispatch_header)**