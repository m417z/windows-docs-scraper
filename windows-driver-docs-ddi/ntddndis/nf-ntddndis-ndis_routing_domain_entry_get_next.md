# NDIS_ROUTING_DOMAIN_ENTRY_GET_NEXT macro

## Description

The **NDIS_ROUTING_DOMAIN_ENTRY_GET_NEXT** macro is used to access the next [**NDIS_ROUTING_DOMAIN_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry) element that follows an **NDIS_ROUTING_DOMAIN_ENTRY** structure in the array that is specified by an [**NDIS_ISOLATION_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_parameters) structure.

## Parameters

### `_RoutingDomainEntry_`

A pointer to an **NDIS_ROUTING_DOMAIN_ENTRY** structure.

## Return value

The **NDIS_ROUTING_DOMAIN_ENTRY_GET_NEXT** macro returns a pointer to the next [**NDIS_ROUTING_DOMAIN_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry) element in the array. If the *\_RoutingDomainEntry\_* parameter already points to the last element in the array, the macro returns **NULL**.

## Remarks

## See also

[**NDIS_ISOLATION_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_parameters)

[**NDIS_ISOLATION_PARAMETERS_GET_FIRST_ROUTING_DOMAIN_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/nf-ntddndis-ndis_routing_domain_entry_get_first_isolation_entry)

[**NDIS_ROUTING_DOMAIN_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry)