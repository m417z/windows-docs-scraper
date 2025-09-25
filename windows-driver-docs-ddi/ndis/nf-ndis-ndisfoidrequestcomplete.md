# NdisFOidRequestComplete function

## Description

Filter drivers call the
**NdisFOidRequestComplete** function to return the final status of an OID request for which the driver's
[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request) function returned
NDIS_STATUS_PENDING.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `OidRequest` [in]

A pointer to a buffer formatted as an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure. The filter
driver obtained this pointer as an input parameter to its
[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request) function.

### `Status` [in]

The final status of the request operation, either NDIS_STATUS_SUCCESS or any driver-determined
NDIS_STATUS_*XXX* value except NDIS_STATUS_PENDING.

## Remarks

A filter driver that returns NDIS_STATUS_PENDING from its
[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request) function must call
the
**NdisFOidRequestComplete** function after the driver has finished the request operation.

If an overlying driver originated the OID request, NDIS calls the request complete function of the
overlying driver after the filter driver calls
**NdisFOidRequestComplete**.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)