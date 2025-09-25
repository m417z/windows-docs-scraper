# _NDIS_OPER_STATE structure

## Description

The NDIS_OPER_STATE structure provides the current operational state of an NDIS network
interface.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_OPER_STATE structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_OPER_STATE_REVISION_1, and the
**Size** member to NDIS_SIZEOF_OPER_STATE_REVISION_1.

### `OperationalStatus`

The
[NET_IF_OPER_STATUS](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_oper_status) operational status
type.

### `OperationalStatusFlags`

This member provides the reason why the
**OperationalStatus** member is set to **NET_IF_OPER_STATUS_DOWN** or NET_IF_OPER_STATUS_DORMANT. This
member is a ULONG value that contains a bitwise OR of a combination of the following flags:

#### NET_IF_OPER_STATUS_DOWN_NOT_AUTHENTICATED

The operational status is set to **NET_IF_OPER_STATUS_DOWN** because the default port of the
miniport adapter is not authenticated.

#### NET_IF_OPER_STATUS_DOWN_NOT_MEDIA_CONNECTED

The operational status is set to **NET_IF_OPER_STATUS_DOWN** because the miniport adapter is not in
a media-connected state.

#### NET_IF_OPER_STATUS_DORMANT_PAUSED

The operational status is set to **NET_IF_OPER_STATUS_DORMANT** because the miniport adapter is in
the paused or pausing state.

#### NET_IF_OPER_STATUS_DORMANT_LOW_POWER

The operational status is set to **NET_IF_OPER_STATUS_DORMANT** because the miniport adapter is in a
low power state.

## Remarks

For the
[NDIS_STATUS_OPER_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-oper-status) status
indication, NDIS supplies an NDIS_OPER_STATE structure in the
**StatusBuffer** member of the
[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) structure.

NDIS_STATUS_OPER_STATUS indicates the current operational state of an NDIS network interface to
overlying drivers.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[NDIS_STATUS_OPER_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-oper-status)

[NET_IF_OPER_STATUS](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_oper_status)