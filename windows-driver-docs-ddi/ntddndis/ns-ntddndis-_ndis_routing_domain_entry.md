# _NDIS_ROUTING_DOMAIN_ENTRY structure

## Description

The **NDIS_ROUTING_DOMAIN_ENTRY** structure is used by the [OID_GEN_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-isolation-parameters) OID to return the routing domain entries for a VM network adapter's port.

## Members

### `Header`

The type, revision, and size of the **NDIS_ROUTING_DOMAIN_ENTRY** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to **NDIS_OBJECT_TYPE_DEFAULT**. To specify the version of the **NDIS_ROUTING_DOMAIN_ENTRY** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_ROUTING_DOMAIN_ENTRY_REVISION_1

Original version for NDIS 6.40 and later.

Set the **Size** member to **NDIS_SIZEOF_NDIS_ROUTING_DOMAIN_ENTRY_REVISION_1**.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `RoutingDomainId`

The routing domain identifier for the VM network adapter. This identifier is a GUID.

### `RoutingDomainName`

An [NDIS_ISOLATION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_name) structure that contains the routing domain name for the VM network adapter.

### `NumIsolationEntries`

A **ULONG** value that specifies the number of [NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry) structures in the array that follows the [NDIS_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_parameters) structure.

### `FirstIsolationEntryOffset`

A **ULONG** value that specifies the offset, in bytes, to the first **NDIS_ROUTING_DOMAIN_ENTRY** element in the array that follows the [NDIS_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_parameters) structure in the buffer that the **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure points to. The offset is measured from the start of the **NDIS_ROUTING_DOMAIN_ENTRY** structure to the beginning of the first element of the array.

**Note** If the value of **NumRoutingDomainEntries** is zero, this member is ignored.

## See also

[NDIS_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_parameters)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_ROUTING_DOMAIN_ENTRY_GET_NEXT](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-routing-domain-entry-get-next)

[NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_isolation_entry)

[OID_GEN_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-isolation-parameters)