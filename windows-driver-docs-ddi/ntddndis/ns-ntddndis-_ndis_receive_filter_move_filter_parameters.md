# _NDIS_RECEIVE_FILTER_MOVE_FILTER_PARAMETERS structure

## Description

The **NDIS_RECEIVE_FILTER_MOVE_FILTER_PARAMETERS** structure specifies the parameters for moving a previously created receive filter. A receive filter is moved from a receive queue on a virtual port (VPort) to a receive queue on another VPort.

## Members

### `Header`

The type, revision, and size of the **NDIS_RECEIVE_FILTER_MOVE_FILTER_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_RECEIVE_FILTER_MOVE_FILTER_PARAMETERS** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_RECEIVE_FILTER_MOVE_FILTER_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_RECEIVE_FILTER_MOVE_FILTER_PARAMETERS_REVISION_1.

### `FilterId`

An NDIS_RECEIVE_FILTER_ID value that specifies the identifier of the receive filter.

**Note** The filter specified by this value must have been previously set through an OID method request of [OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter).

### `SourceQueueId`

An NDIS_RECEIVE_QUEUE_ID value that specifies the identifier of the receive queue on which this filter was previously set. For more information, see the Remarks section.

### `SourceVPortId`

An NDIS_NIC_SWITCH_VPORT_ID value that specifies the identifier of the VPort on which this filter was previously set.

### `DestQueueId`

An NDIS_RECEIVE_QUEUE_ID value that specifies the identifier of the receive queue on which the filter is to be moved. For more information, see the Remarks section.

### `DestVPortId`

An NDIS_NIC_SWITCH_VPORT_ID value that specifies the identifier of the VPort on which this filter is to be moved.

## Remarks

This structure is used in OID set requests of [OID_RECEIVE_FILTER_MOVE_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-move-filter).

**Note** Starting with NDIS 6.30, the single root I/O virtualization (SR-IOV) interface allows receive filters to be set only on the default receive queue on both default and nondefault VPorts. The **SourceQueueId** and **DestQueueId** members must always be set to NDIS_DEFAULT_RECEIVE_QUEUE_ID.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_RECEIVE_FILTER_MOVE_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-move-filter)