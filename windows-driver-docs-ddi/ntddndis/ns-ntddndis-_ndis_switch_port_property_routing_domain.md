# _NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN structure

## Description

The **NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN** structure is used to specify the routing domain properties of a VM network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to **NDIS_OBJECT_TYPE_DEFAULT**. To specify the version of the **NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN_REVISION_1

Original version for NDIS 6.40 and later.

Set the **Size** member to **NDIS_SIZEOF_NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN_REVISION_1**.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `RoutingDomainId`

The routing domain identifier for the VM network adapter. This identifier is a GUID.

### `RoutingDomainName`

An [NDIS_ISOLATION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_name) structure that contains the routing domain name for the VM network adapter.

### `NumIsolationEntries`

A **ULONG** value that specifies the number of [NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry) in the array that follows the **NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN** structure.

#### FirstIsolationEntryOffset

The offset, in bytes, from the beginning of the buffer pointed to by the **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure to the first isolation entry.

### `FirstIsolationEntryOffset`

## See also

[NDIS_ISOLATION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_name)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_ROUTING_DOMAIN_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry)

[NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry)

[NDIS_SWITCH_PROPERTY_PARAMETERS_GET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-property-parameters-get-property)