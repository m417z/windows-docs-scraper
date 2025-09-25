# NdisFDirectOidRequest function

## Description

Filter drivers call the
**NdisFDirectOidRequest** function to forward a direct OID request to underlying drivers or to originate
such a request.

## Parameters

### `NdisFilterHandle` [in]

An NDIS handle that identifies a filter module. NDIS passed the handle to the filter driver in a
call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `OidRequest` [in]

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that specifies
the operation that is requested with a given OID_*Xxx* code. The structure can specify an OID query, set, or method request.

## Return value

For a list of possible return values, see the
[NdisDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdirectoidrequest) function.

## Remarks

The
**NdisFDirectOidRequest** function cannot be used for general OID requests. For general OID requests,
use the
[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest) function instead.
**NdisFDirectOidRequest** can be used only for OIDs that NDIS supports for use with the direct OID
interface. For example, the following OIDs can be used:

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_DELETE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-delete-sa)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_UPDATE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-update-sa)

Filter drivers can originate direct OID requests to underlying drivers by calling
**NdisFDirectOidRequest**.

Filter drivers can also filter direct OID requests that are originated by overlying drivers. NDIS
calls the
[FilterDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request) function
to process each such request.

If
**NdisFDirectOidRequest** returns **NDIS_STATUS_PENDING**, NDIS calls the
[FilterDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request_complete) function after the underlying drivers complete the OID request. A
driver that calls
**NdisFDirectOidRequest** must register the
*FilterDirectOidRequestComplete* function.

A driver can call
**NdisFDirectOidRequest** when it is in the
*Restarting*,
*Running*,
*Pausing*, or
*Paused* state.

The direct OID request interface is similar to the general OID request interface. For more information
about issuing general requests, see
[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request)

[FilterDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request_complete)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdirectoidrequest)

[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_DELETE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-delete-sa)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_UPDATE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-update-sa)