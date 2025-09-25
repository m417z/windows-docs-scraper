# NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN_GET_FIRST_ISOLATION_ENTRY macro

## Description

The **NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN_GET_FIRST_ISOLATION_ENTRY** macro is used to access the first [**NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry) that is specified by an [**NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_routing_domain) structure.

## Parameters

### `_RoutingDomainProperty_`

A pointer to an **NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN** structure.

## Return value

The **NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN_GET_FIRST_ISOLATION_ENTRY** macro returns a pointer to the first [**NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry).

## Remarks

## See also

[**NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry)

[**NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_routing_domain)