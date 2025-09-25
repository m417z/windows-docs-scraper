# _NDIS_ISOLATION_PARAMETERS structure

## Description

The **NDIS_ISOLATION_PARAMETERS** structure is used by the [OID_GEN_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-isolation-parameters) OID to return the isolation parameters that are set on a VM network adapter's port.

## Members

### `Header`

The type, revision, and size of the **NDIS_ISOLATION_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to **NDIS_OBJECT_TYPE_DEFAULT**. To specify the version of the **NDIS_ISOLATION_PARAMETERS** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_ISOLATION_PARAMETERS_REVISION_1

Original version for NDIS 6.40 and later.

Set the **Size** member to **NDIS_SIZEOF_NDIS_ISOLATION_PARAMETERS_REVISION_1**.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `IsolationMode`

An [NDIS_ISOLATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_isolation_mode) enumeration value that specifies the isolation mode.

### `AllowUntaggedTraffic`

Specifies whether the VM network adapter's port is allowed to send or receive untagged packets. If untagged packets are allowed, the VM network adapter miniport driver tags untagged packets with the default isolation ID. Otherwise, the miniport driver drops them.

### `NumRoutingDomainEntries`

A **ULONG** value that specifies the number of [NDIS_ROUTING_DOMAIN_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry) in the array that follows the **NDIS_ISOLATION_PARAMETERS** structure.

### `FirstRoutingDomainEntryOffset`

A **ULONG** value that specifies the offset, in bytes, to the first [NDIS_ROUTING_DOMAIN_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry) element in the array that follows the **NDIS_ISOLATION_PARAMETERS** structure. The offset is measured from the start of the **NDIS_ISOLATION_PARAMETERS** structure to the beginning of the first element of the array.

**Note** If the value of **NumRoutingDomainEntries** is zero, this member is ignored.

## See also

[NDIS_ISOLATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_isolation_mode)

[NDIS_ISOLATION_PARAMETERS_GET_FIRST_ROUTING_DOMAIN_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-isolation-parameters-get-first-routing-domain-entry)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_ROUTING_DOMAIN_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_routing_domain_entry)

[NDIS_SWITCH_PORT_PROPERTY_ISOLATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_isolation)

[OID_GEN_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-isolation-parameters)