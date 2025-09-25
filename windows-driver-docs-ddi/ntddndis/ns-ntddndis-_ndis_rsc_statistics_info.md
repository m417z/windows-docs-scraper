# _NDIS_RSC_STATISTICS_INFO structure

## Description

The **NDIS_RSC_STATISTICS_INFO** structure contains statistics that a miniport driver supplies in response to a query of the [OID_TCP_RSC_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-rsc-statistics) OID.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the NDIS_RSC_STATISTICS_INFO structure. Set the **Type** member of the structure that **Header** specifies to NDIS_OBJECT_TYPE_DEFAULT.

To specify the version of the **NDIS_RSC_STATISTICS_INFO** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_RSC_STATISTICS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_RSC_STATISTICS_REVISION_1.

### `CoalescedPkts`

The total number of packets that were coalesced.

### `CoalescedOctets`

The total number of bytes that were coalesced.

### `CoalesceEvents`

The total number of coalescing events. That is, the total number of packets that were formed from coalescing packets.

### `Aborts`

The total number of RSC abort events. That is, the number of exceptions other than the IP datagram length being exceeded. This count should include the cases where a packet is not coalesced because of insufficient hardware resources.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_TCP_RSC_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-rsc-statistics)