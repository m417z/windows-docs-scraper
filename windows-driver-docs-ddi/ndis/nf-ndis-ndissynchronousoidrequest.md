# NdisSynchronousOidRequest function

## Description

Protocol drivers call the **NdisSynchronousOidRequest** function to originate a new Synchronous OID request and issue it to underlying drivers.

## Parameters

### `NdisBindingHandle` [in]

The handle returned by the [NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function that identifies the target miniport adapter on the binding.

### `OidRequest` [in]

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that specifies
the operation that is requested with a given OID_*Xxx* code. The structure can specify an OID query, set, or method request.

## Return value

The underlying driver determines which NDIS_STATUS_*XXX* code
**NdisSynchronousOidRequest** returns, but it is usually one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The request operation completed successfully. |
| **NDIS_STATUS_INVALID_OID** | The OID_*Xxx* code that was specified in the **Oid** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)-structured buffer at *OidRequest* was invalid or unsupported by the underlying driver. |
| **NDIS_STATUS_INVALID_LENGTH or NDIS_STATUS_BUFFER_TOO_SHORT** | The value that was specified in the **InformationBufferLength** member of the NDIS_OID_REQUEST-structured buffer at *OidRequest* did not match the requirements for the given OID_*Xxx* code. If the information buffer was too small, the **BytesNeeded** member contains the correct value for **InformationBufferLength** on return from **NdisSynchronousOidRequest**. |
| **NDIS_STATUS_INVALID_DATA** | The data that was supplied at **InformationBuffer** in the given NDIS_OID_REQUEST structure was invalid for the given OID_*Xxx* code. |
| **NDIS_STATUS_NOT_SUPPORTED or NDIS_STATUS_NOT_RECOGNIZED** | The underlying driver does not support the requested operation. |
| **NDIS_STATUS_RESOURCES** | The request could not be satisfied because of a resource shortage. Typically, this return value indicates that an attempt to allocate memory was unsuccessful, but it does not necessarily indicate that the same request, submitted later, will be failed for the same reason. |
| **NDIS_STATUS_NOT_ACCEPTED** | The underlying driver attempted the requested operation, typically a set on a NIC, but it failed. For example, an attempt to set too many multicast addresses might cause the return of this value. |
| **NDIS_STATUS_CLOSING or NDIS_STATUS_CLOSING_INDICATING** | The underlying driver failed the requested operation because a close operation is in progress. |
| **NDIS_STATUS_RESET_IN_PROGRESS** | The underlying miniport driver cannot satisfy the request at this time because it is currently resetting the affected NIC. The caller's [ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex) function was or will be called with NDIS_STATUS_RESET_START to indicate that a reset is in progress. This return value does not necessarily indicate that the same request, submitted later, will be failed for the same reason. |
| **NDIS_STATUS_FAILURE** | This value typically is a non-specific default, returned when none of the more specific NDIS_STATUS_*Xxx* values caused the underlying driver to fail the request. |

## Remarks

The **NdisSynchronousOidRequest** function cannot be used for general OID requests. For general OID requests, use the [NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function instead. **NdisSynchronousOidRequest** can be used only for OIDs that NDIS supports for use with the Synchronous OID interface. Most protocol drivers do not need to call **NdisSynchronousOidRequest**

Protocol drivers must not close the adapter binding until any Synchronous OID requests originated by the protocol driver are completed.

Protocol drivers are not required to implement [ProtocolOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_oid_request_complete) or [ProtocolDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_direct_oid_request_complete) in order to call **NdisSynchronousOidRequest**. As its name suggests, a Synchronous OID request always completes synchronously, so there is no asynchronous callback.

## See also

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_direct_oid_request_complete)

[ProtocolOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_oid_request_complete)

[ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex)