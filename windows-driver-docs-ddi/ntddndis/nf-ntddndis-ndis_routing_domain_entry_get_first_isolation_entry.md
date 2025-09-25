# NDIS_ROUTING_DOMAIN_ENTRY_GET_FIRST_ISOLATION_ENTRY macro

## Description

The **NDIS_ROUTING_DOMAIN_ENTRY_GET_FIRST_ISOLATION_ENTRY** macro is used to access the first [**NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry) that is specified by an [**NDIS_ROUTING_DOMAIN_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry) structure.

## Parameters

### `_RoutingDomainEntry_`

A pointer to an **NDIS_ROUTING_DOMAIN_ENTRY** structure.

## Return value

The **NDIS_ROUTING_DOMAIN_ENTRY_GET_FIRST_ISOLATION_ENTRY** macro returns a pointer to the first [**NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry) element in the array.

## Remarks

## See also

[**NDIS_ROUTING_DOMAIN_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry)

[**NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry)