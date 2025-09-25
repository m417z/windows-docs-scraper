# _NDIS_WMI_EVENT_HEADER structure

## Description

The NDIS_WMI_EVENT_HEADER structure provides information about a GUID event for WMI clients.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for this
NDIS_WMI_EVENT_HEADER structure. Set the
**Type** member of NDIS_OBJECT_HEADER to NDIS_WMI_OBJECT_TYPE_EVENT, the
**Revision** member to NDIS_WMI_EVENT_HEADER_REVISION_1, and the
**Size** member to
sizeof(NDIS_WMI_EVENT_HEADER).

### `IfIndex`

The NDIS interface index of the NDIS miniport adapter interface that is associated with the
GUID.

### `NetLuid`

The NDIS network interface name of the miniport adapter.

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

### `PortNumber`

The miniport adapter port, if any. If the GUID is not specific to a port,
**PortNumber** is zero.

### `DeviceNameLength`

The length, in bytes, of the device name.

### `DeviceNameOffset`

The offset, in bytes, to the beginning of the device name from the beginning of the
NDIS_WMI_EVENT_HEADER structure.

### `Padding`

This member is reserved.

## Remarks

NDIS translates NDIS status indications to WMI GUID event indications.

WMI GUID event indications that are specific to NDIS 6.0 and later versions include an
NDIS_WMI_EVENT_HEADER structure that is followed by the GUID-specific data, if any.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)