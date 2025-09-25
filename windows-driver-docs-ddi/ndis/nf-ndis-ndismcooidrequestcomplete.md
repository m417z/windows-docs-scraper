# NdisMCoOidRequestComplete function

## Description

The
**NdisMCoOidRequestComplete** function returns the final status of an OID request that a miniport driver's
[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request) function
returned NDIS_STATUS_PENDING for.

## Parameters

### `MiniportAdapterHandle` [in]

A miniport adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `NdisMiniportVcHandle`

A handle that identifies the virtual connection (VC). The miniport driver obtained this handle as
an input parameter to its
[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc) function, either
when a client set up an outgoing call or when the call manager created a VC for a client-registered
service access point (SAP). The call manager created the VC to indicate an incoming-call notification.
If the request is
not VC-specific, this parameter is **NULL**.

### `Request`

A pointer to a buffer that is formatted as an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure. The miniport
driver obtained this pointer as an input parameter to its
[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request) function.

### `Status` [in]

The final status of the request operation, either NDIS_STATUS_SUCCESS,
NDIS_STATUS_REQUEST_ABORTED, or any driver-determined NDIS_STATUS_*XXX* value
except NDIS_STATUS_PENDING.

## Remarks

A CoNDIS miniport driver that returns NDIS_STATUS_PENDING from its
[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request) function must
call
**NdisMCoOidRequestComplete** after the miniport driver has finished the request operation.

A call to
**NdisMCoOidRequestComplete** causes a call to the
[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete) function of the overlying driver that called the
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest) function.

## See also

[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc)

[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest)

[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete)