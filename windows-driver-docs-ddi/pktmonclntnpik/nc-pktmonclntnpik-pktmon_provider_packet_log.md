## Description

The **PKTMON_PROVIDER_PACKET_LOG** callback function is invoked by the PktMonClnt application to log packet flow events. This callback is called when a packet successfully flows through a monitored component edge, as opposed to being dropped.

## Parameters

### `ProviderBindingContext`

An opaque context pointer representing the provider binding. This context identifies the specific provider instance handling this packet logging operation.

### `EdgeHandle`

A handle to the edge where the packet flow event occurred. This handle was returned from a previous **[PKTMON_PROVIDER_ADD_EDGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_add_edge)** callback invocation.

### `PacketLog`

A pointer to a **[PKTMON_PACKET_LOG_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_log_in)** structure containing information about the packet being logged, including direction, packet type, and optional header information.

### `Context`

An optional pointer to a **[PKTMON_PACKET_CONTEXT_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_context_in)** structure containing component-specific context information, such as a connection ID. Can be NULL.

## Remarks

This callback is part of the **[PKTMON_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_provider_dispatch)** structure and is invoked by the PktMonClnt application to report that a packet successfully flowed through a monitoring point.

## See also

- [PKTMON_PACKET_LOG_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_log_in)
- [PKTMON_PACKET_CONTEXT_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_context_in)
- [PKTMON_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_provider_dispatch)
- [PktMonClntNblLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntnbllog)
- [PktMonClntHeaderInfoLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntheaderinfolog)