# _NDIS_RECEIVE_FILTER_INFO structure

## Description

The **NDIS_RECEIVE_FILTER_INFO** structure contains information about a receive filter that is currently configured on a miniport driver.

NDIS receive filters are used in the following NDIS interfaces:

* [NDIS Packet Coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing). For more information about how to use receive filters in this interface, see [Managing Packet Coalescing Receive Filters](https://learn.microsoft.com/windows-hardware/drivers/network/managing-packet-coalescing-receive-filters).
* [Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/single-root-i-o-virtualization--sr-iov-). For more information about how to use receive filters in this interface, see [Setting a Receive Filter on a Virtual Port](https://learn.microsoft.com/windows-hardware/drivers/network/setting-a-receive-filter-on-a-virtual-port).
* [Virtual Machine Queue (VMQ)](https://learn.microsoft.com/windows-hardware/drivers/network/virtual-machine-queue-architecture). For more information about how to use receive filters in this interface, see [Setting and Clearing VMQ Filters](https://learn.microsoft.com/windows-hardware/drivers/network/setting-and-clearing-vmq-filters).

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_FILTER_INFO** structure. The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT.

To indicate the version of the **NDIS_RECEIVE_FILTER_INFO** structure, the driver sets the
**Revision** member to one of the following values:

#### NDIS_RECEIVE_FILTER_INFO_REVISION_1

Original version for NDIS 6.20.

The driver sets the
**Size** member to NDIS_SIZEOF_RECEIVE_FILTER_INFO_REVISION_1.

### `Flags`

A bitwise OR of flags. This member is reserved for NDIS.

### `FilterType`

The type of the receive filter.

### `FilterId`

A receive filter identifier. The filter identifier
is an integer from one up to and including the number of receive filters that the network adapter
supports. A value of zero is not valid.

## Remarks

The **NDIS_RECEIVE_FILTER_INFO** structure is used with the
[NDIS_RECEIVE_FILTER_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_info_array) structure for the
OID request of [OID_RECEIVE_FILTER_ENUM_FILTERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-enum-filters). This OID request enumerates receive filters that have been configured on the miniport driver. This includes packet coalescing receive filters or the receive filters configured on a receive queue that is used in the VMQ or SR-IOV interface.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RECEIVE_FILTER_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_info_array)

[OID_RECEIVE_FILTER_ENUM_FILTERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-enum-filters)