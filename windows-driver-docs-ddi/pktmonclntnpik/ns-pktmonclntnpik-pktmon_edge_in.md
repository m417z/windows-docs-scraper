## Description

The **PKTMON_EDGE_IN** structure contains information about a monitoring edge being added to a component. An edge represents a packet monitoring boundary where packets can be tracked as they flow through the component.

## Members

### `Header`

A [PKTMON_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_header) structure used for versioning and size validation.

### `Name`

A Unicode string containing the name of the edge. This name is used for identification in packet logs and diagnostic output.

### `DirTagIn`

A Unicode string tag for inbound packet direction at this edge. This tag appears in packet logs to identify packets entering through this monitoring point.

### `DirTagOut`

A Unicode string tag for outbound packet direction at this edge. This tag appears in packet logs to identify packets leaving through this monitoring point.

## Remarks

## See also

- [PKTMON_PROVIDER_ADD_EDGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_add_edge)
- [PktMonClntAddEdge](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntaddedge)
- [PKTMON_EDGE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_edge_context)