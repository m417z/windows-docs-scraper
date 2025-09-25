# NdisMCmOidRequestComplete macro

## Description

The
**NdisMCmOidRequestComplete** function returns the final status of a CoNDIS OID request that a miniport
call manager (MCM) driver's
[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request) function
previously returned NDIS_STATUS_PENDING for.

## Parameters

### `_AH_`

An address family (AF) handle that NDIS passed to the MCM's
[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request) function.

### `_VH_`

A virtual connection (VC) handle that NDIS passed to the MCM's
*ProtocolCoOidRequest* function. A **NULL** value for this parameter indicates that the request is not
VC-specific. This parameter is **NULL** if the caller of the
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest) function specified a
**NULL** VC handle.

### `_PH_`

A party handle that NDIS passed to the MCM's
*ProtocolCoOidRequest* function. A **NULL** value for this parameter indicates that the request is not
party-specific. This parameter is **NULL** if the caller of the
**NdisCoOidRequest** function specified a **NULL** party handle.

### `_R_`

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that the caller
of the
**NdisCoOidRequest** function supplied.

### `_S_`

The final status of the request operation. This parameter can be NDIS_STATUS_SUCCESS,
NDIS_STATUS_REQUEST_ABORTED, or any driver-determined NDIS_STATUS_*XXX* status value
except NDIS_STATUS_PENDING.

## Remarks

A CoNDIS MCM that returns NDIS_STATUS_PENDING from its
[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request) function must
call the
**NdisMCmOidRequestComplete** function after the MCM has finished the OID request operation.

After the MCM calls
**NdisMCmOidRequestComplete**, NDIS calls the
[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete) function of the CoNDIS client that originally called the
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest) function.

For more information about the OIDs defined to use with CONDIS drivers, see
[NDIS OIDs](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

## See also

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest)

[ProtocolCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request)

[ProtocolCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_oid_request_complete)