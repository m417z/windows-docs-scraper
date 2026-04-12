## Description

The **PKTMON_PROVIDER_ADD_EDGE** callback function is invoked by the PktMonClnt application to add an edge to a registered component. An edge represents a packet monitoring boundary (entry/exit point) where packets flow through the component, allowing the component to report packet events at specific boundaries.

## Parameters

### `ProviderBindingContext`

An opaque context pointer representing the provider binding. This context identifies the specific provider instance handling this operation.

### `CompHandle`

A handle to the component to which the edge will be added. This handle was returned from a previous **[PKTMON_PROVIDER_REGISTER_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_register_component)** callback invocation.

### `Edge`

A pointer to a **[PKTMON_EDGE_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_edge_in)** structure containing information about the edge being added, including its name and packet type.

### `EdgeHandle`

A pointer to a handle that receives the edge handle upon successful addition. This handle is used when logging or reporting packet events at this edge.

## Return value

Returns `STATUS_SUCCESS` if the edge is successfully added. Otherwise, returns an appropriate `NTSTATUS` error code indicating the failure reason.

## Remarks

This callback is part of the **[PKTMON_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_provider_dispatch)** structure and is invoked by the PktMonClnt application. Components can have multiple edges representing different monitoring points.

## See also

- [PKTMON_EDGE_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_edge_in)
- [PKTMON_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_provider_dispatch)
- [PktMonClntAddEdge](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntaddedge)