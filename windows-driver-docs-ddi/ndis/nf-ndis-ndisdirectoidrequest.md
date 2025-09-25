# NdisDirectOidRequest function

## Description

The
**NdisDirectOidRequest** function forwards a direct OID request to the underlying drivers to query the
capabilities or status of an adapter or set the state of an adapter.

## Parameters

### `NdisBindingHandle` [in]

The handle that the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function returns that
identifies the target miniport adapter on the binding.

### `OidRequest` [in]

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that specifies
the operation that is requested with a given OID_*Xxx* code to either query the status of an adapter or to set the state of an adapter.

## Return value

The underlying driver determines which NDIS_STATUS_*XXX* code
**NdisDirectOidRequest** returns, but it is usually one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The request operation completed successfully. |
| **NDIS_STATUS_PENDING** | The request is being handled asynchronously, and NDIS will call the caller's [ProtocolDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_direct_oid_request_complete) function when the request is completed. |
| **NDIS_STATUS_INVALID_OID** | The OID_*Xxx* code that was specified in the **Oid** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)-structured buffer at *OidRequest* was invalid or unsupported by the underlying driver. |
| **NDIS_STATUS_INVALID_LENGTH or NDIS_STATUS_BUFFER_TOO_SHORT** | The value that was specified in the **InformationBufferLength** member of the NDIS_OID_REQUEST-structured buffer at *OidRequest* did not match the requirements for the given OID_*Xxx* code. If the information buffer was too small, the **BytesNeeded** member contains the correct value for **InformationBufferLength** on return from **NdisDirectOidRequest**. |
| **NDIS_STATUS_INVALID_DATA** | The data that was supplied at **InformationBuffer** in the given NDIS_OID_REQUEST structure was invalid for the given OID_*Xxx* code. |
| **NDIS_STATUS_NOT_SUPPORTED or NDIS_STATUS_NOT_RECOGNIZED** | The underlying driver does not support the requested operation. For **NdisDirectOidRequest**, NDIS can also return this status if the calling driver has not registered a [ProtocolDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_direct_oid_request_complete) function. |
| **NDIS_STATUS_RESOURCES** | The request could not be satisfied because of a resource shortage. Typically, this return value indicates that an attempt to allocate memory was unsuccessful, but it does not necessarily indicate that the same request, submitted later, will be failed for the same reason. |
| **NDIS_STATUS_NOT_ACCEPTED** | The underlying driver attempted the requested operation, typically a set on a NIC, but it failed. For example, an attempt to set too many multicast addresses might cause the return of this value. |
| **NDIS_STATUS_CLOSING or NDIS_STATUS_CLOSING_INDICATING** | The underlying driver failed the requested operation because a close operation is in progress. |
| **NDIS_STATUS_RESET_IN_PROGRESS** | The underlying miniport driver cannot satisfy the request at this time because it is currently resetting the affected NIC. The caller's [ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex) function was or will be called with NDIS_STATUS_RESET_START to indicate that a reset is in progress. This return value does not necessarily indicate that the same request, submitted later, will be failed for the same reason. |
| **NDIS_STATUS_FAILURE** | This value typically is a non-specific default, returned when none of the more specific NDIS_STATUS_*Xxx* values caused the underlying driver to fail the request. |

## Remarks

The
**NdisDirectOidRequest** function cannot be used for general OID requests. For general OID requests,
use the
[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function instead.
**NdisDirectOidRequest** can be used only for OIDs that NDIS supports for use with the direct OID
interface. For example, the following OIDs can be used:

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_DELETE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-delete-sa)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_UPDATE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-update-sa)

A protocol driver must allocate sufficient memory to hold the information buffer that is associated
with the specified OID. The driver must also allocate and set up the buffer at the
*OidRequest* parameter before it calls
**NdisDirectOidRequest**. Both buffers must be allocated from nonpaged pool because the underlying
driver runs at raised IRQL while processing the request.

**NdisDirectOidRequest** forwards a request to underlying drivers or handles the request itself. If the
next-lower driver is an NDIS intermediate driver, the intermediate driver can call
**NdisDirectOidRequest** with an OID-specific request of its own before completing the request that the
higher-level driver originally submitted.

A driver that calls
**NdisDirectOidRequest** must register the
[ProtocolDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_direct_oid_request_complete) function.

The direct OID request interface is similar to the general OID request interface. For more information
about issuing general requests, see
[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest).

**Note** Although Direct OID requests are not generally serialized, NDIS itself may still pend a request with NDIS_STATUS_PENDING and queue the request for later completion. For example, NDIS may pend and queue a Direct OID request sent to a selective suspend miniport that is currently in a low power state. Protocols and filters must be prepared to handle an NDIS_STATUS_PENDING code, even if the underlying miniport would complete the request synchronously.

## See also

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_DELETE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-delete-sa)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_UPDATE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-update-sa)

[ProtocolDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_direct_oid_request_complete)

[ProtocolStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_status_ex)