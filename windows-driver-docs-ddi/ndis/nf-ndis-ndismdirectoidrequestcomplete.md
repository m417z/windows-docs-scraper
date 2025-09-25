# NdisMDirectOidRequestComplete function

## Description

Miniport drivers call the
**NdisMDirectOidRequestComplete** function to return the final status of a direct OID request for which
the driver's
[MiniportDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_direct_oid_request) function returned NDIS_STATUS_PENDING.

## Parameters

### `MiniportAdapterHandle` [in]

A miniport adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `OidRequest` [in]

A pointer to a buffer that is formatted as an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure. The miniport
driver obtained this pointer as an input parameter to its
*MiniportDirectOidRequest* function.

### `Status` [in]

The final status of the request operation: NDIS_STATUS_SUCCESS, NDIS_STATUS_REQUEST_ABORTED, or
any driver-determined NDIS_STATUS_*Xxx*except NDIS_STATUS_PENDING. For more information about OID status values, see
[MiniportDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_direct_oid_request).

## Remarks

A miniport driver that returns NDIS_STATUS_PENDING from its
[MiniportDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_direct_oid_request) function must call
**NdisMDirectOidRequestComplete** after the miniport driver has finished the request operation.

If an overlying driver originated the direct OID request, NDIS calls the request complete function
(see
[ProtocolDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_direct_oid_request_complete) and
[FilterDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request_complete)) of the overlying that originated the request.

## See also

[FilterDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request_complete)

[MiniportDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_direct_oid_request)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[ProtocolDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_direct_oid_request_complete)