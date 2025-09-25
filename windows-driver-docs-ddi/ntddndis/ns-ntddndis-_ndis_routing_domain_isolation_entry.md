# _NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY structure

## Description

The **NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY** structure is used by the [OID_GEN_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-isolation-parameters) OID to return information relating to a single isolation ID within a routing domain entry for a Hyper-V extensible switch network adapter's port.

## Members

### `Header`

The type, revision, and size of the **NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to **NDIS_OBJECT_TYPE_DEFAULT**. To specify the version of the **NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY_REVISION_1

Original version for NDIS 6.40 and later.

Set the **Size** member to **NDIS_SIZEOF_NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY_REVISION_1**.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `IsolationIdName`

An [NDIS_ISOLATION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_name) structure that contains the isolation ID name for the Hyper-V extensible switch network adapter.

### `VirtualSubnetId`

The virtual switch port ID that will be set on all sent or received packets if untagged packets are allowed..

### `VlanId`

The virtual local area network (VLAN) ID that will be set on all sent or received packets if untagged packets are allowed..

### `IsolationId`

The default isolation ID that will be set on all sent or received packets if untagged packets are allowed. (See the **AllowUntaggedTraffic** member of the [NDIS_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_parameters) structure.)

## See also

[NDIS_ISOLATION_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_name)

[NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY_GET_NEXT](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-routing-domain-isolation-entry-get-next)

[OID_GEN_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-isolation-parameters)