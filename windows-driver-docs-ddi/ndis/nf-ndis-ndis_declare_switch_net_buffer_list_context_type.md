# NDIS_DECLARE_SWITCH_NET_BUFFER_LIST_CONTEXT_TYPE macro

## Description

Hyper-V extensible switch extensions use the **NDIS_DECLARE_SWITCH_NET_BUFFER_LIST_CONTEXT_TYPE** macro to define the context type that is used by the [*SetNetBufferListSwitchContext*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_set_net_buffer_list_switch_context) and [*GetNetBufferListSwitchContext*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_switch_context) functions to attach and retrieve context from a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. Extensions can define as many context types as they want within their driver.

## Parameters

### `_ContextName`

An identifier for the context type.

### `_ExtensionId`

A GUID that matches the extension ID.

## Remarks

## See also

[*SetNetBufferListSwitchContext*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_set_net_buffer_list_switch_context)

[*GetNetBufferListSwitchContext*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_switch_context)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)