# FILTER_SYNCHRONOUS_OID_REQUEST_COMPLETE function

## Description

NDIS calls a filter driver’s FilterSynchronousOidRequestComplete function after a Synchronous OID request has been completed from an underlying driver.

This function is supported in NDIS 6.81 and later.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module that is the target of this request. The filter driver created and initialized this context area in the [*FilterAttach*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `OidRequest` [in, out]

A pointer to an [**NDIS_OID_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that specifies the operation being completed.

### `Status` [in, out]

A pointer to the resulting status code of the request being completed.

### `CallContext` [in]

A PVOID-sized storage slot for the filter driver to share state between its [*FilterSynchronousOidRequest*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-filter_synchronous_oid_request) and *FilterSynchronousOidRequestComplete* handlers. If the filter driver implements a *FilterSynchronousOidRequest* handler, this parameter contains the context value that the *FilterSynchronousOidRequest* handler returned. Otherwise, if the filter driver does not implement a *FilterSynchronousOidRequest* handler, this value is zero.

## Remarks

*FilterSynchronousOidRequestComplete* is an optional function. If a filter driver does not need to observe or modify Synchronous OID requests completed from the miniport driver, the filter driver should set the entry point for this function to **NULL** when it calls [**NdisFRegisterFilterDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver).

NDIS calls the filter driver’s *FilterSynchronousOidRequestComplete* function to process Synchronous OID requests that are completed by underlying drivers. Filter drivers can read or modify some fields in the [**NDIS_OID_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure as follows:

| Field | Filter access |
| --- | --- |
| Header | Read-only |
| RequestType | Read/write |
| PortNumber | Read/write |
| Timeout | Do not access |
| RequestId | Do not access |
| RequestHandle | Read/write |
| DATA | Read/write |
| NdisReserved | Do not access |
| MiniportReserved | Do not access |
| SourceReserved | Do not access |
| SupportedRevision | Read/write |
| Reserved1, Reserved2 | Do not access |
| SwitchId | Read/write |
| VPortId | Read/write |
| Flags | Read/write |

In addition to modifying the **NDIS_OID_REQUEST** structure, filter drivers can read or modify the status code with which the operation completed. The filter driver can write a new value to the _*Status_ parameter. Filter drivers must not write NDIS_STATUS_PENDING or NDIS_STATUS_ALREADY_COMPLETE to the _*Status_ parameter.

If the filter driver also registers a [*FilterSynchronousOidRequest*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-filter_synchronous_oid_request) handler, NDIS guarantees that the *FilterSynchronousOidRequestComplete* handler will be called if and only if the *FilterSynchronousOidRequest* handler returns NDIS_STATUS_SUCCESS.

Filter drivers are expected to return from their *FilterSynchronousOidRequestComplete* handler quickly, without blocking, waiting, or sleeping. Synchronous OID requests are only used for low-latency operations, and filter drivers should strive to continue or complete them within several milliseconds.

NDIS does not serialize Synchronous OID requests against each other, against other OID requests, or against [*FilterPause*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_pause). It is the responsibility of the filter driver to implement any needed synchronization.

NDIS does serialize Synchronous OID requests against [*FilterDetach*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach): NDIS guarantees that no Synchronous OID requests will be active once *FilterDetach* is invoked.

Filter drivers must not call [**NdisAllocateCloneOidRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatecloneoidrequest) or [**NdisCancelOidRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceloidrequest) on a Synchronous OID request. Filter drivers must not call [**NdisFSynchronousOidRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsynchronousoidrequest) on an OID request that is received through a *FilterSynchronousOidRequestComplete* handler.

## See also

[*FilterSynchronousOidRequest*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-filter_synchronous_oid_request)

[**NdisFSynchronousOidRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsynchronousoidrequest)

[Synchronous OID Request Interface in NDIS 6.80](https://learn.microsoft.com/windows-hardware/drivers/network/synchronous-oid-request-interface-in-ndis-6-80)