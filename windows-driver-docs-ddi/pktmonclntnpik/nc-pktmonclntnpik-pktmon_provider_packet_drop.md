## Description

The **PKTMON_PROVIDER_PACKET_DROP** callback function is invoked by the PktMonClnt application to log packet drop events. This callback is called when a packet is dropped by a monitored component, recording the drop reason and location for diagnostic purposes.

## Parameters

### `ProviderBindingContext`

An opaque context pointer representing the provider binding. This context identifies the specific provider instance handling this packet drop logging operation.

### `CompHandle`

A handle to the component where the packet drop occurred. This handle was returned from a previous **[PKTMON_PROVIDER_REGISTER_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_register_component)** callback invocation.

### `PacketLog`

A pointer to a **[PKTMON_PACKET_LOG_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_log_in)** structure containing information about the dropped packet, including direction, packet type, and optional header information.

### `DropReport`

A pointer to a **[PKTMON_DROP_REPORT_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_drop_report_in)** structure containing the drop reason code and drop location code that explain why and where the packet was dropped.

### `Context`

An optional pointer to a **[PKTMON_PACKET_CONTEXT_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_context_in)** structure containing component-specific context information. Can be NULL.

## Remarks

This callback is part of the **[PKTMON_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_provider_dispatch)** structure and is invoked by the PktMonClnt application to report that a packet was dropped.

## See also

- [PKTMON_PACKET_LOG_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_log_in)
- [PKTMON_DROP_REPORT_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_drop_report_in)
- [PKTMON_PACKET_CONTEXT_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_context_in)
- [PKTMON_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_provider_dispatch)
- [PktMonClntNblDrop](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntnbldrop)
- [PktMonClntHeaderInfoDrop](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntheaderinfodrop)