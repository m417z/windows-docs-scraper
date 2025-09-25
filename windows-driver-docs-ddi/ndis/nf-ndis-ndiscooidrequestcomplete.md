# NdisCoOidRequestComplete function

## Description

The
**NdisCoOidRequestComplete** function returns the final status of an OID request that a CoNDIS client's
or stand-alone call manager's
[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request) function
previously returned NDIS_STATUS_PENDING for.

## Parameters

### `NdisAfHandle` [in]

An address family (AF) handle that NDIS passed to the client or stand-alone call manager's
[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request) function.

### `NdisVcHandle` [in, optional]

A virtual connection (VC) handle that NDIS passed to the client or stand-alone call manager's
*ProtocolCoOidRequest* function. A **NULL** value for this parameter indicates that the request is not
VC-specific. This parameter is **NULL** if the caller of the
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest) or
[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest) function specified a
**NULL** VC handle.

### `NdisPartyHandle` [in, optional]

A party handle that NDIS passed to the client or stand-alone call manager's
*ProtocolCoOidRequest* function. A **NULL** value for this parameter indicates that the request is not
party-specific. This parameter is **NULL** if the caller of the
**NdisCoOidRequest** or
**NdisMCmOidRequest** function specified a **NULL** party handle.

### `OidRequest` [in]

A pointer to a buffer that is formatted as an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure. The caller of
the
**NdisCoOidRequest** or
**NdisMCmOidRequest** function supplied this buffer.

### `Status` [in]

The final status of the request operation, either NDIS_STATUS_SUCCESS, or any driver-determined
NDIS_STATUS_*XXX* status value
except NDIS_STATUS_PENDING.

## Remarks

A CoNDIS protocol driver that returns NDIS_STATUS_PENDING from its
[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request) function must
call
**NdisCoOidRequestComplete** after the protocol driver has finished the request operation.

After a driver calls
**NdisCoOidRequestComplete**, NDIS calls the
[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete) function of the driver that originally called the
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest) or
[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest) function.

Only clients and stand-alone call managers, which register themselves with NDIS as protocol drivers,
can call
**NdisCoOidRequestComplete**. Miniport call managers (MCMs) call the
[NdisMCmOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequestcomplete) function or
[NdisMCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcooidrequestcomplete) instead, depending on whether the MCM driver's
[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request) or
[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request) function,
respectively, handled the client's request.

## See also

[MiniportCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_oid_request)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest)

[NdisMCmOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequest)

[NdisMCmOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmoidrequestcomplete)

[NdisMCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcooidrequestcomplete)

[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request)

[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete)