# _NDIS_WMI_SET_HEADER structure

## Description

The NDIS_WMI_SET_HEADER structure provides information about a GUID set request from WMI
clients.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for this
NDIS_WMI_SET_HEADER structure. Set the
**Type** member of NDIS_OBJECT_HEADER to NDIS_WMI_OBJECT_TYPE_SET, the
**Revision** member to NDIS_WMI_SET_HEADER_REVISION_1, and the
**Size** member to
sizeof(NDIS_WMI_SET_HEADER).

### `PortNumber`

The miniport adapter port, if any. If the GUID is not specific to a port,
**PortNumber** is zero. WMI clients can use the
[GUID_NDIS_GEN_ENUMERATE_PORTS](https://learn.microsoft.com/windows-hardware/drivers/network/guid-ndis-gen-enumerate-ports) GUID to obtain a list of the ports that are associated with a
miniport adapter.

### `NetLuid`

The NDIS network interface name of the miniport adapter. WMI clients can use the
[GUID_NDIS_ENUMERATE_ADAPTERS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/guid-ndis-enumerate-adapters-ex) GUID to find a device name and the associated
**NetLuid** value.

### `RequestId`

An identifier for the request. If a miniport driver must complete a request immediately and it
completes the request with a status of NDIS_STATUS_INDICATION_REQUIRED, the miniport driver uses this
**RequestId** value to set the
**RequestId** member of the associated
[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) structure.

NDIS or overlying drivers can also use the
**RequestId** to cancel a request. When a miniport driver receives a
cancellation request, the miniport driver cancels any pending requests with a matching
**RequestId**. If
**RequestId** is zero, the miniport driver can ignore this member.

For more information about this member, see
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request).

### `Timeout`

A time-out, in seconds, for the request. NDIS can reset the driver or cancel the request if the
time-out expires before the driver completes the request.

For more information about this member, see
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request).

### `Padding`

This member is reserved

## Remarks

NDIS translates WMI GUID set requests to NDIS OID requests.

WMI GUID set requests that are specific to NDIS 6.0 and later versions include an NDIS_WMI_SET_HEADER
structure that is followed by the GUID-specific data, if any.

## See also

[GUID_NDIS_ENUMERATE_ADAPTERS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/guid-ndis-enumerate-adapters-ex)

[GUID_NDIS_GEN_ENUMERATE_PORTS](https://learn.microsoft.com/windows-hardware/drivers/network/guid-ndis-gen-enumerate-ports)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)