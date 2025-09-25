# _NDIS_SWITCH_NIC_OID_REQUEST structure

## Description

The **NDIS_SWITCH_NIC_OID_REQUEST** structure specifies the information that is required to forward or originate OID requests.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_NIC_OID_REQUEST** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_NIC_OID_REQUEST** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_NIC_OID_REQUEST_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_NIC_OID_REQUEST_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `SourcePortId`

An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the Hyper-V extensible switch port to which the OID request was originally issued.

### `SourceNicIndex`

An NDIS_SWITCH_NIC_INDEX value that specifies the index of the source network adapter that is connected to the source extensible switch port specified by the **SourcePortId** member.

### `DestinationPortId`

An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the extensible switch port to which the OID request is to be forwarded.

### `DestinationNicIndex`

An NDIS_SWITCH_NIC_INDEX value that specifies the index of the destination network adapter that is connected to the extensible switch port specified by the **DestinationPortId** member.

### `OidRequest`

A pointer to an [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure. This structure contains the data for the OID request that will be forwarded to the miniport driver of the network adapter specified by the **DestinationPortId** and **DestinationNicIndex** members.

## Remarks

The **NDIS_SWITCH_NIC_OID_REQUEST** structure is used in OID method requests of [OID_SWITCH_NIC_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-request).

An extension can forward or originate OID requests to underlying physical network adapters in the extensible switch driver stack. This enables an extension to do the following:

* Manage the configuration of hardware offloads on an underlying physical adapter for the following offload technologies:

  + Internet Protocol security (IPsec).
  + Virtualized machine queue (VMQ).
  + Single root I/O virtualization (SR-IOV).
* Query the configuration of an underlying physical network adapter by issuing standard NDIS OIDs. For example, the extension can issue an OID query request of [OID_802_3_CURRENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-current-address) to obtain the adapter's current media access control (MAC) address.

For guidelines on how to issue OID requests to underlying physical adapters, see [Managing OID Requests to Physical Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/managing-oid-requests-to-physical-network-adapters).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[OID_SWITCH_NIC_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-request)