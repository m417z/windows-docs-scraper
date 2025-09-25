# NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY_GET_NEXT macro

## Description

Hyper-V extensible switch extensions use the **NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY_GET_NEXT** macro to access the next [**NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry) element that follows an **NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY** structure in the array that is specified by an [**NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_routing_domain) structure.

## Parameters

### `_IsolationInfoEntry_`

A pointer to an **NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY** structure.

## Return value

The **NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY_GET_NEXT** macro returns a pointer to the next [**NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry) element in the array. If the *\_IsolationInfoEntry\_* parameter already points to the last element in the array, the macro returns **NULL**.

## Remarks

## See also

[**NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry)

[**NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_routing_domain)