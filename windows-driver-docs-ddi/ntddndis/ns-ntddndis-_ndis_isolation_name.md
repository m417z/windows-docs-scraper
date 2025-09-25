# _NDIS_ISOLATION_NAME structure

## Description

The **NDIS_ISOLATION_NAME** structure contains an NDIS isolation name for a VM network adapter. The isolation name can be an isolation ID name or a routing domain name. This structure supports the following derived types:
```
typedef NDIS_ISOLATION_NAME NDIS_ISOLATION_ID_NAME, *PNDIS_ISOLATION_ID_NAME;
typedef NDIS_ISOLATION_NAME NDIS_ROUTING_DOMAIN_NAME, *PNDIS_ROUTING_DOMAIN_NAME;

```

## Members

### `Length`

Length, in bytes, of the NDIS isolation name. This member must be less than or equal to **NDIS_ISOLATION_NAME_MAX_STRING_SIZE**.

### `String`

A **NULL**-terminated string that contains the NDIS isolation name. The isolation name can be an isolation ID name or a routing domain name.

## Remarks

This structure is used in:

* The **IsolationIdName** member of the [NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry) structure.
* The **RoutingDomainName** member of the [NDIS_ROUTING_DOMAIN_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry) structure.
* The **RoutingDomainName** member of the [NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_routing_domain) structure.

## See also

[NDIS_ISOLATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_isolation_mode)

[NDIS_ROUTING_DOMAIN_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry)

[NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry)

[NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_routing_domain)