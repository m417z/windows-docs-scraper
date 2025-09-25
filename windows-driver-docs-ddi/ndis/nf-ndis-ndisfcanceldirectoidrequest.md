# NdisFCancelDirectOidRequest function

## Description

Filter drivers call the
**NdisFCancelDirectOidRequest** function to cancel a previous direct OID request to the underlying
drivers.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `RequestId` [in]

A cancellation identifier for the request. This identifier specifies the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structures that are being
canceled.

## Remarks

Filter drivers call
**NdisFCancelDirectOidRequest** to cancel a previously issued direct OID request. The request can be
originated by the filter driver or by overlying drivers. The pointer that is passed at the
*OidRequest* parameter must be the same pointer that was passed in the call to the
[NdisFDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequest) function.

The filter driver can call
**NdisFCancelDirectOidRequest** from the
[FilterCancelDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_direct_oid_request) function to pass on the cancellation to underlying drivers.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterCancelDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_direct_oid_request)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisFDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdirectoidrequest)