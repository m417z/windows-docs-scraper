# _NDIS_SWITCH_NIC_STATUS_INDICATION structure

## Description

The **NDIS_SWITCH_NIC_STATUS_INDICATION** structure specifies the information that is required to forward or originate an NDIS status indication from an underlying physical network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_NIC_STATUS_INDICATION** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_NIC_STATUS_INDICATION** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_NIC_STATUS_INDICATION_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_SWITCH_NIC_STATUS_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `SourcePortId`

An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the Hyper-V extensible switch port from which the NDIS status indication was originally generated.

### `SourceNicIndex`

An NDIS_SWITCH_NIC_INDEX value that specifies the index of the source network adapter that is connected to the source extensible switch port. This port is specified by the **SourcePortId** member.

### `DestinationPortId`

An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the extensible switch port to which the NDIS status indication is to be forwarded.

### `DestinationNicIndex`

An NDIS_SWITCH_NIC_INDEX value that specifies the index of the destination network adapter that is connected to the extensible switch port specified by the **DestinationPortId** member.

### `StatusIndication`

A pointer to an [NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) structure. This structure contains the data for the NDIS status indication originally issued by the source network adapter as specified by the **SourcePortId** and **SourceNicIndex** members.

## Remarks

The **NDIS_SWITCH_NIC_STATUS_INDICATION** structure is used in NDIS status indications of [NDIS_STATUS_SWITCH_NIC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-switch-nic-status).

An extension can forward or originate status indications from any underlying physical adapter that is connected to the extensible switch [external network adapter](https://learn.microsoft.com/windows-hardware/drivers/network/external-network-adapters). Typically, the extension issues these status indications in order to change the advertised hardware offload capabilities of the underlying physical adapter.

The extension can forward or originate status notifications for the following types of hardware offloads:

* Internet Protocol security (IPsec).
* Virtualized machine queue (VMQ).
* Single root I/O virtualization (SR-IOV).

For guidelines on how to issue NDIS status indications from underlying physical adapters, see [Managing NDIS Status Indications from Physical Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/managing-ndis-status-indications-from-physical-network-adapters).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[NDIS_SWITCH_NIC_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_nic_status_indication)