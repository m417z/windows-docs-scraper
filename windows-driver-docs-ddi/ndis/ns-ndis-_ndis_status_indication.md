# _NDIS_STATUS_INDICATION structure

## Description

NDIS and underlying drivers use the NDIS_STATUS_INDICATION structure to provide status indications to
overlying protocol drivers.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_STATUS_INDICATION structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_STATUS_INDICATION, the
**Revision** member to NDIS_STATUS_INDICATION_REVISION_1, and the
**Size** member to NDIS_SIZEOF_STATUS_INDICATION_REVISION_1.

### `SourceHandle`

The source of the status indication. If the source is a miniport adapter, it should be the handle
that NDIS passed to the
*MiniportAdapterHandle* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function. If
the source is a filter module, it should be the handle that NDIS passed to the
*NdisFilterHandle* parameter of the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `PortNumber`

The source port of the status indication. If the status indication is not specific to a port, set
**PortNumber** to zero.

### `StatusCode`

The status code, either provided by NDIS or propagated from the underlying drivers. The value is
an NDIS_STATUS_*XXX* code. For more information about NDIS_STATUS_*XXX* codes, see
[Status Indications](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

### `Flags`

The type of information in the status buffer at
**StatusBuffer** . Miniport drivers set this member to zero. This member is reserved for NDIS.

### `DestinationHandle`

A handle that identifies the overlying driver that should receive the status indication. If **NULL**,
NDIS indicates the status to each protocol driver that is bound to the miniport adapter. If non-**NULL**,
NDIS indicates the status only to the driver that
**DestinationHandle** identifies. In this case the driver must also set the
**RequestId** member. For more information about OID requests, see the Remarks section.

### `RequestId`

The OID request that is associated with the status indication. If there is no OID request that is
associated with the status indication,
**RequestId** is **NULL**. Miniport drivers must set the
**RequestId** member if the status indication is associated with an OID request that the miniport
driver completed with a returned status of NDIS_STATUS_INDICATION_REQUIRED. In this case, the driver
must also set the
**DestinationHandle** member.

For more information about OID requests, see the following Remarks section.

### `StatusBuffer`

A pointer to a buffer that contains medium-specific data that depends on the value at
**StatusCode** .

For example, if
**StatusCode** is
[NDIS_STATUS_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-link-state), this
parameter points to an
[NDIS_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_link_state) structure and
**StatusBufferSize** is
sizeof(NDIS_LINK_STATE).

For some NDIS_STATUS_*XXX* values, this pointer is **NULL** and
**StatusBufferSize** is set to zero.

### `StatusBufferSize`

The length, in bytes, of the status information buffer at
**StatusBuffer** .

### `Guid`

A private GUID that NDIS uses to generate a WMI notification. For more information about private
GUIDs, see
[OID_GEN_SUPPORTED_GUIDS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-supported-guids).

### `NdisReserved`

Reserved for NDIS.

## Remarks

Miniport drivers indicate status by calling the
[NdisMIndicateStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatestatusex) function.
Filter drivers call the
[NdisFIndicateStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfindicatestatus) function.

Some OID requests enable a miniport driver to provide an OID completion status with a status
indication. In this case, the miniport driver returns NDIS_STATUS_INDICATION_REQUIRED for the completion
status of the OID request. A miniport driver cannot return this status unless the particular OID allows
it. To determine if this status is allowed, see the OID reference page.

If a status indication is associated with an OID request where the miniport driver returned
NDIS_STATUS_INDICATION_REQUIRED, the driver that is making the status indication must set the
**DestinationHandle** and
**RequestId** members in the NDIS_STATUS_INDICATION structure.

In this case, the driver sets the
**DestinationHandle** and
**RequestId** members to the values from the
**RequestHandle** and
**RequestId** members in the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure,
respectively.

For example, in wireless networking, the processing of an OID request can take a very long time to
complete. In this case, the miniport driver can complete the OID request immediately and provide a status
indication later to provide the final result for the OID request.

Protocol drivers receive status indications at the
[ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex) function. Filter
drivers receive status indications at the
[FilterStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_status) function.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_status)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_link_state)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_STATUS_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-link-state)

[NDIS_TAPI_EVENT](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff558986(v=vs.85))

[NdisFindicateStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfindicatestatus)

[NdisMIndicateStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatestatusex)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[OID_GEN_SUPPORTED_GUIDS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-supported-guids)

[ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex)