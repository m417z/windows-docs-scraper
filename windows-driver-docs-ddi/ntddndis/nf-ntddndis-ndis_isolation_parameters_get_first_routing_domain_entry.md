# NDIS_ISOLATION_PARAMETERS_GET_FIRST_ROUTING_DOMAIN_ENTRY macro

## Description

The **NDIS_ISOLATION_PARAMETERS_GET_FIRST_ROUTING_DOMAIN_ENTRY** macro is used to access the first [**NDIS_ROUTING_DOMAIN_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry) that is specified by an [**NDIS_ISOLATION_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_parameters) structure.

## Parameters

### `_MultiTenancyInfo_`

A pointer to an **NDIS_ISOLATION_PARAMETERS** structure.

## Return value

The **NDIS_ISOLATION_PARAMETERS_GET_FIRST_ROUTING_DOMAIN_ENTRY** macro returns a pointer to the first [**NDIS_ROUTING_DOMAIN_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry) element in the array.

## Remarks

## See also

[**NDIS_ISOLATION_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_parameters)

[**NDIS_ROUTING_DOMAIN_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry)