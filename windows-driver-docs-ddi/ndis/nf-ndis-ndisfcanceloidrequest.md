# NdisFCancelOidRequest function

## Description

Filter drivers call the
**NdisFCancelOidRequest** function to cancel a previous request to the underlying drivers.

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
**NdisFCancelOidRequest** to cancel a previously issued request. The request can be originated by the
filter driver or by overlying drivers. The pointer passed at
*OidRequest* must be the same pointer that was passed in the call to the
[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest) function.

The filter driver can call
**NdisFCancelOidRequest** from the
[FilterCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_oid_request) function
to pass on the cancellation to underlying drivers.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_oid_request)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest)