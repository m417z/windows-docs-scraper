# NdisFSynchronousOidRequest function

## Description

Filter drivers call the NdisFSynchronousOidRequest function to originate a new Synchronous OID request and issue it to underlying drivers.

This function is supported in NDIS 6.81 and later.

## Parameters

### `NdisFilterModuleHandle` [in]

An NDIS handle that identifies a filter module. NDIS passed the handle to the filter driver in a call to the [*FilterAttach*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `OidRequest` [in]

A pointer to an [**NDIS_OID_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that specifies the operation that is requested with a given *OID_Xxx* code. The structure can specify an OID query, set, or method request.

## Return value

This function returns the same values as [**NdisDirectOidRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdirectoidrequest) **except** that NDIS_STATUS_PENDING is never returned from this function.

## Remarks

The **NdisFSynchronousOidRequest** function cannot be used for general OID requests. For general OID requests, use the [**NdisFOidRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest) function instead. **NdisFSynchronousOidRequest** can be used only for OIDs that NDIS supports for use with the Synchronous OID interface. Most filter drivers do not need to call **NdisFSynchronousOidRequest**.

Filter drivers must not complete [*FilterDetach*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach) until any Synchronous OID requests originated by the filter driver are completed.

Filter drivers are not required to implement [*FilterOidRequestComplete*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request_complete), [*FilterDirectOidRequestComplete*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request_complete), [*FilterSynchronousOidRequest*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-filter_synchronous_oid_request), or [*FilterSynchronousOidRequestComplete*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-filter_synchronous_oid_request_complete) in order to call **NdisFSynchronousOidRequest**. As its name suggests, a Synchronous OID request always completes synchronously, so there is no asynchronous callback.

## See also

[*FilterSynchronousOidRequest*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-filter_synchronous_oid_request)

[*FilterSynchronousOidRequestComplete*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-filter_synchronous_oid_request_complete)

[Synchronous OID Request Interface in NDIS 6.80](https://learn.microsoft.com/windows-hardware/drivers/network/synchronous-oid-request-interface-in-ndis-6-80)