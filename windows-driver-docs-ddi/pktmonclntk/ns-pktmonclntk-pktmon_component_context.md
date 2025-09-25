## Description

The **PKTMON_COMPONENT_CONTEXT** structure holds the context for the component.

## Members

### `ListLink`

A **[LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry)** structure that links this component to the list of components belonging to this client.

### `EdgeList`

The list of edges for this component. An edge represents a pair of entry/exit points for a component. Use *EdgeList* to track all the edge contexts that belong to a component and to access these edge contexts.

### `EdgeCount`

The number of entries in *EdgeList*.

### `CompHandle`

The handle for the component.

### `CompType`

The type of the component.

### `PacketType`

The type of packet being handled by the component.

### `FlowEnabled`

Indicates if flow logging is enabled.

### `DropEnabled`

Indicates if dropped packet logging is enabled.

## Remarks

This structure should be zero-initialized before **[PktMonClntComponentRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntcomponentregister)** is called and **PktMonClntComponentRegister** will fill in the structure as needed.

## See also

- **[LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry)**
- **[PktMonClntComponentRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntcomponentregister)**