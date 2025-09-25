# _NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS structure

## Description

The **NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS** structure specifies the receive filtering features that are
enabled or disabled on a network adapter.

NDIS receive filters are used in the following NDIS interfaces:

* [NDIS Packet Coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing). For more information about how to use receive filters in this interface, see [Managing Packet Coalescing Receive Filters](https://learn.microsoft.com/windows-hardware/drivers/network/managing-packet-coalescing-receive-filters).
* [Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/single-root-i-o-virtualization--sr-iov-). For more information about how to use receive filters in this interface, see [Setting a Receive Filter on a Virtual Port](https://learn.microsoft.com/windows-hardware/drivers/network/setting-a-receive-filter-on-a-virtual-port).
* [Virtual Machine Queue (VMQ)](https://learn.microsoft.com/windows-hardware/drivers/network/virtual-machine-queue-architecture). For more information about how to use receive filters in this interface, see [Setting and Clearing VMQ Filters](https://learn.microsoft.com/windows-hardware/drivers/network/setting-and-clearing-vmq-filters).

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS** structure. The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT.

To indicate the version of the **NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS** structure, the driver sets the
**Revision** member to one of the following values:

#### NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS_REVISION_1

Original version for NDIS 6.20.

The driver sets the
**Size** member to NDIS_SIZEOF_RECEIVE_FILTER_GLOBAL_PARAMETERS_REVISION_1.

### `Flags`

A bitwise OR of flags. This member is reserved for NDIS.

### `EnabledFilterTypes`

A bitwise OR of flags for types of enabled receive filters. The
following filter type flag is valid.

#### NDIS_RECEIVE_FILTER_VMQ_FILTERS_ENABLED

Specifies that VMQ filters are enabled.

**Note** The miniport driver should set this flag if the miniport driver is enabled to use the SR-IOV interface. For more information on how these interfaces are enabled, see [Handling SR-IOV, VMQ, and RSS Standardized INF Keywords](https://learn.microsoft.com/windows-hardware/drivers/network/handling-sr-iov--vmq--and-rss-standardized-inf-keywords).

#### NDIS_RECEIVE_FILTER_PACKET_COALESCING_FILTERS_ENABLED

Specifies that NDIS packet coalescing receive filters are enabled.

### `EnabledQueueTypes`

A bitwise OR of flags for types of enabled receive queues. The
following queue type flag is valid.

#### NDIS_RECEIVE_FILTER_VM_QUEUES_ENABLED

Specifies that virtual machine (VM) queues are enabled. VM queues are used in the VMQ and SR-IOV interface.

## Remarks

The **NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS** structure is used in the
[OID_RECEIVE_FILTER_GLOBAL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-global-parameters) query OID to obtain the current global receive filter
settings.

**Note** Many of the members and flag settings of the **NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS** structure are valid if the miniport driver is enabled to use the VMQ or SR-IOV interface. The miniport driver is enabled to use these interfaces through standardized INF keywords. For more information, see [Handling SR-IOV, VMQ, and RSS Standardized INF Keywords](https://learn.microsoft.com/windows-hardware/drivers/network/handling-sr-iov--vmq--and-rss-standardized-inf-keywords).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_RECEIVE_FILTER_GLOBAL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-global-parameters)