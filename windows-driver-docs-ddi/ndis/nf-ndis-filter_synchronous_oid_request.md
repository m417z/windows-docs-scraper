# FILTER_SYNCHRONOUS_OID_REQUEST function

## Description

NDIS calls a filter driver's *FilterSynchronousOidRequest* function to preview a Synchronous OID request before the request is given to the underlying miniport driver.

This function is supported in NDIS 6.81 and later.

## Parameters

### `FilterModuleContext`

A handle to the context area for the filter module that is the target of this request. The filter driver created and initialized this context area in the [**FilterAttach**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `OidRequest` [in, out]

A pointer to an [**NDIS_OID_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that specifies the operation requested.

### `CallContext` [out]

A PVOID-sized storage slot for the filter driver to share state between its *FilterSynchronousOidRequest* and [*FilterSynchronousOidRequestComplete*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-filter_synchronous_oid_request_complete) handlers. NDIS guarantees this initially points to a zero value. See the Remarks section for more information.

## Return value

This function returns one of the following appropriate NDIS_STATUS codes:

| Return code | Description |
| --- | --- |
| NDIS_STATUS_SUCCESS | Allow the OID request to continue propagating down to the miniport driver. Filter drivers must return this status code for any unrecognized type of OID. |
| NDIS_STATUS_ALREADY_COMPLETE | Stop propagating the OID request down, and instead return it to the caller with the status NDIS_STATUS_SUCCESS. |
|

* NDIS_STATUS_BUFFER_TOO_SHORT
* NDIS_STATUS_INVALID_LENGTH
* NDIS_STATUS_INVALID_DATA

| Same as [*FilterDirectOidRequest*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_direct_oid_request). |
| NDIS_STATUS_RESOURCES | Same as *FilterDirectOidRequest*, but with a caution that Synchronous OID requests must be completed quickly, and so filter drivers should typically avoid allocating resources. |
| NDIS_STATUS_NOT_SUPPORTED | Filter drivers must not return this code simply because the OID is unrecognized. Filter drivers may only return this if the filter recognizes the operation but cannot perform it for some reason. |

## Remarks

*FilterSynchronousOidRequest* is an optional function. If a filter driver does not need to observe or modify Synchronous OID requests sent to the miniport driver, the filter driver should set the entry point for this function to **NULL** when it calls [**NdisFRegisterFilterDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver).

NDIS calls the filter driver’s *FilterSynchronousOidRequest* function to process Synchronous OID requests that are originated by overlying drivers. Filter drivers can read or modify some fields in the [**NDIS_OID_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure as follows:

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

In addition to modifying the **NDIS_OID_REQUEST** structure, filter drivers can control the request using the return code from *FilterSynchronousOidRequest*:

- NDIS_STATUS_SUCCESS: the OID continues to propagate down to the miniport driver.
- NDIS_STATUS_ALREADY_COMPLETE: the OID is immediately completed back to the overlying drivers, without first propagating down to the miniport driver. The OID request is completed to the overlying driver with NDIS_STATUS_SUCCESS.
- Any other status code: the OID is immediately completed back to the overlying drivers, without first propagating down to the miniport driver. The OID request is completed to the overlying driver with the status code returned by the filter driver.

If the filter driver also registers a [*FilterSynchronousOidRequestComplete*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-filter_synchronous_oid_request_complete) handler, NDIS guarantees that the *FilterSynchronousOidRequestComplete* handler will be called if and only if the *FilterSynchronousOidRequest* handler returns NDIS_STATUS_SUCCESS.

The *FilterSynchronousOidRequest* handler can write any PVOID-sized value to _*CallContext_, and the same value will be returned to the filter driver’s *FilterSynchronousOidRequestComplete* handler when the OID request is completed. Filter driver can use this to carry state across the two handlers. Since the *FilterSynchronousOidRequestComplete* handler is only invoked if the *FilterSynchronousOidRequest* handler returns NDIS_STATUS_SUCCESS, there’s no reason to write a value to _*CallContext_ when returning any other code. Likewise, there’s no reason to write a value to _*CallContext_ if the filter driver does not provide a *FilterSynchronousOidRequestComplete* handler.

Filter drivers must not return NDIS_STATUS_PENDING from a *FilterSynchronousOidRequest* handler. Synchronous OID requests cannot be pended or cancelled.

Filter drivers are expected to return from their *FilterSynchronousOidRequest* handler quickly, without blocking, waiting, or sleeping. Synchronous OID requests are only used for low-latency operations, and filter drivers should strive to continue or complete them within several milliseconds.
NDIS does not serialize Synchronous OID requests against each other, against other OID requests, or against [*FilterPause*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_pause). It is the responsibility of the filter driver to implement any needed synchronization.

NDIS does serialize Synchronous OID requests against [*FilterDetach*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach): NDIS guarantees that no Synchronous OID requests will be active once *FilterDetach* is invoked.

Filter drivers must not call [**NdisAllocateCloneOidRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatecloneoidrequest) or [**NdisCancelOidRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceloidrequest) on a Synchronous OID request. Filter drivers must not call [**NdisFSynchronousOidRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsynchronousoidrequest) on an OID request that is received through a *FilterSynchronousOidRequest* handler.

If a filter driver raises the IRQL in its *FilterSynchronousOidRequest* handler, it must restore the IRQL to its initial level before returning from its *FilterSynchronousOidRequest* handler.

## See also

[*FilterSynchronousOidRequestComplete*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-filter_synchronous_oid_request_complete)

[**NdisFSynchronousOidRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsynchronousoidrequest)

[Synchronous OID Request Interface in NDIS 6.80](https://learn.microsoft.com/windows-hardware/drivers/network/synchronous-oid-request-interface-in-ndis-6-80)