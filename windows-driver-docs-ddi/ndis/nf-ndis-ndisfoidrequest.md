# NdisFOidRequest function

## Description

Filter drivers call the
**NdisFOidRequest** function to forward an OID request to underlying drivers or to originate such a
request.

## Parameters

### `NdisFilterHandle` [in]

An NDIS handle that identifies a filter module. NDIS passed the handle to the filter driver in a
call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `OidRequest` [in]

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that specifies
the operation requested with a given OID_*XXX* code. The structure can specify a query, set, or method request. For more information about
OIDs, see
[NDIS OIDs](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

## Return value

See the
[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function.

## Remarks

Filter drivers can originate OID requests to underlying drivers by calling
**NdisFOidRequest**.

Filter drivers can also filter OID requests that are originated by overlying drivers. NDIS calls the
[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request) function to process
each such request.

If
**NdisFOidRequest** returns **NDIS_STATUS_PENDING**, NDIS calls the
[FilterOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request_complete) function after the underlying drivers complete the OID request.

If
**NdisFOidRequest** returns **NDIS_STATUS_SUCCESS**, it returns the results of a query request in the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure at the
*OidRequest* parameter.

**NdisFOidRequest** can return **NDIS_STATUS_INVALID_PARAMETER** if the filter driver passes invalid values
for the
**Type** and
**Size** fields in the
**Header** field of the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure.

A driver can call
**NdisFOidRequest** when it is in the
*Restarting*,
*Running*,
*Pausing*, or
*Paused* state.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request)

[FilterOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request_complete)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest)