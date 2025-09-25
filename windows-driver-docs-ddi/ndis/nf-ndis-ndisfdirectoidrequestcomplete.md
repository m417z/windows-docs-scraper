# NdisFDirectOidRequestComplete function

## Description

Filter drivers call the
**NdisFDirectOidRequestComplete** function to return the final status of a direct OID request for which
the driver's
[FilterDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request) function
returned NDIS_STATUS_PENDING.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `OidRequest` [in]

A pointer to a buffer that is formatted as an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure. The filter
driver obtained this pointer as an input parameter to its
[FilterDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request) function.

### `Status` [in]

The final status of the request operation: NDIS_STATUS_SUCCESS or any driver-determined
NDIS_STATUS_*Xxx* value except NDIS_STATUS_PENDING.

## Remarks

A filter driver that returns NDIS_STATUS_PENDING from its
[FilterDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request) function
must call the
**NdisFDirectOidRequestComplete** function after the driver has finished the request operation.

If an overlying driver originated the direct OID request, NDIS calls the request complete function
(see
[ProtocolDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_direct_oid_request_complete) and
[FilterDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request_complete)) of the overlying driver that originated the request.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request)

[FilterDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request_complete)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[ProtocolDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_direct_oid_request_complete)