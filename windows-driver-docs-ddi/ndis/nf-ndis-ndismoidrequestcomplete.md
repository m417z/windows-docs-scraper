# NdisMOidRequestComplete function

## Description

Miniport drivers call the
**NdisMOidRequestComplete** function to return the final status of an OID request for which the driver's
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function returned
NDIS_STATUS_PENDING.

## Parameters

### `MiniportAdapterHandle` [in]

A miniport adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `OidRequest` [in]

A pointer to a buffer that is formatted as an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure. The miniport
driver obtained this pointer as an input parameter to its
*MiniportOidRequest* function.

### `Status` [in]

The final status of the request operation, either NDIS_STATUS_SUCCESS,
NDIS_STATUS_REQUEST_ABORTED, or any driver-determined NDIS_STATUS_*XXX*except NDIS_STATUS_PENDING. For more information about OID status values, see
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request).

## Remarks

A miniport driver that returns NDIS_STATUS_PENDING from its
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function must
call
**NdisMOidRequestComplete** after the miniport driver has finished the request operation.

A call to
**NdisMOidRequestComplete** causes a call to the request complete function (see
[ProtocolRequestComplete](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff563254(v=vs.85)),
[ProtocolOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_oid_request_complete),
[FilterOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request_complete)) of
the overlying driver that called the
[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function.

## See also

[FilterOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request_complete)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest)

[ProtocolOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_oid_request_complete)

[ProtocolRequestComplete](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff563254(v=vs.85))